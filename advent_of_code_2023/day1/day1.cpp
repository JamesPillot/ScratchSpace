#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>

template <typename T>
bool set_contains(T element_in, std::set<T> &set_in)
{
    // Flag to tell if element in set
    bool in_set = false;
    // Iterator over set
    typename std::set<T>::iterator it;
    // check if element is in set
    it = set_in.find(element_in);
    if(it != set_in.end())
    {
        in_set = true;
    }
    return in_set;
}

int forward_pass(std::string str_in, std::vector<std::string> &valid_strings, 
                std::map<std::string, int> number_map)
{
    // Keeps track of where integer number was found if it was found
    int integer_index = -1;
    // Keeps track of where number from string was found if it was found, initialize to be huge for forward pass, want smallest winner
    size_t word_num_index = SIZE_MAX;
    // Keeps track of number string that was found (e.g "one")
    std::string found_num_string = "";
    // First digit of number from forward pass
    int first_digit = -1;
    // Loop through set of valid strings to find position of substring in our input string
    for (int i = 0; i < str_in.length(); ++i)
    {
        if(isdigit(str_in[i]))
        {
            integer_index = i;
            break;
        }
    }
    for (std::string substr: valid_strings)
    {   
        // std::cout << substr << std::endl;
        size_t pos = str_in.find(substr);
        // std::cout << word_num_index << std::endl;
        if(pos != std::string::npos && pos < word_num_index)
        {
            // store found number substring e.g. "one"
            found_num_string = substr;
            // store index of smallest number if we found it
            word_num_index = pos;
        }
    }
    // if word number index is smaller, return first digit found as word number
    if(word_num_index < integer_index || integer_index == -1)
    {
        first_digit = number_map[found_num_string];
    }
    else
    {
        first_digit = str_in[integer_index] - '0'; 
    }
    return first_digit;
}

int backward_pass(std::string str_in, std::vector<std::string> &valid_strings, 
                std::map<std::string, int> number_map)
{
    // Keeps track of where integer number was found if it was found
    int integer_index = -1;
    // Keeps track of where number from string was found if it was found, initialize to be small for backward pass, want biggest winner
    std::size_t word_num_index = 0;
    // Keeps track of number string that was found (e.g "one")
    std::string found_num_string = "";
    // Second digit of number from backward pass
    int second_digit = -1;
    // Loop through set of valid strings to find position of substring in our input string
    for (int i = (str_in.length() - 1); i >= 0; --i)
    {
        if(isdigit(str_in[i]))
        {
            integer_index = i;
            break;
        }
    }
    for (std::string substr: valid_strings)
    {   
        // std::cout << substr << std::endl;
        std::size_t pos = str_in.rfind(substr);
        if(pos != std::string::npos && pos > word_num_index)
        {
            // store found number substring e.g. "one"
            found_num_string = substr;
            // store index of smallest number if we found it
            word_num_index = pos;
        }
    }
    // std::cout << word_num_index << ": " << integer_index << std::endl;

    // if word number index is bigger and integer index is valid, return second digit found as word number
    if(integer_index >= word_num_index && integer_index != -1)
    {
        second_digit = str_in[integer_index] - '0'; 
    }
    else
    {
        second_digit = number_map[found_num_string];
    }
    return second_digit;
}

int get_num_from_string(std::string str_in)
{
    // digits of two digit number
    int first_digit; 
    int second_digit;

    // set of valid strings 
    std::vector<std::string> valid_strings = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // map of strings to integer
    std::map<std::string, int> number_map{{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
    {"eight", 8}, {"nine", 9}};
    // forwards pass to find first digit
    first_digit = forward_pass(str_in, valid_strings, number_map);
    // backwards pass to find second digit
    second_digit = backward_pass(str_in, valid_strings, number_map);
    // std::cout << "First digit is " << first_digit << std::endl;
    // std::cout << "Second digit is " << second_digit << std::endl;
    // Calculate two digit number
    const int first_digit_offset = 10;
    int number_out = (first_digit_offset * first_digit) + second_digit;

    static int debug_cnt = 1;
    std::cout << debug_cnt << ": " << "Number is " << number_out << std::endl;
    debug_cnt++;

    return number_out;
}


int main()
{
    // Open input file
    std::ifstream input_file;
    input_file.open("puzzle_input");
    // String to hold contents of input file when parsed line by line
    std::string file_line;
    // Check that input file is open
    if(input_file.is_open())
    {
        // sum of all digits calculated
        int sum = 0;
        // loop over input file until the end
        while(input_file.good())
        // for(int i = 0; i < 10; i++)
        {
            std::getline(input_file, file_line);
            // std::cout << file_line << std::endl;
            sum += get_num_from_string(file_line);
        }
        std::cout << "Sum is " << sum << std::endl;
    }
    return 0;
}