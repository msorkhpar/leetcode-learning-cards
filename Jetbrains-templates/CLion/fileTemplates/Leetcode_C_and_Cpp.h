#[[#include]]# <vector>
#set($Class_name = ${StringUtils.removeAndHump(${Name}, "_")})
#set ($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Pascal_case_method = "$Method.substring(0,1).toUpperCase()$Method.substring(1)")

class ${Class_name} {
public:
    int ${Pascal_case_method}(const std::vector<int> & input);
};
