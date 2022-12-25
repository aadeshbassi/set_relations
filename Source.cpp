/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Set Theory to Find if the function is Transitive,Symmetrive,Reflexive and Equivalence. 
#include <iostream>

using namespace std;
bool Transitive = false;
bool Reflexive = false;
bool Symmetric = false;

bool Check_pair(int a, int b, int R[], int size_R)
{
    for (int i = 0; i < size_R; i = i + 2)
    {
        if (a == R[i] && b == R[i + 1])
        {
            return true;
        }
    }
    return false;
}
void Check_Reflexive(int a[], int R[], int size_a, int size_R)
{
    bool is_reflexive = false;
    for (int i = 0; i < size_a; i++)
    {
        is_reflexive = Check_pair(a[i], a[i], R, size_R);
        if (is_reflexive == false)
        {
            cout << "Not Reflexive";
            break;
        }
    }
    if (is_reflexive == true)
    {
        cout << "Reflexive";
        Reflexive = true;
    }
}

void Check_Symmetric(int a[], int R[], int size_a, int size_R)
{
    bool is_symmetric = true;
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_a; j++)
        {
            if (Check_pair(a[i], a[j], R, size_R) == true)
            {
                if (Check_pair(a[j], a[i], R, size_R) == true) is_symmetric = true;
                else
                    is_symmetric = false;
            }

            if (is_symmetric == false)
            {
                cout << "Not Symmetric";
                break;
            }
        }
        if (is_symmetric == false)
        {
            break;
        }
    }
    if (is_symmetric == true)
    {
        cout << "Symmetric";
        Symmetric = true;
    }
}

void Check_Transitive(int a[], int R[], int size_a, int size_R)
{
    bool is_transitive = true;
    for (int i = 0; i < size_a - 2; i++)
    {
        for (int j = i + 1; j < size_a - 1; j++)
        {
            for (int k = j + 1; k < size_a; k++)
            {
                if (Check_pair(a[i], a[j], R, size_R) == true)
                {
                    if (Check_pair(a[j], a[k], R, size_R) == true)
                    {
                        if (Check_pair(a[i], a[k], R, size_R) == true)is_transitive = true;
                        else is_transitive = false;
                    }

                }

                if (is_transitive == false)
                {
                    cout << "Not Transitive";
                    break;
                }
            }
            if (is_transitive == false)
            {
                break;
            }
        }
        if (is_transitive == false)
        {
            break;
        }

    }
    if (is_transitive == true)
    {
        cout << "Transitive";
        Transitive = true;
    }
}

void Check_Equivalence()
{
    if (Transitive == true && Reflexive == true && Symmetric == true)
    {
        cout << "Equivalence";
    }
    else cout << "Not Equivalence";
}
int main()
{
    int A[] = { 0,1,2,3 };
    int R[] = { 0,0,0,1,0,3,1,0,1,1,2,2,3,0,3,3 };
    int size_a = sizeof(A) / sizeof(A[0]);
    int size_r = sizeof(R) / sizeof(R[0]);
    Check_Reflexive(A, R, size_a, size_r);
    cout << endl;
    Check_Symmetric(A, R, size_a, size_r);
    cout << endl;
    Check_Transitive(A, R, size_a, size_r);
    cout << endl;
    Check_Equivalence();
    return 0;
}
