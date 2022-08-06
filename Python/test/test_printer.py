import io
import unittest
from unittest.mock import patch
from src import printer


class PrintFunctionOutputTest(unittest.TestCase):

    @patch('builtins.input', side_effect=["Mo"])
    @patch('sys.stdout', new_callable=io.StringIO)
    def test_evaluate_console_output(self, mock_stdout, mock_input):
        printer.run()
        self.assertEqual(mock_stdout.getvalue().strip(), "Hello Mo!")


if __name__ == '__main__':
    unittest.main()
