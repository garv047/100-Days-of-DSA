int* relativeSortArray(int* arr1,int arr1Size,int* arr2,int arr2Size,int* returnSize){
    int* result=(int*)malloc(sizeof(int)*arr1Size);
    int idx=0;

    for(int i=0;iresult[j]){
                int tmp=result[i];
                result[i]=result[j];
                result[j]=tmp;
            }
        }
    }

    *returnSize=arr1Size;
    return result;
}
