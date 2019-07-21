#include<iostream>
#include<vector>

int binary_search(int arr[], int l, int r, int val){
    if(l <= r){
        int mid = (r + l)/2;

        if(arr[mid] == val) return mid; //FOUND
        if(val < arr[mid]) return binary_search(arr, l, mid-1, val);
        //else
        return binary_search(arr, mid+1, r, val);
    }
    return -1; //NOT FOUND
}
int binary_search(int arr[], int n, int val){
    int l = 0, r = n;
    while(l < r){
        int mid = (r+l)/2;

        if(arr[mid] == val) return mid;
        if(val < arr[mid]) r = mid - 1;
        else
            l = mid + 1;        
    } 
    return -1;
}
int main(){
    int arr[] = {-10, -5, 0, 1, 2, 3, 4, 6, 8, 10, 17, 42, 100};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::vector<int> test_vector = {-10, -3, 0, 4, 7, 17, 43, 100};
    std::vector<int>::iterator it;

    for(it = test_vector.begin(); it != test_vector.end(); it++){
        std::cout << *it << " -> ";
        int result = binary_search(arr, n-1, *it);
        if(result == -1)
            std::cout << " is not in the array\n";
        else
            std::cout << " is at " << result << std::endl;
    }

    //testing for empty arr
    int a[] = {};
    n = sizeof(a)/sizeof(a[0]);
    std::cout << binary_search(a, n, 3) << std::endl;
    //testing for arr of size 1
    int b[] = {1};
    n = sizeof(b)/sizeof(b[0]);
    std::cout << binary_search(b, n, 1) << std::endl;  
    return 0;
}