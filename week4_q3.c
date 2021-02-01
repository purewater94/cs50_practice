//  2021.02.01

#include <stdio.h>

int find_min(int input[]);
int find_mintime(int input[], int min);
void output_case(int input[], int min);

// Main
int main(void)
{
    int input[15] = {14, 11, 1, 12, 2, 13, 3, 14, 4, 5, 6, 7, 8, 9, 10};
    int min;
    int min_time;

    min = find_min(input);
    min_time = find_mintime(input, min);
    output_case(input, min);
}

// Functions
int find_min(int input[])
{
    int min = input[1];
    for (int i = 1; i < input[0]; i++)
    {
        if ( input[i+1] < min)
        {
            min = input[i+1];
        }
       printf("i = %d, min = %d\n", i, min);
    }
    printf("min = %d\n\n",min);
    return min;
}

int find_mintime(int input[], int min)
{
    int min_time = 0;
    // sum
    for (int i = 1; i < input[0]+1; i++)
    {
        min_time += input[i];
        //printf("i = %d, min_time = %d\n", i,  min_time);  //debugging
    }
    // min_time = sum + n*min - min
    min_time = min_time + (input[0] -2) * min;
    printf("\nmin_time = %d\n\n", min_time);
    return min_time;
}

void output_case(int input[], int min)
{
    int time_calculated = 0;
    for(int i = 1; i < input[0] +1; i++)
    {
        if (min == input[i])
        {
            continue;
        }
        else
        {
            printf("Cross the bridge : %d, %d\n", input[i], min);
            printf("Come back        : %d\n\n", min);
            time_calculated = time_calculated + input[i] + min;
            //printf("i = %d, time_calculated = %d\n\n\n", i, time_calculated); //debugging
        }
    }
    //printf("Cross the bridge : %d, %d\n\n", input[input[0]], min);

    //debugging
    printf("time_calculated = %d\n", time_calculated);
}

/*  더 Develop하고 싶은 것
        1. 배열을 외부에서 받아오기 & 배열 원소의 갯수(== 첫 번째 원소)를 동적으로 읽기.
        2. 다른 방법으로 풀기.
        3. 값의 크기 차이가 적고, 원소 갯수가 매우 많은 케이스에 최적화된 풀이 찾기.
        4. 다른 조건은 같고, 중복된 값이 많은 경우로 문제가 바뀌었을 때, 최적 풀이를 찾기.
*/

/* 부스트코스 4주차 미션 3번. https://www.boostcourse.org/study-cs50-2nd/lecture/317820/

    1. 미션 제목
        최단 시간에 다리건너기

    2. 지시문
    N명의 사람들로 구성된 한 그룹이 밤중에 다리를 건너려고 합니다.
    한 번에 최대 두 명 까지만 다리를 건널 수 있으며 다리 위를 지나가는 사람들은 반드시 손전등을 가지고 가야 합니다.
    n명의 사람들한테는 손전등이 한 개밖에 없기 때문에
    남아 있는 사람들이 다리를 건너려면 어떤 식으로든 손전등을 가지고
    다시 다리를 건너지 않은 사람들이 있는 곳으로 돌아가는 일을 해야합니다.
    사람마다 다리를 건너는 속도가 다른데, 그룹의 속도는 가장 느린 구성원의 속도에 따라 결정됩니다.
    가장 짧은 시간 안에 n명이 모두 다리를 건널 수 있는 방법과 그 시간을 출력하는 프로그램을 작성해봅시다.

    입력으로 첫 줄에는 n이 입력되며
    그 다음 줄부터 n개의 줄에 걸쳐서 각 사람들이 다리를 건너는 시간이 입력됩니다.
    입력은 100명을 넘기지 않습니다.


    출력은 맨 첫 줄에는 n명의 사람들이 모두 다리를 건너는데 걸리는 총 시간을 출력하고,
    그 다음줄부터는 그 과정을 출력하면 됩니다.
    이 때 각 줄에는 정수가 하나 또는 두 개가 들어가는데,
    이 정수는 어떤 사람들이 다리를 건너가는지를 나타냅니다.
    각 사람은 그 사람이 건너가는데 걸리는 시간으로 표시하며, 건너가고 오는 순서대로 출력해야 합니다.
    최소 시간을 달성하는 방법이 여러가지가 있을 경우 그 중 아무 방법이나 출력해도 괜찮습니다.
    완전한 프로그램을 작성하기 어려운 경우에는 pseudo code를 작성해도 좋습니다.
    다만 이 경우에는 최대한 자세히 적어야 합니다.
    숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에서 따로 선언하는 것으로 가정합니다.
*/

/*  Pseudo Code(x)
    0. given
        N people,
        1 or 2 people can cross at each time,
        1 light (someone must carry the light),
        Each person has a different speed,
        One group's speed is depend on the slowest person of the group.
    1. output
        the way to cross everyone spending the least amount of time.
        the amount of time

    2. input data
        n
        time to across the bridge for person1
        time to across the bridge for person2
        ...
        (the max.number of input is 100)

    3. output
        total time spent
        1 or 2 integers (people acrossing the bridge)

*/

