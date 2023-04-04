//
// Created by 28432 on 2023/4/4.
//

#include "leetcode.h"

void nextPermutation(int* nums, int numsSize){

    int replaced_idx, replace_idx, temp;
    int flag = 0, count = 0;
    int left, right;

    for(int i = numsSize - 1; i > 0; i--){
        if(nums[i - 1] < nums[i]) {
            replaced_idx = i - 1;
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        for(int i = 0; i < numsSize/2; i++){
            nums[i] = nums[i] ^ nums[numsSize - 1 - i];
            nums[numsSize - 1 - i]  = nums[i] ^ nums[numsSize - 1 - i];
            nums[i] = nums[i] ^ nums[numsSize - 1 - i];
        }
        return;
    }
    for(int i = numsSize - 1 ; i > 0; i--) {
        if(nums[i] > nums[replaced_idx]) {
            replace_idx = i;
            break;
        }
    }

    left = replaced_idx + 1;
    right = numsSize -1;
    while(left <= right){
        temp = (left + right)/2;
        if(nums[temp] <= nums[replaced_idx]) {
            right = temp - 1;
        } else {
            left = temp + 1;
        }
        replace_idx = right;
    }

    nums[replaced_idx] = nums[replaced_idx] ^ nums[replace_idx];
    nums[replace_idx]  = nums[replaced_idx] ^ nums[replace_idx];
    nums[replaced_idx] = nums[replaced_idx] ^ nums[replace_idx];
    for(int i =  1; count < (numsSize - 1 - replaced_idx)/2; i++){
        nums[i + replaced_idx] = nums[i + replaced_idx] ^ nums[numsSize - i];
        nums[numsSize - i]  = nums[i + replaced_idx] ^ nums[numsSize - i];
        nums[i + replaced_idx] = nums[i + replaced_idx] ^ nums[numsSize - i];
        count++;
    }
}











