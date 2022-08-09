#set($Class_name = ${StringUtils.removeAndHump(${Name}, "_")})
#set($Test_class_name = ${StringUtils.removeAndHump(${Name}, "_").concat("Test")})
#set($Method = ${Method_name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()})
#set($Dir_path = ${DIR_PATH.concat("/").replaceAll("/","\.").concat(${Name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()})})
import unittest
from parameterized import parameterized

from ${Dir_path} import ${Class_name}


class ${Test_class_name}(unittest.TestCase):

    @parameterized.expand([
        ([0], 0),
    ])
    def test_actual_return_against_expected(self, data, expected):
        actual = ${Class_name}().${Method}(data)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
