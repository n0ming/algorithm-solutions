
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N (100+2)
#define MAX_INT 2147483647
#define MAX_QUEUE MAX_N * MAX_N * 5

typedef struct _node {
    int r;
    int c;
}node;
int N, C, R;  // 사이즈, 열, 행
int map[MAX_N][MAX_N];  // 입력, 방문표시(3, 4, 5, ...)
int cost[MAX_N][MAX_N];

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

node Queue[MAX_QUEUE];
int front, rear;

void enqueue(int r, int c) {
    if (rear >= MAX_QUEUE) {
        printf("Queue overflow!\n");
    }
    Queue[rear++] = (node){ r, c };
}

node dequeue(void) {
    return Queue[front++];
}

int calc(int a, int b){
    if(a>b) return a-b;
    else if(a==b) return 0;
    else return (b-a)*(b-a);
}

void BFS() {
    node curr = { 0 };
    int nr, nc = 0;

    front = rear = 0;

    for(int i=0; i<N;i++){
        if(cost[i][0] ==MAX_INT){
            cost[i][0] = map[i][0]*map[i][0];
            enqueue(i, 0);
        }
        if(cost[i][N - 1] ==MAX_INT){
            cost[i][N - 1] = map[i][N-1]*map[i][N-1];
            enqueue(i, N - 1);
        }
        if(cost[0][i] ==MAX_INT){
            cost[0][i] = map[0][i]*map[0][i];
            enqueue(0, i);
        }
        if(cost[N - 1][i] ==MAX_INT){
            cost[N - 1][i] = map[N-1][i]*map[N-1][i];
            enqueue(N - 1, i);
        }
    }

    while (front != rear) {
        curr = dequeue();
 
        for (int i = 0; i < 4; ++i) {
            nr = curr.r + dr[i];
            nc = curr.c + dc[i];


            if(nr<0||nr>=N||nc<0||nc>=N) continue;

            int c = calc(map[curr.r][curr.c],map[nr][nc]);

            if(cost[nr][nc]>cost[curr.r][curr.c]+c){
                cost[nr][nc] = cost[curr.r][curr.c]+c;
                enqueue(nr, nc);
            }
        }
    }
}

static void inputData(void) {
    (void)scanf("%d", &N);
    (void)scanf("%d %d", &C, &R);
    C--; R--;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            (void)scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j]=MAX_INT;
        }
    }

    for(int i=0; i<N;i++){
        if(cost[i][0] ==MAX_INT){
            cost[i][0] = map[i][0]*map[i][0];
            enqueue(i, 0);
        }
        if(cost[i][N - 1] ==MAX_INT){
            cost[i][N - 1] = map[i][N-1]*map[i][N-1];
            enqueue(i, N - 1);
        }
        if(cost[0][i] ==MAX_INT){
            cost[0][i] = map[0][i]*map[0][i];
            enqueue(0, i);
        }
        if(cost[N - 1][i] ==MAX_INT){
            cost[N - 1][i] = map[N-1][i]*map[N-1][i];
            enqueue(N - 1, i);
        }
    }
}

static void printMap(void) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(void) {
    inputData();

    BFS();
    printf("%d\n", cost[C][R]);

    //printMap();
    return 0;
}
