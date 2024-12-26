int lastRemaining(int n) {
if(n==1) return 1;
int start=1;
int step=1;
int remaining=n;
bool LR=true;
while(remaining>1){
    if(LR || remaining%2==1 ){
start+=step;
    }
    step*=2;
    remaining/=2;
    LR=!LR;
}
return start;
}
