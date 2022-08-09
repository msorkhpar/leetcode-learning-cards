#set ($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Camel_case_method = "$Method.substring(0,1).toLowerCase()$Method.substring(1)")
#if (${PACKAGE_NAME} && ${PACKAGE_NAME} != "")package ${PACKAGE_NAME}

#end
class ${Name}{
    fun ${Camel_case_method}(input: IntArray): Int {
        for (data in input) {
            println(data)
        }
        return 0
    }
}