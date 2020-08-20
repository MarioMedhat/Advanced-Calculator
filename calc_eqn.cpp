// BY : MARIO MEDHAT
// GITHUB REPOSITORY LINK : https://github.com/MarioMedhat/Advanced-Calculator

#include <iostream>
using namespace std;

#define DEVIDE_BY_ZERO 0
#define MULT_OR_DIV_AFTER_OP 2

// it only works for positive power
// also it does not work with decimal power
// as this will needs a root function
// and this can be di=one in the future
double power(double num1, int num2) {

	double ans = 1;


	for (int i = 1; i <= num2; i++) {
	
		ans = ans * num1;

	}
	return ans;

}

void error_handler(char number) {

	switch (number)
	{

	case DEVIDE_BY_ZERO:
		cout<<("DIVISION BY ZERO OCCURED!\n");

	case MULT_OR_DIV_AFTER_OP:
		cout << ("'*' OR '/' AFTER AN OPPERAND HAS NO MEANING!\n");

	default:
		break;
	}

}

double calc_eqn(char data[]) {

	// here is how we are going to work 
	// we will start checking every element in the input array
	// to convert the numbers from digits into one number
	// need a variable called "work" which will add the value of the next element (digit)
	// and multiply the previous by "10"
	// Example : " 1 , 5 , 3 " to convert these 
	// three seperated digits stored in an array into one 
	// numbers that has a value of "153"
	// first make the variable "work" = 1 , then multiply it by 10
	// after this add 5 to it , then the variable "work" = "15"
	// after this multiply by "10" so "work" will be = "150"
	// finaly add "3" to it so as to have a final value of "153"

	// also there must be a variable to check if the entered number is decimal or not
	// if the entered number is a decimal one 
	// this variable will change from 0 to 1 
	// and will be multiplyed by 10 at every interation (every digit)
	// and after the number ends it will be = to the work value devided by the decimal value

	// Example : "10.125"
	// we will treat as if they are two numbers "10 + 0.125"
	// so when we face the '.' "work" = 10 , will be added to the final answer
	// and we will treat the "0.125" as it is "125" / "1000" 
	// and after ending the decimal number
	// the work variable will be = "125" and the decimal = "1000"
	// so work will be = work \ decimal = "0.125"
	double work = 0;
	int decimal = 0;

	// after this we need to take care of the mathematical operations priority
	// and hrer is how we going to handle it
	// Example : supose that we have an equation like this 

	// "123+55*99-8/66="

	// so first after converting the first from digits into number
	// we will see if the facing operand is ( '+' or '-' ) or ( '*' or '/' )
	// if the facing is ( '+' or '-' ) we will multiply it to the "buffer" 
	// and add it to the variable containing the final answer
	// and reset both the buffer and work variable
	// if we faced '+' the the reset value of the "buffer" will be '1'
	// but if '-' then the reset value will bee '-1' so as when
	// we will multiply the next nymber to it , it will have a negative value

	// but if the facing is ( '*' or '/' ) we will save it 
	// to the buffer variable and multiply with the next number 
	// wich will be held by the variable "work"  
	// and reset the work variable only
	// here we will need a variable that tells us at facing the next operand
	// if the last one was '/' or not because if yes we will 
	// make the work value = "work"^(-1)

	// and wait to face a ( '+' or '-' ) to add the buffer to the final answer variable


	// here is the trace of this code
	// first the initial value of "work" and "final_ans" is '0'
	// because it will not be used in any ( '*' or '/' ) operation 
	// but the "buffer" will have initial value as '1'
	// also we will supose that we have converted the seperated digits into a number 
	// because we have explained how it works
	// so we ar going here to see only what happens when we face an operation
 
	// in the last example at the first operation facing
	// "work" = 123 , "buffer" = 1 , "final_ans" = 0 , devide = 0
 
	// as the next one is '+' so 
	// devide = 0 , so keep "work" as it is
	// "final_ans" = "final_ans" + ( "work" * "buffer" )
	// and reset the "work" and "buffer" values
	// so "work" = 0 , "buffer" = 1 , "final_ans" = 123 , devide = 0
 
	// at the next facing operand
	// "work" = 55 , "buffer" = 1 , "final_ans" = 123 , devide = 0
	// devide = 0 , so keep "work" as it is
	// and as it is '*' 
	// so "buffer" = "buffer" * "work"
	// and reset the value of "work" only   
	// so "work" = 0 , "buffer" = 55 , "final_ans" = 123 , devide = 0
 
	// at the next facing operand
	// "work" = 99 , "buffer" = 55 , "final_ans" = 123 , devide = 0
	// devide = 0 , so keep "work" as it is
	// and as it is '-' 
	// "final_ans" = "final_ans" + ( "work" * "buffer" )
	// and reset the "work" and "buffer" values  
	// so "work" = 0 , "buffer" = -1 , "final_ans" = 5568 , devide = 0
 
	// at the next facing operand 
	// devide = 0 , so keep "work" as it is
	// "work" = 8 , "buffer" = -1 , "final_ans" = 5568 , devide = 0
	// and as it is '/' 
	//  so "buffer" = "buffer" * "work"
	// and reset the value of "work" only  
	// so "work" = 0 , "buffer" = -8 , "final_ans" = 5568 , devide = 1
 
	// at the end
	// "work" = 66 , "buffer" = -8 , "final_ans" = 5568 , devide = 1
	// as devide = 1 
	// so "work" = 1/66 , devide = 0
	// and as it is '*' 
	// so "buffer" = "buffer" * "work"
	// and reset the value of "work" only  
	// so "work" = 0 , "buffer" = -(8/66) , "final_ans" = 5568 , devide = 0
 
	// at the end make the last operation
	// "work" = 66 , "buffer" = -8 , "final_ans" = 5568 , devide = 1
	// devide = 1 , so keep "work" as it is
	// so "work" = 1/66 , devide = 0
	// "final_ans" = 5568 + ( - (8/66) )
	// = 5567.878788

	// so at the end our algorithm solved the problem :D
	double final_ans = 0;
	double buffer = 1;

	// this is a flag to check if there is a division or not 
	char devide_flag = 0;

	// also we have to handle a very important case
	// it is ormal that the user entres '+' or '-'
	// after any opperand
	// '+' must do nothing in this case
	// '-' must multiply the buffer by -1
	// so after any opperand we must set the flag to 0
	// this indicates that the last input is a opperand
	// and in '+' and '-' we ,ust never save any numbers
	// as the flag = 0
	// only in '-' multiply the buffer by -1
	// and if in '*' or '-', the flag = 0
	// we must return a zero to the user
	// as somting like this "5+*6=" has no meaning
	char opp_flag = 0;

	// this is only a counter to navigate in the array
	char i = 0;

	while ((data[i] != '=') && (data[i] != ')')) {

		// check if the user entered a digit
		if (data[i] >= '0' && data[i] <= '9') {

			//save only the numerical value of the digit not the ascii 
			data[i] = data[i] - '0';

			//add the next element to the value of the work variable
			work = 10 * work + data[i];
			decimal *= 10;

			opp_flag = 1;

		}

		// check if the next one is an operand
		// or the character '.' for decimal numbers

		// also check for division and for decimal number 

		else {

			if (decimal) {

				work = work / decimal;
				decimal = 0;

			}

			// check if the devide value is 1 or not 
			// if one so do this
			// check if the value of "work" is zero
			// so we can not continue 
			// so show to the user the error message of the division by zero
			// by calling the function "error_handler" that shows an error message 
			// according to each error occured by passing to it the number of the error
			// you can find the number of each error defined in the top of the code
			// and return 0

			if (devide_flag) {

				if (work) {

					// the division is correct
					work = 1 / work;
					// turn of the division flag
					devide_flag = 0;

				}
				else {

					error_handler(DEVIDE_BY_ZERO);
					return 0;
					

				}


			}



			// if the next one is '+'
			if (data[i] == '+') {

				// add the values stored in the current working number
				// and buffer to the final answer
				// note : we multiplied the current working number by the buffer 
				// because there could be many previous numbers
				// multiplied by each other

				// check if the last input was a number

				if (opp_flag) {
					final_ans = final_ans + (work * buffer);

					// reset the values

					work = 0;
					buffer = 1;
					opp_flag = 0;

				}

			}

			// if the next one is '-'
			else if (data[i] == '-') {

				// add the values stored in the current working number
				// and buffer from the final answer
				// note : we multiplied the current working number by the buffer 
				// because there could be many previous numbers
				// multiplied by each other

				// check if the last input was a number

				if (opp_flag) {
					final_ans = final_ans + (work * buffer);
					work = 0;
					buffer = -1;
					opp_flag = 0;
				}

				// explained at the begining
				buffer = -1 * buffer;
			}

			// if the next one is '*'
			else if (data[i] == '*') {

				// check if the last input is a number

				if (opp_flag) {
					// multiply the current number by the previous one in the buffer

					buffer = buffer * work;

					// reset the values

					work = 0;

					opp_flag = 0;
				}

				else {

					error_handler(MULT_OR_DIV_AFTER_OP);
					return 0;

				}
			}

			// if the next one is '/'
			else if (data[i] == '/') {

				// check if the last input is a number

				if (opp_flag) {
					// devide the current number by the previous one in the buffer

					buffer = buffer * work;

					// reset the values
					devide_flag = 1;
					work = 0;

					opp_flag = 0;
				}

				else {
				
					error_handler(MULT_OR_DIV_AFTER_OP);
					return 0;

				}

			}

			// if the next one is '.'
			else if (data[i] == '.') {

				//i++;
				//work = work + (data[i] / decimal);
				//decimal *= 10;
				final_ans = final_ans + (work * buffer);

				//reset the values

				work = 0;
				buffer = 1;
				decimal = 1;
			}

			// check if this is an internal equation
			else if (data[i] == '(') {

				// so the work value will be = the total answer of this equation
				work = calc_eqn(data + i + 1);

				// set the opp_falg to 1
				// as the charater '(' returns a number
				// so this is not an opperand
				opp_flag = 1;

				// skip all the next element and continue from after the internal equation 
				while (data[i] != ')') {

					i++;

				}


			}

			// check if the comming operation is a power
			else if (data[i] == '^') {

				work = power(work, calc_eqn(data + i + 2));

				// skip all the next element and continue from after the internal equation 
				while (data[i] != ')') {

					i++;

				}

			}
		

		}

			// go to next element
			i++;

	}

		if (decimal) {

			work = work / decimal;

		}


		// check if the devide value is 1 or not 
		// if one so do this
		// check if the value of "work" is zero
		// so we can not continue
		// so show to the user the error message of the division by zero
		// by calling the function "error_handler" that shows an error message 
		// according to each error occured by passing to it the number of the error
		// you can find the number of each error defined in the top of the code
		// and return 0
		if (devide_flag) {

			if (work) {

				work = 1 / work;

			}
			else {

				
				error_handler(DEVIDE_BY_ZERO);
				return 0;

			}


		}

		// save the value of the last number  
		final_ans = final_ans + (work * buffer);

		return final_ans;
	

}

int main() {

	// test case
	char input[160] = { "1.25+5+6+6+9+(8*+-+--+-9)+5^2-9=" };
	cout << input;
	cout << ("\n");
	cout << calc_eqn(input);
	cout << ("\n");
	
	return 0;

}