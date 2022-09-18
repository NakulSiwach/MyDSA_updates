
void merge(vector<int>&arr,int s ,int e){
    int mid  = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int a[len1];
    int b[len2];

    int k = s;
    for(int i = 0;i<len1;i++){
        a[i] = arr[k++];
    }
    for(int i = 0;i<len2;i++){
        b[i] = arr[k++];
    }

    int i = 0;
    int j = 0;
    k = s;
    while (i<len1 and j <len2){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }

    while(i<len1){
        arr[k++] = a[i++];
    }
    while(j<len2){
        arr[k++] = b[j++];
    }
    return;

}
void helper(vector<int>&arr,int i , int j){
    int mid = (i+j)/2;
    if (i>=j){
        return;
    }
    helper(arr,i,mid); 
    helper(arr,mid+1,j);
    
    merge(arr,i,j);

}

void mergeSort(vector < int > & arr, int n) {
    helper(arr,0,n-1);
    return ;
}
