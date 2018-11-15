#include <iostream>
#include <stack>

using namespace std;

/*precondition: a >= b >= 0
 *postcondition: return d = gcd(a,b) 
 */
int EuclidAlgGCD(int a, int b);

/* precondition: a >= b >= 0 */ 
/* postcondition: return d = gcd(a, b), s and t are set so that d = sa + tb 
 */
void ExtendedEuclidAlgGCD (int a, int b, int & s, int & t);

int main()
{
	int first_num, second_num;	

	cout << "Welcome to GCD Euclidean Algorithm!" <<endl;
	cout << "Please insert the first number: ";
	cin >> first_num;
	cout << "Please insert the second number: ";
	cin >> second_num;

	int gcd; 

	gcd = EuclidAlgGCD(first_num, second_num);

	cout << "GCD: " << gcd <<endl;

	int lin1, lin2; 

	ExtendedEuclidAlgGCD(first_num, second_num, lin1, lin2);  

	cout << "Have a nice day!" <<endl;

	return 0;
}


/*precondition: a >= b >= 0
 *postcondition: return d = gcd(a,b) 
 */
int EuclidAlgGCD(int a, int b)
{
	int temp; 
	while (b != 0 && a >= b){
		temp = b; 
		b = a % b;
		a = temp; 
	}; 
	return a; 
}


/* precondition: a >= b >= 0 */ 
/* postcondition: return d = gcd(a, b), s and t are set so that d = sa + tb  
 */
void ExtendedEuclidAlgGCD (int a, int b, int & s, int & t)
{
	int temp1;
	int temp2;  
	stack <int> total; 
	stack <int> divisor; 	
	stack <int> multiplier; 	

	while (b != 0 && a >= b){
		temp1 = a; 
		temp2 = b; 

		b = a % b;
		a = temp2; 
		if (b != 0){
			//store total and divisor into stack 
			total.push(temp1);
			divisor.push(a);
			multiplier.push(temp1/temp2);
		}
		cout << temp1 << " = " << a << "(" << (temp1/temp2) << ")" << " + " << b << endl;
	};
	int x, y =1, c, q =0;
	t =1;
	
	while (!total.empty() && !divisor.empty() && !multiplier.empty()){
		x =total.top(); 
		s = t; 
		c = divisor.top(); 
		t = (t*-multiplier.top())+q;

		cout << x << "(" << s << ")" << "+" << c << "(" << t << ")" <<endl; 
		
		q = s;		

		total.pop();
		divisor.pop();
		multiplier.pop();
	};
}
