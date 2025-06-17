#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y, int size, int *house_cnt, int(*apt)[25]){
    (*house_cnt)++;
    apt[x][y]=0;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=size || ny>=size) continue;

        if(apt[nx][ny]==1){
            dfs(nx, ny, size, house_cnt, apt);
        }
    }
}

int compare(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int main(){
    int answer[25]={0};
    int num =0, cnt =0; 
    (void)scanf("%d", &num);

    int apt[25][25]={0};
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            (void)scanf("%1d",&apt[i][j]);
        }
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(apt[i][j]!=1) continue;

            int house_cnt = 0;
            dfs(i,j,num,&house_cnt,apt);
            answer[cnt++] = house_cnt;
        }
    }
    
    qsort(answer, cnt, sizeof(int), compare);
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++){
        printf("%d\n", answer[i]);
    }


}
