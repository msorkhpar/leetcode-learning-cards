#set($Class_name = ${StringUtils.removeAndHump(${Name}, "_")})
#set ($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Snake_case_method =${Method_name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()} )

from typing import List

class ${Class_name}:

    def $Snake_case_method(self, values: List[int]) -> int:
        for index, value in enumerate(values):
            print (index, value)
        return 0