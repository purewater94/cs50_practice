#include <stdio.h>

void find_max_fall(int input[]);

int main(void){
    int input[11] = { 9, 8, 7, 4, 2, 0, 0, 6, 0, 7, 0};
    //만약 방의 가로길이, 세로길이를 초과하는 입력을 받으면 에러를 출력해야 하지 않을까?
    find_max_fall(input);
}

void find_max_fall(int input[]){
    int max_fall = 0;   // 최대 낙하거리
    int fall = 0;    //아래 조건을 만족하는 것을 세는 수

    for(int i = 2; i < input[0]+1; i++){
        fall = input[0] - i + 1;  // 낙하거리를 다음으로 초기화 : (방의 가로길이 - 자신의 위치) : input[0] - (i-1)
        printf("------------fall(initialized) = %d\n", fall);
        for(int j = i+1; j < input[0]+1; j++){
            printf("i = %d, j = %d\n", i, j);
            if(input[i] <= input[j]){   //자신보다 오른쪽에 있는 상자들 중 더 높이(혹은 같은 높이)로 쌓인 것이 있으면
                fall -= 1;              // 낙하거리를 1 감소시키기
                printf("fall(in for) = %d\n", fall);
            }
        }
        if (fall > max_fall){       // 최대 낙하거리를 갱신하기
            max_fall = fall;        
        }
    }
    printf("\nmax_fall = %d\n----------",max_fall);
}
/*
1. 가장 큰 낙하거리를 구한다.
    (방 가로길이 - 자기위치) - 자기보다 같거나 큰 원소의 갯수
2. 1의 결과물 중 최댓값을 찾는다.
*/

/*
상자들이 쌓여있는 방이 있습니다. 
방이 오른쪽으로 90도 회전하여 상자들이 중력의 영향을 받아 낙하한다고 할 때, 
낙하거리가 가장 큰 상자를 구하여 그 낙하거리를 출력하는 프로그램을 작성해 봅시다. 

중력은 회전이 완료된 이후에 적용되며, 
상자들은 모두 한쪽 벽면에 붙여진 상태로 쌓여 2차원의 형태를 이루며 벽에서 떨어져서 쌓인 상자는 없습니다. 
입력으로는 첫 줄에 각 방의 가로 길이 N(2 ≤ N ≤ 100)과 방의 세로 길이 M(2 ≤ N ≤ 100)이 주어지며, 
다음 줄에는 N개의 상자들이 쌓여있는 높이 H(0 ≤ H ≤ M)가 주어집니다. 
가장 직관적인 방법은 MxN내의 모든 box에 대해서 낙하거리를 계산한 뒤 
정렬 알고리즘을 사용하여 최댓값을 찾으면 되는 문제라고 생각할 수 있습니다. 

이 방법은 시간 복잡도(Big O)가 얼마나 될 지 먼저 생각해봅시다. 
그리고, 이보다 더 효율적인 방법으로 프로그램을 작성해봅시다. 
완전한 프로그램을 작성하는 것이 힘들 경우에는 pseudo code로 작성해도 좋습니다. 
다만 이 경우에는 최대한 자세히 적어야 합니다. 

숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에서 따로 선언하는 것으로 가정합니다.
*/