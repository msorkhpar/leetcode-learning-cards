#set ($Test_class_name = ${Name.concat("Test")})
#set ($Method = ${StringUtils.removeAndHump(${Method_name},"_")} )
#set($Camel_case_method = "$Method.substring(0,1).toLowerCase()$Method.substring(1)")
#if (${PACKAGE_NAME} && ${PACKAGE_NAME} != "")package ${PACKAGE_NAME}

#end
import org.assertj.core.api.Assertions.assertThat

import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.Arguments
import org.junit.jupiter.params.provider.MethodSource

internal class ${Test_class_name} {
    companion object {
        @JvmStatic
        fun parametersProvider() = listOf(
            Arguments.of(intArrayOf(0), 0),
        )
    }

    @ParameterizedTest
    @MethodSource("parametersProvider")
    fun `${Camel_case_method} should return the expected value`(input: IntArray, expected: Int) {
        val actual = ${Name}().${Camel_case_method}(input)
        assertThat(actual).isEqualTo(expected)
    }
}