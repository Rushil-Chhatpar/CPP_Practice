// https://www.hackerrank.com/challenges/the-grid-search/problem
#include "headers.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

// int patternHeight = P.size();
// int patternWidth = P[0].size();
// int imageHeight = G.size();
// int imageWidth = G[0].size();
// if (patternHeight>imageHeight || patternWidth>imageWidth)
// {
//     return "NO";
// }
// for (int y=0;y<=imageHeight-patternHeight; y++)
// {
//     for (int x=0; x<=imageWidth-patternWidth; x++)
//     {
//         bool found = true;
//         for (int j=y; j<y+patternHeight; j++)
//         {
//             for (int i=x; i<x+patternWidth; i++)
//             {
//                 if (P[j-y][i-x]!=G[j][i])
//                 {
//                     found = false;
//                     break;
//                 }
//             }
//             if (!found)
//                 break;
//         }
//         if (found)
//         {
//             return "YES";
//         }
//     }
// }
// return "NO";


string gridSearch(vector<string> G, vector<string> P)
{
    // O( (imageHeight - patternHeight + 1) * (imageWidth - patternWidth + 1) * patternHeight * patternWidth )
    int imageWidth = G[0].length();
    int imageHeight = G.size();

    int patternWidth = P[0].length();
    int patternHeight = P.size();

    for(int y = 0; y < imageHeight - patternHeight + 1; y++)
    {
        for(int x = 0; x < imageWidth - patternWidth + 1; x++)
        {
            bool found = true;
            for(int j = 0; j < patternHeight; j++)
            {
                for(int i = 0; i < patternWidth; i++)
                {
                    if(P[j][i] != G[y + j][x + i])
                    {
                        found = false;
                        break;
                    }
                }
                if(!found)
                    break;
            }
            if(found)
            {
                cout << "x: " <<x << ", y: " << y <<endl;
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

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

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
