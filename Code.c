#include <stdio.h>
#include <stdlib.h>


void FCFS(int arr[], int sizeArr)
{
    int totalMov = 0;
    int i;

    for(i = 0; i < sizeArr - 1; i++)
        totalMov += abs(arr[i]-arr[i+1]);

    printf("FCFS\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");
}

void SSTF(int arr[], int sizeArr)
{
    int totalMov = 0, distances[sizeArr];
    int i, j, aux;

    for(i = 0; i<sizeArr; i++)
        distances[i] = abs(arr[0] - arr[i]);

    for(i = 0; i < sizeArr; i++)
        for(j = i+1; j < sizeArr; j++)
            if(distances[i]>distances[j])
            {
                aux = distances[i];
                distances[i] = distances[j];
                distances[j] = aux;

                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }

    for(i = 0; i<sizeArr - 1; i++)
        totalMov += abs(arr[i] - arr[i+1]);

    printf("SSTF\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");

}

void SCAN(int arr[], int sizeArr)
{
    int totalMov = 0;
    int header, headerPos;
    int i, j, aux;

    header = arr[0];

    for(i=0; i<sizeArr;i++)
        for(j=i; j<sizeArr; j++)
            if(arr[i]>arr[j])
            {
                aux =arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }

    for(i=0; i<sizeArr;i++)
        if(arr[i] == header)
        {
            headerPos = i;
            break;
        }


    if(abs(header-0) <= abs(header-199))
    {
        for(i = headerPos; i > 0; i--)
            totalMov += arr[i] - arr[i-1];

        int val = arr[0];
        for(i = headerPos+1; i < sizeArr; i++)
        {
            totalMov += arr[i] - val;
            val = arr[i];
        }

    }

    else
    {
        for(i = headerPos; i < sizeArr - 1; i++)
        totalMov += arr[i+1] - arr[i];

        int var = 199;
        for(i = headerPos-1; i >= 0; i--)
        {

            totalMov += var - arr[i];
            var = arr[i];
        }
    }



    printf("SCAN\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");


}

void CSCAN(int arr[], int sizeArr)
{
    int totalMov = 0;
    int header, headerPos;
    int i, j, aux;

    header = arr[0];

    for(i=0; i<sizeArr;i++)
        for(j=i; j<sizeArr; j++)
            if(arr[i]>arr[j])
            {
                aux =arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }

    for(i=0; i<sizeArr;i++)
        if(arr[i] == header)
        {
            headerPos = i;
            break;
        }

    for(i = headerPos; i < sizeArr - 1; i++)
        totalMov += arr[i+1] - arr[i];

    totalMov += 199;
    int val = 0;
    for(i = 0; i < headerPos; i++)
    {
        totalMov += abs(val - arr[i]);
        val = arr[i];
    }

    printf("C-SCAN\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");

}

void LOOK(int arr[], int sizeArr)
{
    int totalMov = 0;
    int header, headerPos;
    int i, j, aux;

    header = arr[0];

    for(i=0; i<sizeArr; i++)
        for(j=i; j<sizeArr; j++)
            if(arr[i]>arr[j])
            {
                aux =arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }

    for(i=0; i<sizeArr;i++)
        if(arr[i] == header)
        {
            headerPos = i;
            break;
        }

    for(i = headerPos; i < sizeArr - 1; i++)
        totalMov += arr[i+1] - arr[i];

    int val = arr[sizeArr - 1];
    for(i = headerPos - 1; i >=0; i--)
    {
        totalMov += val - arr[i];
        val = arr[i];
    }

    printf("LOOK\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");

}

void CLOOK(int arr[], int sizeArr)
{
    int totalMov = 0;
    int header, headerPos;
    int i, j, aux;

    header = arr[0];
    for(i=0; i<sizeArr; i++)
        for(j=i; j<sizeArr; j++)
            if(arr[i]>arr[j])
            {
                aux =arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }

    for(i=0; i<sizeArr;i++)
        if(arr[i] == header)
        {
            headerPos = i;
            break;
        }

    for(i = headerPos; i < sizeArr - 1; i++)
        totalMov += arr[i+1] - arr[i];

    int val = arr[sizeArr - 1];
    for(i = 0; i < headerPos; i++)
    {
        totalMov += abs(val - arr[i]);
        val = arr[i];
    }

    printf("C-LOOK\n");
    printf("Total head movement: %d\n", totalMov);
    printf("Average seek time: %f\n", totalMov/(float)sizeArr);
    printf("\n");

}

