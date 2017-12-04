//
// Created by Benjamin on 9/5/17.
//
#include <iostream>
#include "ArrayLib.h"

int genRandInt(int min, int max, int& numLinesRun) {
    numLinesRun += 5; //3 parameters, 1 if, 1 return
    if (min > max) {
        return -1;
    }
    return min + rand() % (max - min + 1);
}


int* genRandArray(int size, int min, int max, int& numLinesRun){
    numLinesRun += 5; //for parameters and if
    if (min > max){
        int temp = min;
        min = max;
        max = temp;
        numLinesRun += 3; //for swap
    }
    int* arr = new int[size];
    numLinesRun += 1; //array creation
    numLinesRun += 2; //for loop initialization and first check
    for (int i = 0; i < size; i++){
        arr[i] = genRandInt(min, max, numLinesRun);
        numLinesRun += 3; //for loop update
    }
    numLinesRun += 1; //return
    return arr;
}


int* genShuffledArray(int size, int& numLinesRun){
    numLinesRun += 3; //parameters and if
    if (size < 1){
        numLinesRun += 1; //return statement
        return nullptr;
    }
    int* arr = new int[size];
    numLinesRun += 3; //arr assignment and for loop initialization
    for (int i = 0; i < size; ++i) {
        arr[i] = i+1;
        numLinesRun += 3; // loop update
    }
    numLinesRun += 2; //for loop initialation
    for (int j = size-1; j > 0; j--) {
        int pos = genRandInt(0,j, numLinesRun);

        int temp = arr[j];
        arr[j] = arr[pos];
        arr[pos] = temp;
        numLinesRun += 6; //for loop update
    }
    numLinesRun += 1; //return statement
    return arr;
}


std::string toString(const int* arrayPtr, int size) {
    std::string str = "{";
    for (int i = 0; i < size; i++){
        std::string pos = std::to_string(arrayPtr[i]);
        str += pos;
        if (i < size-1){
            str+=", ";
        }
    }
    str +="}";
    return str;
}


int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 6; //parameters and for loop init
    for (int i = 0; i < size; i++){
        numLinesRun += 1; //if
        if (arrayPtr[i] == numToFind){
            numLinesRun += 1; //return statement
            return i;
        }
        numLinesRun += 2; //for loop update
    }
    numLinesRun += 1; //return
    return -1;
}


int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 4; //parameters
    numLinesRun += 2; //for loop init
    for(int i = size-1; i >= 0; i--){
        numLinesRun += 1; //if
        if (arrayPtr[i] == numToFind){
            numLinesRun += 1; //return
            return i;
        }
        numLinesRun+= 2; //loop update
    }
    numLinesRun += 1; //return
    return -1;
}


int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    numLinesRun += 4; //parameters and check
    if (size < 1 ) {
        numLinesRun+= 1; //return
        return -1;
    }
    int maxIdx = 0;
    numLinesRun += 3; //maxIdx and loop init
    for (int i = 0; i < size; i ++){
        if (arrayPtr[i] > arrayPtr[maxIdx]){
            maxIdx = i;
            numLinesRun += 1; //assignment
        }
        numLinesRun+= 3; //loop update and check
    }
    numLinesRun += 1; //return
    return maxIdx;
}


//This function implements an insert sort algorithm
void sort(int* arrayToSort, int size, int& numLinesRun){
    numLinesRun +=5;//parameters and for loop init
    for (int i = 0; i < size; ++i) { //iterate through every position in the array

        int checkNum = arrayToSort[i]; //retrieve the next value in the array

        for (int j = i; j > 0; --j) { //iterate backwards through the portion of the array that is already sorted

            if (checkNum < arrayToSort[j-1]){ // check if our current value is less than the previous value in the array

                arrayToSort[j] = arrayToSort[j-1]; //if it is, bump the previous value up
                arrayToSort[j-1] = checkNum; //and put our current value in it's place
                numLinesRun += 2;

            } else { //if our current value is greater than or equal to the previous value, it's in the right place,
                    //so we can be a little bit more efficient by breaking our insert loop early
                numLinesRun += 1;
                break;
            }
            numLinesRun += 3; //loop iteration
        }
        numLinesRun += 5; //loop iteration
    }
}


