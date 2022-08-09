#[[#include]]# <iostream>
#[[#include]]# "${Name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()}.h"
#set($Class_name = ${StringUtils.removeAndHump(${Name}, "_")})
#set ($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Pascal_case_method = "$Method.substring(0,1).toUpperCase()$Method.substring(1)")

using namespace std;

int ${Class_name}::${Pascal_case_method}(const vector<int> &input) {
    int result = 0;
    for (const auto &record: input) {
        cout << record;
    }
    return result;
}
