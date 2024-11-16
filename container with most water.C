#define max_h(a,b) ((a<b)?b:a)
int maxArea(int* height, int heightSize){
int maxArea = -1;
int beg  = 0;
int end = heightSize-1;
    while(beg<end){
        if(height[beg]<height[end]){
            maxArea = max_h(maxArea, height[beg]*(end-beg));
            beg++;
        }else{
            maxArea = max_h(maxArea, height[end]*(end-beg));
            end--;
        }    
    }
    return maxArea;
}
