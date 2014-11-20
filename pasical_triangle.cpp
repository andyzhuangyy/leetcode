#include <vector>
#include <iostream>
using namespace std;


vector<vector<int> > generate(int numRows)
{
    vector<vector<int > > ret;
    int i, j;
    vector<int > lastvect(numRows);

    for (i = 0; i < numRows ; ++i)
    {
        vector<int> vect1(i + 1);
        vect1[0] = 1;
        vect1[i] = 1;
        for( j = 1; j < i; ++j)
        {
            vect1[j] = lastvect[j - 1] + lastvect[j];
        }
        lastvect.assign(vect1.begin(), vect1.end());
        ret.push_back(vect1);
    }
    return ret;
}

int main(int argc, char** argv)
{
    vector<vector<int > > tmp;
    if(argc != 2)
        return 0;
    int numRows = atoi(argv[1]);

    tmp = generate(numRows);

    for(int i = 0; i < tmp.size(); ++i)
    {
        for(int j = 0; j < tmp[i].size(); ++j)
        {
            cout<<tmp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

