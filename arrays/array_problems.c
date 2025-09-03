#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int mathSum = 0;
    int n = 10;
    int diff;
    int arr[10] = {7,8,9,11,12,14,16,17,20,21};
    // mathSum = (arr[9] * (arr[9] + 1)) / 2;
    // for (int i=0;i < 10; i++) {
    //     sum += arr[i];
    // }
    // if (sum != mathSum)
    //     printf("%d\n", mathSum - sum);
    // else {
    //     printf("All natural numbers are present\n");
    // }

    // now if the array is not starting from 0
    diff = arr[0];
    // for(int i=0;i<10;i++) {
    //     if (arr[i] - i != diff) {
    //         printf("Missing element %d\n", diff + i);
    //         break;
    //     }  
    // }

    // multiple missing array
    for(int i=0;i<10;i++) {
        if (arr[i] - i != diff) {
	    while(arr[i] - i > diff) {
		printf("Missing element %d\n", i + diff);
                diff++;
	    }
        }
    }

    // find missing element in unsorted array
    int unsorted_array[10] = {3,7,4,9,12,6,1,11,2,10};		// sequence from 1 to h - we are assuming we know the highest number in the array i.e. 12 here
    int hash[12] = {0};

	for(int i=0; i < 10;i++) {
		hash[unsorted_array[i]]++;
	}

	for(int i = 1; i < 12; i++) {
		if (hash[i] == 0)
			printf("Missing element found %d\n", i);
	}

	
    int sorted_array[10] = {3,6,8,8,10,12,15,15,15,20};
	// finding duplicates
	int lastDup = 0;
	for(int i=0; i < 9; i++) {
		if (sorted_array[i] == sorted_array[i+1] && sorted_array[i] != lastDup) {
			lastDup = sorted_array[i];
			printf("Duplicate found %d\n", sorted_array[i]);
		}
	}

	// count duplicates
	int count = 0;
	int j = 0;
	for(int i=0; i < 9; i++) {
		if (sorted_array[i] == sorted_array[i+1]) {
			j = i;
			while(sorted_array[j] == sorted_array[i]) {j++;}
			count += (j-i);
			printf("%d is appearing %d times\n", sorted_array[i], j - i);
			i = j - 1;
		}
	}

	// finding duplicate elements and their count using hashing in a sorted array
	// as hashing, it assumes we know the largest number in the array, in this case, i.e. 20 so that can be the size of the hash table
	int hash2[20] = {0};
	int dupCount = 0;
	for(int i = 0; i < 10; i++) {
		hash2[sorted_array[i]]++;
	}
	for(int i = 0; i < 20; i++) {
		if (hash2[i] > 1) {
			printf("%d is appearing %d times\n", i, hash2[i]);
			dupCount += hash2[i];
		}
	}
	printf("Total Duplicate Count here : %d\n", dupCount);

	// find duplicate elements in an unsorted array
	int array2[10] = {8,3,6,4,6,5,6,8,2,7};
	int duplicateCount = 0;
	for(int i=0; i < 9; i++) {
		for(int j=i+1;j<10;j++) {
			if (array2[i] != -1 && array2[i] == array2[j]) {
				duplicateCount++;
				array2[j] = -1;
			}
		}
	}
	printf("Duplicates Count found in unsorted array are %d\n", duplicateCount);

    // finding a pair of elements with sum K
    int array3[10] = {6,3,8,10,16,7,5,2,9,14};
    int desired_sum = 10;
    // O(n2) method
    for(int i=0; i < 9; i++) {
        for(int j = i + 1; j < 10; j++) {
            if (desired_sum == array3[i] + array3[j]) {
                printf("A pair with sum %d are: (%d,%d)\n", desired_sum, array3[i], array3[j]);
            }
        }
    }
    // Hashing Method - we need to know the largest element in the array
    int hash3[16] = {0};
    for(int i = 0; i  < 10; i++){
        if (hash3[desired_sum - array3[i]] >= 1 && desired_sum - array3[i] > 0) {
            printf("[Hashing] - A pair with sum %d are found: (%d,%d)\n", desired_sum, array3[i], desired_sum - array3[i]);
	}
	hash3[array3[i]]++;
    }

    // find a pair of elements with sum equal to K in a sorted array
    int sorted_array2[10] = {1,3,4,5,6,8,9,10,12,14};
    int sum_needed = 10;
    int l = 0, h = 9;
    while (l<h) {
        if (sorted_array2[l] + sorted_array2[h] == sum_needed){
            printf("Found a pair with sum %d -> (%d,%d)\n", sum_needed, sorted_array2[l], sorted_array2[h]);
            l++;
            h--;
        } else if (sorted_array2[l] + sorted_array2[h] > sum_needed) {
            h--;
        } else {
            l++;
        }
    }

    // find min and max in a single scan
    int array4[10] = {4,8,3,9,6,2,10,7,-1,5};
    int min = array4[0], max = array4[0];
    for(int i=1; i < 10;i++) {
        if (array4[i] < min) {min = array4[i];}
        else if(array4[i] > max) {max = array4[i];}
    }
    printf("Min: %d Max: %d\n", min, max);

}
