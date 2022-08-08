#include <iostream>
#include "gtest/gtest.h"
#include "Printer.h"

using namespace std;

TEST(PrinterTest, test_output_of_std_in_and_out) {
    string input_str = "Mo";
    string expected_str = "Hello Mo!";

    stringstream fake_input(input_str);
    ostringstream prompt;
    ostringstream output;
    Printer::run(fake_input, prompt, output);
    auto actual = output.str();
    EXPECT_EQ(actual, expected_str);
}