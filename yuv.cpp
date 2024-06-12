#include<bits/stdc++.h>

using namespace std;

int func(string s1, string s2)
{
    int arr[26]={0};
    for(int i=0;i<s1.length();i++)
    {
        arr[s1[i] - 'A']++;
    }

    for(int i=0;i<s2.length();i++)
    {
        arr[s2[i] - 'A']--;
    }

    int ans = 0;
    for(int i=0;i<26;i++)
    {
        if(arr[i] < 0)
        {
            ans += abs(arr[i]);
        }
    }

    return ans;

}

long long funcc(int arr[], int n)
{
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans *= arr[i];
    }

    return ans;
}

int main()
{
    cout << func("ABD","AABCCAD") << endl;
}