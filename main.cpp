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

	while (b != 0 && a >= b){
		temp1 = a; 
		temp2 = b; 

		b = a % b;
		a = temp2; 
		if (b != 0){
			//store total and divisor into stack 
			total.push(temp1);
			divisor.push(a);
		}
		//cout << temp1 << " = " << a << "(" << (temp1/temp2) << ")" << " + " << b << endl;
	};
	int new_total=0;
	int multi_one=1;
	int multi_two;

	while (!total.empty() && !divisor.empty()){
		temp1 = total.top();
		temp2 = divisor.top(); 
		//base case 
		if (new_total == 0){
			new_total = a - temp1;
			multi_two=new_total/temp2; 
		}
		else{
			int temp_multi = multi_one;
			multi_one = multi_two; 
			multi_two= temp_multi * -temp2; 
		}
		total.pop();
		divisor.pop();

		cout << a << "=" << temp1 << "(" << multi_one << ")" << "+" << temp2 << "(" << multi_two << ")" <<endl; 
	};
}

