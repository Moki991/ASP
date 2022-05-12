#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int inf=100000; //ili INT_MAX/2
vector< vector<int> > graf;

int main()
{
    ifstream input;
    input.open("distances2.txt");
    if (!input.is_open()){
        cout<<"Dogodila se pogreska prilikom otvaranja datoteke. \n";
        cout<<"Provjerite nalazi li se distances2.txt u istoj mapi kao i .cpp file!\n\n";
        return 1;
        }

    cout<<"\n========= Citam iz datoteke distances2.txt ==============\n";
    int n,m;
    input>>n>>m;
    cout<<n<<" gradova je povezano sa "<<m<<" veza\n";

    vector <int> vi(n,inf);
    graf.insert(graf.begin(),n,vi);

    for (int i=0;i<n;i++)
        graf[i][i]=0;

    int a,b,c;
    for (int i=0;i<m;i++){
        input>>a>>b>>c;
        cout<<a<<"-"<<b<<":"<<c<<endl;
        if (graf[a][b]>c)
            graf[a][b]=graf[b][a]=c;
        }
        
    for (int k=0;k<n;k++) //Floyd
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if (graf[i][j]>graf[i][k]+graf[k][j])
                    graf[i][j]=graf[i][k]+graf[k][j];
    cout<<"\n== matrica susjedstva najmanje udaljenosti za navedene gradove ==\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cout<<setw (4)<<graf[i][j];
        cout<<endl;
        }
    return 0;
}
