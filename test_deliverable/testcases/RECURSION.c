int factorial(int i) {
   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int  f() {
   int i = 3;
   return factorial(i);
}
