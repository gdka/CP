#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
using namespace std;
#define pb push_back
#define f(i,j,k,l) for(int i = j; i < k; i+=l)
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define sciii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define mp make_pair
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

typedef pair<int, int> ii

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector <bool> vb;

typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, vi> miv;


ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }
ll mcm(ll a, ll b){ return a * b / gcd(a, b); }
ll sq(ll a) { return a*a; }
ll pot(ll a, ll b){ return b ? sq(pot(a, b >> 1))*(b & 1 ? a : 1) : 1; }
ll potMod(ll a, ll e){ return e ? ((sq(potMod(a, e >> 1)) % MOD)*(e & 1 ? a : 1)) % MOD : 1; }


bool IsPowerOfTwo(ulong x){ return (x != 0) && ((x & (x - 1)) == 0);}
unsigned long ut(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;

}

//NUMERO DE REG 
r(n) = Comb(n, 4) + Comb(n, 2) + 1 = (n^4 – 6n^3 + 23n^2 – 18n + 24)/24

// STRING A INT
int a;
strig str " ALGO"
stringstream(str) >> a;

string s=a.substr(i,p);

llu mulmod(llu A, llu B, llu MOD) {
    llu res = 0, temp;
    if (B >= MOD) B %= MOD;

    while (A != 0) {
        if (A & 1) {
            if (B >= MOD - res) res -= MOD;
            res += B;
        }
        A >>= 1;
        temp = B;
        if (B >= MOD - B) temp -= MOD;
        B += temp;
    }
    return res;
}

//ORDENAR VEC AND ARRAYS:
//vector
sort(ar.begin(),ar.end());

sort(k,k+x);
//DE STRING A INT.
int num=(int)(g-48);

//Vector erarse:
  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

//COLA:

queue<int> myqueue;
  myqueue.front() //MUESTRA EL PRIMER ELEMENTO
  myqueue.push (myint); //METER EL PRIMERO
  myqueue.pop(); //BORRA EL PRIMERO

// cola de priodiar
   priority_queue <int > cola;
   cola.top()
   cola.push()
   cola.empty()
   cola.pop()


// MAP
    map<char,int> mymap;
    mymap.size() //VALOR DEL MAPA (CANT ELEMENTOS)
    mymap.max_size()
    mymap.find ('e')
    mymap.erase ('c');
    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );
    mymap.clear();