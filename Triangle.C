int minArr(int* arr,int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        min = fmin(min,arr[i]);
    }
    return min;
}


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int n = triangleSize;
    
    int* arr1 = (int*)malloc(n*sizeof(int));
    int* arr2 = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr1[i]=INT_MAX;
        arr2[i]=INT_MAX;
    }
    arr1[0] = triangle[0][0];

    for(int i=1;i<n;i++){
        int* ptra;
        int* ptrb;
        if(i%2==0){
            ptra = arr1;
            ptrb = arr2;
        }
        else{
            ptra = arr2;
            ptrb = arr1;
        }

        for(int j=0;j<i+1;j++){
            
            if(j-1>=0 && j<i){
                ptra[j] = fmin(ptrb[j-1], ptrb[j]) + triangle[i][j];
            }
            else if(j-1>=0){
                ptra[j] = ptrb[j-1] + triangle[i][j];
            }
            else{
                ptra[j] = ptrb[j] + triangle[i][j];
            }

        }
    }

    if(n%2==0) return minArr(arr2,n);
    else return minArr(arr1,n);


}
