#set($Class_name = ${StringUtils.removeAndHump(${Name}, "_")})
#set($Test_class_name = ${StringUtils.removeAndHump(${Name}, "_").concat("Test")})
#set($Test_data = ${StringUtils.removeAndHump(${Name}, "_").concat("Test").concat("_test_data")})
#set($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Cpp_method = "$Method.substring(0,1).toUpperCase()$Method.substring(1)")
#set($C_method = ${Method_name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()})
#set($Dir_path = ${DIR_PATH.replace("src/","").concat("/").concat(${Name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()})})
#[[#include]]# <iostream>
#[[#include]]# <vector>

#[[#include]]# "gtest/gtest.h"
#[[#include]]# "${Dir_path}.h"
#[[#include]]# "${Dir_path}.c"

struct ${Test_data} {
    std::vector<int> input;
    int expected;
};

struct ${Test_class_name} : public testing::TestWithParam<${Test_data}> {
};

INSTANTIATE_TEST_SUITE_P(${Test_class_name}TestCases, ${Test_class_name},
                         testing::Values(
                            ${Test_data}
                                {{0}, 0}
                         )
);

TEST_P(${Test_class_name}, ${Test_class_name}CppTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;

    auto actual = ${Class_name}().${Cpp_method}(input);
    
    ASSERT_EQ(actual, expected);
}

TEST_P(${Test_class_name}, ${Test_class_name}CTestCase) {
    auto input = GetParam().input;
    auto const &expected = GetParam().expected;
    
    int actual = ${C_method}(input.data(), input.size());
    
    ASSERT_EQ(actual, expected);
}