int main(int arr[], int sizeArr)
{
    int alg;
    int ok = 1;
    printf("<---|Welcome to Disk Scheduling Algorithms|--->\n");
    printf("Witch algorithm do you want to use?\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Seek Time First (SSTF)\n");
    printf("3. Elevator Algorithm (SCAN)\n");
    printf("4. Circular Elevator Algorithm (C-SCAN)\n");
    printf("5. LOOK Algorithm\n");
    printf("6. Circular LOOK algorithm (C-LOOK)\n");
    printf("7. Multiple threads (All algorithms at once)\n");
    printf("8. Multiple queues\n");
    printf("9. Close the program\n");

    int numbElements, numbElements1, numbElements2;
    ///The header is the first element of the array
    int elements[] = {100, 279, 66, 265, 165, 53, 243, 63, 41, 167};
    int elements1[] = {12, 43, 123, 75, 272, 125, 54, 23, 46};
    int elements2[] = {56, 17, 234, 165, 123, 66, 11, 8, 123};
    numbElements = sizeof elements / sizeof elements[0];
    numbElements1 = sizeof elements1 / sizeof elements1[0];
    numbElements2 = sizeof elements2 / sizeof elements2[0];


    while(ok == 1)
    {
        printf("Choose a number to try an algorithm: ");
        scanf("%d", &alg);
        printf("\n");
        if(alg == 1)
        {
            FCFS(elements, numbElements);
        }

        else if(alg == 2)
        {
            SSTF(elements, numbElements);
        }

        else if(alg == 3)
        {
            SCAN(elements, numbElements);
        }

        else if(alg == 4)
        {
            CSCAN(elements, numbElements);
        }

        else if(alg == 5)
        {
            LOOK(elements, numbElements);
        }

        else if(alg == 6)
        {
            CLOOK(elements, numbElements);
        }
        else if(alg == 7)
        {
            FCFS(elements, numbElements);
            SSTF(elements, numbElements);
            SCAN(elements, numbElements);
            CSCAN(elements, numbElements);
            LOOK(elements, numbElements);
            CLOOK(elements, numbElements);
        }

        else if(alg == 8)
        {
            int algm, num;
            printf("Choose which algorithm and how many queue you want (max 3):");
            scanf("%d", &algm);
            scanf("%d", &num);
            if(algm == 1)
            {
                if(num == 1)
                    FCFS(elements, numbElements);
                else if(num == 2)
                {
                    FCFS(elements, numbElements);
                    FCFS(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    FCFS(elements, numbElements);
                    FCFS(elements1, numbElements1);
                    FCFS(elements2, numbElements2);
                }

            }

            else if(algm == 2)
            {
                if(num == 1)
                    SSTF(elements, numbElements);
                else if(num == 2)
                {
                    SSTF(elements, numbElements);
                    SSTF(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    SSTF(elements, numbElements);
                    SSTF(elements1, numbElements1);
                    SSTF(elements2, numbElements2);
                }
            }

            else if(algm == 3)
            {
                if(num == 1)
                    SCAN(elements, numbElements);
                else if(num == 2)
                {
                    SCAN(elements, numbElements);
                    SCAN(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    SCAN(elements, numbElements);
                    SCAN(elements1, numbElements1);
                    SCAN(elements2, numbElements2);
                }
            }

            else if(algm == 4)
            {
                if(num == 1)
                    CSCAN(elements, numbElements);
                else if(num == 2)
                {
                    CSCAN(elements, numbElements);
                    CSCAN(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    CSCAN(elements, numbElements);
                    CSCAN(elements1, numbElements1);
                    CSCAN(elements2, numbElements2);
                }
            }

            else if(algm == 5)
            {
                if(num == 1)
                    LOOK(elements, numbElements);
                else if(num == 2)
                {
                    LOOK(elements, numbElements);
                    LOOK(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    LOOK(elements, numbElements);
                    LOOK(elements1, numbElements1);
                    LOOK(elements2, numbElements2);
                }
            }

            else if(algm == 6)
            {
                if(num == 1)
                    CLOOK(elements, numbElements);
                else if(num == 2)
                {
                    CLOOK(elements, numbElements);
                    CLOOK(elements1, numbElements1);
                }
                else if(num == 3)
                {
                    CLOOK(elements, numbElements);
                    CLOOK(elements1, numbElements1);
                    CLOOK(elements2, numbElements2);
                }
            }

        }

        else if(alg == 9)
            ok = 0;

        else
            printf("You typed a wrong number. Try again\n");

    }

    return 0;
}
