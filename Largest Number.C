# Write your MySQL query statement below
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person P LEFT JOIN Address A
on P.personId = A.personIdint cmpfunc (const void * a, const void * b)
{
    int a_num = *(int *)a;
    int b_num = *(int *)b;
    char ab[21], ba[21];
    sprintf(ab, "%d%d", a_num, b_num);
    sprintf(ba, "%d%d", b_num, a_num);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), cmpfunc);

    char *answer = malloc(sizeof(char) * ((numsSize * 10) + 1));
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        char tmp[11];
        sprintf(tmp, "%d", nums[i]);
        for (int j = 0; tmp[j] != '\0'; j++) {
            answer[k] = tmp[j];
            k++;
        }
    }

    if (answer[0] == '0')
        answer[1] = '\0';
    else
        answer[k] = '\0';

    return answer;
}
