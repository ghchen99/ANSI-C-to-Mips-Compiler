int f(int x1,int x2){
 if(x1 < x2){
    if(x1 > 0){
	if(x2 > 0){
	    return x1;
	}
    }
 }else{
    if(x2 > 0){
	if((x2 >= 0)&&(x2 != 199)){
            return x2;
	}
    }
 }
}
