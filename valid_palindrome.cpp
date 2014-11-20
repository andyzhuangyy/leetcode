#include <string>
using namespace std;

bool is_palindrome(string s)
{
    int i, j;

    if(0 == s.size())
        return true;
    

    for(i = 0, j = s.size() - 1; i < j; )
    {
        if(!((s[i] >= '0' && s[i] <='9') ||
            (s[i] >= 'a' && s[i] <='z')|| 
            (s[i] >= 'A' && s[i] <='Z'))) 
        {
            ++i;
            continue;
        }

        if(!((s[j] >= '0' && s[j] <='9') ||
            (s[j] >= 'a' && s[j] <='z')||
            (s[j] >= 'A' && s[j] <='Z'))) 
        {
            --j;
            continue;
        }

        if(s[i] >= '0' && s[i] <='9' && s[j] >= '0' && s[j] <='9')
        {
            if(s[i] != s[j])
                return false;
        }
        else if(s[i] >='a' && s[i] <= 'z' && !(s[j] >= '0' && s[j] <='9'))
        {
            if(s[i] != s[j] && 
               s[i] - s[j] != 'a' - 'A')
                return false;
        }
        else if(s[i] >='A' && s[i] <= 'Z' && !(s[j] >= '0' && s[j] <='9'))
        {
            if(s[i] != s[j] && 
               s[j] - s[i] != 'a' - 'A')
                return false;
        }
        else
            return false;
        ++i; --j; 
    }
    return true;
}

int main(int argc, char** argv)
{
    if(argc != 2)
        return 0;

    if(is_palindrome(string(argv[1])))
        printf("\"%s\", is palindrome\n", argv[1]);
    else
        printf("\"%s\", is not palindrome\n", argv[1]);
    
    return 0;
}
