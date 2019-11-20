#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// declaring the function for given operation
string performAddition(string number1, string number2, string sign);
string performSubstraction(string number1, string number2, string sign);

// starting point of the program
// determines the smaller and larger number to pass to declared functions
int main()
{
    // sample big nnumbers
    string number3 = "-95", number4 = "-10005";

    // for determinig sign of the operation
    string sign = "";

    // for storing the result returned from functions
    string output;

    if (number4[0] == *"-" && number3[0] == *"-")
    {
        // case 1: if both numbers are negative
        output = performAddition(number4.substr(1), number3.substr(1), "-");
    }
    else if (number4[0] == *"-" && number3[0] != *"-")
    {
        // case 2: if the first one is only negative
        if ((number4.length() - 1) > number3.length())
        {
            // 1.inner case: the first one is bigger
            output = performSubstraction(number4.substr(1), number3, "-");
        }
        else if ((number4.length() - 1) < number3.length())
        {
            // 3.inner case: the second one is bigger
            output = performSubstraction(number3, number4.substr(1), "+");
        }
        else
        {
            // 3.inner case: Both are equal in length
            int c = 0;

            // making control by one of the number length
            while (c > number4.length())
            {
                if ((number4[c + 1] + '0') > (number3[c] + '0'))
                {
                    // if number 4 is greater
                    output = performSubstraction(number4.substr(1), number3, "-");
                    return 0;
                }
                else if ((number4[c + 1] + '0') < (number3[c] + '0'))
                {
                    // if number 3 is greater
                   output = performSubstraction(number3, number4.substr(1), "+");
                    return 0;
                }

                // increameting control
                c++;
            }

            // both are equal in magnitude : zero will be the result
            output = performSubstraction(number3, number4.substr(1), "+");
        }
    }

    // case 3: if the second one is only negative
    else if ((number4[0] != *"-" && number3[0] == *"-"))
    {
        if (number4.length() > (number3.length() - 1))
        {
            // 1.inner case: if the first number is better
            output = performSubstraction(number4, number3.substr(1), "+");
        }
        else if (number4.length() < (number3.length() - 1))
        {
            // 2.inner case: if the second number is bigger
            output = performSubstraction(number3.substr(1), number4, "-");
        }
        else
        {
            // 3.inner case: Both are equal in length
            int c = 0;

            // making control by one of the number length
            while (c > number4.length())
            {
                if ((number4[0] + '0') > (number3[1] + '0'))
                {
                    // if the first number is better
                    output = performSubstraction(number4, number3.substr(1), "+");
                    return 0;
                }
                else if ((number4[0] + '0') < (number3[1] + '0'))
                {
                    // if the second number is bigger
                    output = performSubstraction(number3.substr(1), number4, "-");
                    return 0;
                }
            }

            // if both are equal in magnitude, result will be zero
            output =  performSubstraction(number3.substr(1), number4, "-");
        }
    }
    else
    {
        // case 4: if the both of them is posetive
        output = performAddition(number4, number3, "+");
    }

    // printing answer
    cout << "Answer: " + output << endl;

    // exiting
    return 0;
}

string performAddition(string number1, string number2, string sign)
{
    // checking the bigger number in size
    if (number1.length() > number2.length())
        swap(number1, number2);

    // string for result of operation
    string operationResult = "";

    // finding smaller length  for loop control
    int smallerLength = number1.length(), largerLength = number2.length();

    // reversig for loop manipulation
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    // carry variable
    int carry = 0;

    // adding upto smaller length
    for (int i = 0; i < smallerLength; i++)
    {
        int sum = ((number1[i] - '0') + (number2[i] - '0') + carry);
        operationResult.push_back(sum % 10 + '0');
        carry = sum > 9 ? 1 : 0;
    }

    // adding the remaning ones
    for (int i = smallerLength; i < largerLength; i++)
    {
        int sum = ((number2[i] - '0') + carry);
        operationResult.push_back(sum % 10 + '0');
        carry = sum > 9 ? 1 : 0;
    }

    // if any carry avaliable
    if (carry > 0)
    {
        operationResult.push_back(carry + '0');
    }

    // back-reversing the result, since we made operation using reversing
    reverse(operationResult.begin(), operationResult.end());

    return sign == "+" ? operationResult : ("-" + operationResult);
}

string performSubstraction(string number1, string number2, string sign)
{
    // reversing both numbers for looping
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    // stores result of the operation
    string operationResult = "";

    // contrrols the loops until the samller lengtth is coverd
    int control = 0;

    while (control < number2.length())
    {

        // calculating the current difference bewtween the digits
        int currentDifference = (number1[control] - '0') - (number2[control] - '0');

        // if thier differenece is leass than zero we need some maths
        if (currentDifference < 0)
        {
            // finding the real difference
            currentDifference += 10;

            // if the next elements are one zero followed by non zero elements
            if ((number1[control + 1] - '0') != 0)
            {
                number1[control + 1] = ((number1[control + 1] - '0') - 1) + '0';
            }
            else
            {
                // for multiple zeros until non zero element is found
                int nextNumberIndex = control + 1;

                while (nextNumberIndex < number1.length())
                {
                    if ((number1[nextNumberIndex] - '0') == 0)
                    {
                        // making zeros nine
                        number1[nextNumberIndex] = (9 + '0');
                        nextNumberIndex++;
                    }
                    else
                    {
                        // making the non zero element, element - 1
                        number1[nextNumberIndex] = ((number1[nextNumberIndex] - '0') - 1) + '0';
                        break;
                    }
                }
            }
        }

        // adding at the back of the operationResult
        operationResult.push_back(currentDifference + '0');

        // updating control for while loop
        control++;
    }

    // for remaning elemnts of the larger number
    for (int i = number2.length(); i < number1.length(); i++)
    {
        operationResult.push_back(number1[i]);
    }

    // reversing back the operationResult since all operation are done in reverse manner
    reverse(operationResult.begin(), operationResult.end());

    return sign == "+" ? operationResult : ("-" + operationResult);
}