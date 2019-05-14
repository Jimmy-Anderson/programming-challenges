#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int n=w.length();
    int j=n-2;
    while(w[j]>=w[j+1])
        j--;
    if(j==-1)
    return "no answer";
    int k=n-1;
    while(w[j]>=w[k])
        k--;
    w[j]=(w[k]+w[j])-(w[k]=w[j]);
    cout<<w<<"\n";
    int r=n-1;
    int s=j+1;
    while(r>s)
    {
        w[r]=(w[r]+w[s])-(w[s]=w[r]);
        r--;
        s++;
    }
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
