#include <iostream>

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
	while (b != 0 && a >= b){
		temp1 = a; 
		temp2 = b; 

		b = a % b;
		a = temp2; 
	cout << temp1 << " = " << a << "(" << (temp1/temp2) << ")" << " + " << b << endl;
	};
}
