#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int inf=100000; //ili INT_MAX/2
vector< vector<int> > graf;


int main(){
    ifstream input;
    input.open("distances.txt");
    if (!input.is_open()){
            cout<<"Dogodila se pogreska prilikom otvaranja datoteke. \n";
            cout<<"Provjerite nalazi li se distances.txt u istoj mapi kao i .cpp file!\n\n";
            return 1;
                        }

    int n,m,x;
    cout<<"\n========= Citam iz datoteke distances.txt ==============\n";
    input>>n;
    cout<<n<<" gradova je povezano \n";
    input>>m;
    cout<<m<<" cesta povezuje te gradove\n";
    input>>x;
    cout<<"Krece se iz grada "<<x<<endl;

    vector <int> bio(n,0);
    vector <int> dist (n,inf);
    vector <int> vi(n,inf);
    graf.insert(graf.begin(), n, vi);

    int a,b,c;
    for (int i=0;i<m;i++){
            input>>a>>b>>c;
            if (graf[a][b]>c)
                graf[a][b]=graf[b][a]=c;
                        }

    dist[x]=0;
    int udaljenost,cvor;
    for (int i=0; i<n-1;i++){
        udaljenost = inf+1; //tražimo najbliži čvor u kojem još nismo bili
        for (int j=0; j<n; j++)
            if (dist[j]<udaljenost && !bio[j]){
                udaljenost=dist[j];
                cvor=j;
                                              }

    bio[cvor]=1;
    for (int j=0; j<n; j++)
        if (dist[j]>udaljenost +graf[cvor][j]) //provjeravamo može li se popraviti udaljenost...
            dist[j]=udaljenost+graf[cvor][j];
                            }
    cout<<"=========================================="<<endl;
    for (int j=0; j<n; j++)
        cout<<"do grada "<<j<<" najkraći put iznosi: "<<dist[j]<<endl;
    input.close();
    return 0;
}
