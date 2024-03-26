
#include <iostream> 
#include <cstring>
#include <cctype>
#include  "stack.h"

using namespace std;

int main()
{
	Stack <char> palindromeStack;
	char palindrome[100], base[100];

	char exitW = 'C';
	char exceptions[] = "~`!@#$%^&*()_-+=[]{};:\"\',.<>/? \\|";

	while (exitW == 'C')
	{

		strncpy(palindrome, base, 100);

		cout << "Please enter a string:\n>";

		cin.getline(palindrome, 100);

		if (palindrome[0] == NULL)
			exitW = 'Q';
		else
		{
			char* pch;
			char value, prvsValue;
			bool isPalindrome = true;

			for (int j = 0; j < 100; j++)
			{
				pch = (char*)memchr(exceptions, palindrome[j], strlen(exceptions));
				if (palindrome[j] != NULL && pch == NULL && palindrome[j] != char(-52))
					palindromeStack.push(toupper(palindrome[j]));
			}

			for (int j = 0; j < 100; j++)
			{
				pch = (char*)memchr(exceptions, palindrome[j], strlen(exceptions));
				if (palindrome[j] != NULL && pch == NULL && palindrome[j] != char(-52))
				{
					value = prvsValue = toupper(palindrome[j]);
					palindromeStack.pop(value);
					if (value != prvsValue) isPalindrome = false;

				}
			}

			cout << "\n" << "\"" << palindrome << "\"";

			if (isPalindrome)
				cout << " is palindrome";
			else
				cout << " is NOT palindrome";

			cout << "\n\n";
		}
	}
}
