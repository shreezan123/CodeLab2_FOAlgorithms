

#include <iostream>
#include <string>
using namespace std;

int multiplyLargeNumbers(int* first_number,
                         int first_number_length,
                         int* second_number,
                         int second_number_length,
                         int* result) {
    // Now write your code here to multiply the two numbers
    // and write the result to result, and return its number
    // of digits.
    
    //string first_num_string = numberAsArrayToString(first_number, first_number_length); //passes firstnumber array and returns string value of it
    
    
    
    //we will have an array and shift left will have to add a position to the left of the array and put 0 there.
    int carry_array[1000];
    int carry_over = 0;
    int k =0 ;
    for (int i = first_number_length-1 ; i>=0; i--){
        for (int j = second_number_length; j>=0; j--){
            if (second_number[i]*first_number[j] < 10){
                int local_carry = 0;
                local_carry = carry_over;
                if (local_carry > 0){
                    carry_array[k] = ((second_number[i]*first_number[j])+ carry_over);
                }
                else{
                    carry_array[k] = second_number[i]*first_number[j];
                }
                k++;
            }
            
            else{
                int multiplied_number = second_number[i]*first_number[j];
                int to_put_in_array = multiplied_number%10;
                carry_over = multiplied_number/10;
                carry_array[k] = to_put_in_array;
                k++;
            }
        }
        //iterate through this array to make sure that it works.
        
    }
    return 0;
}



int stringtoarray(const string& num_as_string,
                                int* num_array) {
    for (int i = 0; i < num_as_string.length(); ++i) {
        if (num_as_string[i] >= '0' &&
            num_as_string[i] <= '9') {
            num_array[i] = static_cast<int>(num_as_string[i] - '0');
        } else {
            return -1;
        }
    }
    return num_as_string.length();
}


string arraytostring(int* num_array, int length) {
    if (length <= 0 ) {
        return "NaN";
    }
    string num_string;
    for (int i = 0; i < length; ++i) {
        num_string += static_cast<char>(num_array[i] + '0');
    }
    return num_string;
}

int main(){
    int first_number[10000];
    int second_number[10000];
    int first_number_length, second_number_length;
    cout << "Let's multiply two numbers." << endl;
    {
        //asking for number passing it to fromstring, and get length
        cout << "Please enter the first number: ";
        string first_number_as_string;
        cin >> first_number_as_string;
        first_number_length = stringtoarray(
                                                          first_number_as_string,
                                                          first_number);
    }
    
    {
        //asking for second number and passing to fromstring and get length
        cout << "Please enter the second number: ";
        string second_number_as_string;
        cin >> second_number_as_string;
        second_number_length = stringtoarray(
                                                           second_number_as_string,
                                                           second_number);
    }
    cout << "First number is : " << arraytostring(first_number, first_number_length) << endl;
    cout << "Second number is : " << arraytostring(second_number, second_number_length) << endl;
    
    
    
    
    int result[20000];

    int result_length =
    multiplyLargeNumbers(first_number, first_number_length,
                         second_number, second_number_length,
                         result);
    
    cout << "Result: " << arraytostring(result, result_length) << endl;
    return 0;
}
