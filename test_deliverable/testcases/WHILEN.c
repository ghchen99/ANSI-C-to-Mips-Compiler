int f(int x1,int x2){
int z = 0;
while(x1 != x2){
    if(z < 0){
        return 0;
    }
  z = z + 1;
  x1 = x1 + 1;
}
return z;
}
