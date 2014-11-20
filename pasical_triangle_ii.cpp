#include <vector>
#include <iostream>
using namespace std;


vector<int> getRow(int rowIndex)
{
    vector<int> vect1(rowIndex + 1);
    vector<int> vect2(rowIndex + 1);
    int i, j;
    vector<int> *plast, *pcurr, *ptmp;
    

    plast = &vect1;
    pcurr = &vect2;
    for (i = 0; i < rowIndex + 1; ++i)
    {
        for( j = 1; j < rowIndex; ++j)
        {
            (*pcurr)[j] = (*plast)[j - 1] + (*plast)[j];
        }
        (*pcurr)[0] = 1;
        (*pcurr)[i] = 1;
        ptmp = pcurr;
        pcurr = plast;
        plast = ptmp;
    }
    return *plast;
}

int main(int argc, char** argv)
{
    vector<int > tmp;
    if(argc != 2)
        return 0;
    int rowIndex = atoi(argv[1]);

    tmp = getRow(rowIndex);

    for(int i = 0; i < tmp.size(); ++i)
    {
        cout<<tmp[i]<<" ";
    }
    
    return 0;
}

