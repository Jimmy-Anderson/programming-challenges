#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int check_pattern(int x,int y,int rg,int cg,int rp,int cp,vector<string> &G,vector<string> &P)
{
    for(int i=0;i<rp;i++)
    {
        for(int j=0;j<cp;j++)
        {
            int ii=i+x;
            int jj=j+y;
            if(ii>=rg||jj>=cg)
                return 0;
            if(G[ii][jj]!=P[i][j])
                return 0;
        }
    }
    return 1;
}
string gridSearch(vector<string> G, vector<string> P) {
    int rg,cg,rp,cp;
    rg=G.size();
    cg=G[0].size();
    rp=P.size();
    cp=P[0].size();
    string ps="";
    for(int i=0;i<rp;i++)
        for(int j=0;j<cp;j++)
            ps.push_back(P[i][j]);
    cout<<ps<<"\n";
    int flag=0;
    for(int i=0;i<rg;i++)
        for(int j=0;j<cg;j++)
            if(check_pattern(i,j,rg,cg,rp,cp,G,P)==1)
            {
                flag=1;
                break;
            }
    if(flag==1)
        return "YES";
    else
        return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
