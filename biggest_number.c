#include <stdio.h>
#include <stdlib.h>

int stringLength(const char *str){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

void appendStringDyn(char *destination, const char *source){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sortReverse(char arr[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){     
        for(j = 0; j < n-i-1; j++){
            if(arr[j] < arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void bubble_sort(char arr[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){     
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


int main(){
    char temp[100]; //temp array to get a size of the dynamic array
    printf("Enter a number: ");
    scanf("%99s",temp);

    int size = stringLength(temp);//size of the dynamic array

    char *Hello = malloc((size + 1) * sizeof(char));//create a array for size of the temp array
    int *Helloint = malloc((size + 1) * sizeof(int));

    //check if memory allocation failed
     if (Hello == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    appendStringDyn(Hello,temp);
    
    int len = stringLength(Hello);

    //converting char array to int array   
    int i;
    for(i = 0; Hello[i] != '\0'; i++){
        Helloint[i] = Hello[i] - '0';
    }
    
    //finding pivot
    int pivot = -1;
    int j;
    for(j = 0; j < len - 1; j++){
        if(Hello[i-1] < Hello[i]){
            pivot = Helloint[i-1];
            break;
        }
        else {
            i--;
        }
    }

    //return error code if pivot is not found
    if(pivot == -1){
        printf("Already biggest possible number\n");
        free(Hello);
        free(Helloint);
        return -1;
    }

    //pivots index
    int P_index = -1;
    P_index = i - 1;

    // Append characters to left[]
    char *left = malloc((size+1)*sizeof(char));
    for(i = 0; i <= P_index; i++){
        left[i] = Hello[i];
    }
    left[P_index + 1] = '\0';

    int len_of_left = stringLength(left);

    //append characters to right[]
    char *right = malloc((size - P_index)*sizeof(char));
    for(i = P_index +1, j = 0 ; i <= len; i++, j++) {
        right[j] = Hello[i];
    }
    right[i + 1] = '\0';

    int len_of_right = stringLength(right);

    //append characters to rightint
    int *rightint = malloc(len_of_right * sizeof(int));
    for(i = 0; right[i] != 0; i++){
        rightint[i] = right[i] - '0';
    }

    //sorting right part descending order
    bubble_sortReverse(right, stringLength(right));

    //finding biggest
    int biggest;
    for(i = stringLength(right) - 1; i >= 0; i--){
        if(rightint[i] > pivot){
            biggest = rightint[i];
            break;
        }
    }

    //finding B_index
    int B_index;
    for(i = stringLength(right) - 1; i >= 0; i--) {
        if(rightint[i] == biggest){
            B_index = i;
            break;
        }
    }

    //swap pivot and biggest
    swap(&left[P_index], &right[B_index]);
    bubble_sort(right, stringLength(right));

    char *res = malloc(size * sizeof(char));
    for (i = 0; i < len_of_left; i++) {
        res[i] = left[i];
    }

    for(i = 0; i < len_of_right; i++) {
        res[len_of_left+i] = right[i];
    }

    res[len_of_left + len_of_right] = '\0';

    printf("Result:%s\n", res);

    free(Hello);
    free(Helloint);
    free(left);
    free(right);
    free(rightint);
    free(res);
    return 0;
}