int* copyArray(const int* arrayToCopy, const int size, int& numLinesRun){
    int* arr = new int[size];
    numLinesRun += 4; // parameters and arr init
    numLinesRun += 2; //for loop init
    for (int i = 0; i < size; ++i) {
        arr[i] = arrayToCopy[i];
        numLinesRun += 1; //assignment
    }
    numLinesRun += 1; //return
    return arr;
}

int binFind(const int* const arrayPtr, const int min, const int max, const int numToFind, int& numLinesRun){ //tail
    numLinesRun += 6; //params, eval
    if (min > max){
        numLinesRun += 1; //return
        return -1;
    }
    numLinesRun += 2; //assign, eval
    int mid = (min+max)/2;
    if (arrayPtr[mid]==numToFind){
        numLinesRun += 1; //return
        return mid;
    } else if (numToFind > arrayPtr[mid]){
        numLinesRun += 2; //eval, return
        return binFind(arrayPtr, mid+1, max, numToFind, numLinesRun);
    } else {
        numLinesRun += 1; //return
        return binFind(arrayPtr, min, mid-1, numToFind, numLinesRun);
    }
}



int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    numLinesRun += 1; //return
    return binFind(arrayPtr, 0, size-1, numToFind, numLinesRun);
}

/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 * or nullptr if (size1+size2) < 1
 */
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    numLinesRun += 4; //params, eval
    if (size1+size2 < 1) {
        numLinesRun += 1; //return
        return nullptr;
    }

    numLinesRun += 4; //assign, assign, assign, assign
    int count1 = 0;
    int count2 = 0;
    int* mergedArr = new int[size1+size2];
    int mergedArrPos = 0;

    numLinesRun += 1; //eval
    while(count1 < size1 && count2 < size2) {

        if(a1[count1] < a2[count2]) {
            numLinesRun += 2; //assign, assign
            mergedArr[mergedArrPos]=a1[count1];
            count1++;
        } else {
            numLinesRun += 2; //assign, assign
            mergedArr[mergedArrPos]=a2[count2];
            count2++;
        }
        mergedArrPos++;
        numLinesRun += 1; //eval, assign, while loop re-eval
    }

    numLinesRun += 1; //eval
    while(count1 < size1) {
        mergedArr[mergedArrPos]=a1[count1];
        count1++;
        mergedArrPos++;
        numLinesRun += 4; //assign, assign, assign, eval
    }
    numLinesRun += 1; //eval
    while(count2<size2) {
        mergedArr[mergedArrPos]=a2[count2];
        count2++;
        mergedArrPos++;
        numLinesRun += 4; //assign, assign, assign, eval
    }
    numLinesRun +=1; //return
    return mergedArr;
}

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1
 */

int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 4; //params, eval
    if (size < 1) {
        numLinesRun += 1; //return
        return nullptr;
    }

    numLinesRun += 1; //eval
    if (size == 1) {
        numLinesRun += 3; //assign, assign, return
        int* a = new int[size];
        *a = *arrayToSort;
        return a;
    }

    numLinesRun += 1; //assign
    int mid = size/2;

    numLinesRun += 1; //assign
    int* arr1 = mergeSort(arrayToSort, mid, numLinesRun);
    numLinesRun += 3; //I'll be fair and count the conditional operator as two (eval and assign). Assign, eval, assign
    int* arr2 = mergeSort(arrayToSort+mid, size%2==0?mid:mid+1, numLinesRun);
    numLinesRun += 3; //assign, eval, assign
    int* merged = merge (arr1, mid, arr2, size%2==0?mid:mid+1, numLinesRun);
    numLinesRun += 3; //destruct, destruct, return
    delete[] arr1;
    delete[] arr2;
    return merged;
}