void main(){
	bool a=false;
	bool b=true;
	int c=1;
	int d=2;
	
	a=true || false;
	print("attendue 1, ", a);
	a=true && false;
	print("attendue 0, ", a);
	a=false==false;
	print("attendue 1, ", a);
	a=false!=true; 
	print("attendue 1, ", a);
	
	a=true || a;
	print("attendue 1, ", a);
	a=true && a;
	print("attendue 1, ", a);
	a=false==a;
	print("attendue 0, ", a);
	a=false!=a;
	print("attendue 0, ", a);
	
	a=b || a;
	print("attendue 1, ", a);
	a=b && a;
	print("attendue 1, ", a);
	a=b==a;
	print("attendue 1, ", a);
	a=b!=a; 
	print("attendue 0, ", a);
	
	
	
	a=c<d;
	print("attendue 1, ", a);
	a=c<=d;
	print("attendue 1, ", a);
	a=c>d;
	print("attendue 0, ", a);
	a=c>=d;
	print("attendue 0, ", a);
	
	a=1<d;
	print("attendue 1, ", a);
	a=1<=d;
	print("attendue 1, ", a);
	a=1>d;
	print("attendue 0, ", a);
	a=1>=d;
	print("attendue 0, ", a);
	
	a=1<2;
	print("attendue 1, ", a);
	a=1<=2;
	print("attendue 1, ", a);
	a=1>2;
	print("attendue 0, ", a);
	a=1>=2;
	print("attendue 0, ", a);
	
		
}
