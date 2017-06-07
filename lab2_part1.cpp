

#include <iostream>
#include <string>
using namespace std;

string arraytostring(int* num_array, int length) ;
int additionfcn (int* twoDimensionArray, int rows, int columns);


int multiplyLargeNumbers(int* first_number,
                         int first_number_length,
                         int* second_number,
                         int second_number_length,
                         int* result) {
    
    
    int num1 = stoi(arraytostring(first_number, first_number_length));
    int num2 = stoi(arraytostring(second_number, second_number_length));
    int remainder1 = num1%10;
    int remainder2 = num2%10;
    int rows,columns;
    if (remainder1 == 0){
        rows = num1 / 10;
    }
    else{
        rows = (num1/10)+1;
    }
    
    if(remainder2 == 0) {
        columns = num2 / 10;
    }
    else{
        columns = (num2/10)+1;
        
    }
    int twoDimensionArray[rows][columns];
    int rowarray[rows];
    int colarray[columns];
    while (true){
        if (remainder1 == 0){
            for (int i = 0 ; i < rows ; i++){
                rowarray[i] = 10;
            }
        }
        else{
            for (int i = 0 ; i < rows-1 ; i++){
                rowarray[i] = 10;
            }
            rowarray[rows-1] = remainder1;
            break;
        }
    }
    
    while (true){
        if (remainder2 == 0){
            for (int i = 0 ; i < columns ; i++){
                colarray[i] = 10;
            }
        }
        else{
            for (int i = 0 ; i < columns-1 ; i++){
                colarray[i] = 10;
            }
            colarray[columns-1] = remainder2;
            break;
        }
    }
    for (int i = 0; i< rows; i++){
        for (int j = 0; j< columns; j++){
            twoDimensionArray[i][j] = rowarray[i]*colarray[j];
        }
    }
    //test
    int summation = 0;
    for (int i = 0; i< rows; i++){
        for (int j = 0; j<columns; j++){
            summation += twoDimensionArray[i][j];
        }
    }
    return summation;
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
    
    cout << "Result: " << result_length << endl;
    return 0;
}
