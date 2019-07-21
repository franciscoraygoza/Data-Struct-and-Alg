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

int main(){
    int arr[] = {-10, -5, 0, 1, 2, 3, 4, 6, 8, 10, 17, 42, 100};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::vector<int> test_vector = {-10, -3, 0, 4, 7, 17, 43, 100};
    std::vector<int>::iterator it;

    for(it = test_vector.begin(); it != test_vector.end(); it++){
        std::cout << *it << ": ";
        int result = binary_search(arr, 0, n-1, *it);
        if(result == -1)
            std::cout << " is not in the array\n";
        else
            std::cout << " is at " << result << std::endl;
    }
    return 0;
}