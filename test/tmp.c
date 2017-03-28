int main(){
int x1 = 10;
int x2 = 20;
 if(x1 < x2){
    if(x1 > 0){
	if(x2 > 0){
	    return x1;
	}
    }
 }else{
    if(x2 > 0){
	if((x2 >= 0)&&(x1 >= 0)){
            return x2;
	}
    }
 }
}
