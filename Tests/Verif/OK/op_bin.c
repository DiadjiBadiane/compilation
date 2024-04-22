void main(){

	int a=1;
	int b=2;
	int c;
	
	c=~b;
	c= a&b;
	print("attendue 2, ", c);
	c= a|b;
	print("attendue 3, ", c);
	c= a^b;
	print("attendue 3, ", c);
	c= a>>b;
	print("attendue , ", c);
	c= a>>>b;
	print("attendue , ", c);
	c= a<<b;
	print("attendue , ", c);
	
	
	c=~1;
	print("attendue , ", c);
	c= 1&b;
	print("attendue , ", c);
	c= 1|b;
	print("attendue , ", c);
	c= 1^b;
	print("attendue , ", c);
	c= 1>>b;
	print("attendue , ", c);
	c= 1>>>b;
	print("attendue , ", c);
	c= 1<<b;
	print("attendue , ", c);
	
	
	c=~1;
	print("attendue , ", c);
	c= 1&1;
	print("attendue , ", c);
	c= 1|1;
	print("attendue , ", c);
	c= 1^1;
	print("attendue , ", c);
	c= 1>>1;
	print("attendue , ", c);
	c= 1>>>1;
	print("attendue , ", c);
	c= 1<<1;
	print("attendue , ", c);
	
}

