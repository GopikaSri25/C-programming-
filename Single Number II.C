
int singleNumber(int* nums, int numsSize) {

    int result = 0;

    for(int i=0; i<32; i++){
        int bits = 0;
        for(int k=0; k<numsSize; k++){
            /*if( nums[k] & ((unsigned int)1<<i) ){
                bits++;
            }*/

            bits += (nums[k]>>i) & 1;
        }
        result |= ((unsigned int)(bits%3)<<i);
    }
    return result;
}
