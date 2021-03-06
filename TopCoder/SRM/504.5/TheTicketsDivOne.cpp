// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE
double mm[1005][1005];

/*
  Example:
  mm[2][0] = 1/6 + mm[2][2]/2
  mm[2][1] = mm[1][0]/3 + mm[2][0]/2
  mm[2][2] = mm[1][1]/3 + mm[2][1]/2

  So:
  mm[2][0] = 1/6 + mm[1][1]/3/2 + mm[1][0]/3/2/2 + mm[2][0]/2/2/2
*/

class TheTicketsDivOne {
public:
    double find(int n, int m) {
        mm[1][0] = 1.0;
        FOR(i,2,n) {
            mm[i][0] = 0.0;
            REP(j,i-1) {
                mm[i][0] = mm[i][0] / 2.0 + mm[i - 1][j];
            }
            mm[i][0] = (mm[i][0] + 1) / 6.0 / (1 - pow(0.5, i));
            FOR(j,1,i-1) {
                mm[i][j] = mm[i - 1][j - 1] / 3.0 + mm[i][j - 1] / 2.0;
            }
        }
        return mm[n][m - 1];
    }
};
// BEGIN CUT HERE
int main() {
    {
        TheTicketsDivOne theObject; 
        eq(0, theObject.find(2, 1),0.4444444444444444);
    }
    {
        TheTicketsDivOne theObject;
        eq(1, theObject.find(2, 2),0.5555555555555556);
    }
    {
        TheTicketsDivOne theObject;
        eq(2, theObject.find(1, 1),1.0);
    }
    {
        TheTicketsDivOne theObject;
        eq(3, theObject.find(3, 2),0.31746031746031744);
    }
    return 0;
}
// END CUT HERE
