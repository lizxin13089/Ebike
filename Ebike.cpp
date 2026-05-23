#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#define giallo "\033[1m\033[33m"
#define clear "\033[0m"

struct Ebike{
    double x;
    double y;
    bool disp;//disponibilità
    long int id;
    double kmresta;
    double dista;
};

bool confrontaDistanza(const Ebike &a, const Ebike &b) {
    if(a.dista!=-1&&b.dista!=-1){
        return a.dista < b.dista;
    }else{
        return a.dista>b.dista;
    }
    
    
}

int main()
{
    int n=3;
    Ebike bicitot[n]={{2,4,true,3345,34},{5,1,true,2390,50},{10,6,false,8900,120}};
    
    
    double x,y;
    
    cout<<giallo<<"Ebike\n"<<clear;
    cout<<"Hello!\n";
    cout<<"Inserisci il tuo posto\n";
    cout<<"x:";
    cin>>x;
    cout<<"y:";
    cin>>y;
    
    //calc distanza tra utente e bici
    for(int i=0;i<n;i++){
        bicitot[i].dista=-1;
        if(bicitot[i].disp==true){
            bicitot[i].dista=sqrt(pow(bicitot[i].x-x,2)+pow(bicitot[i].y-y,2));
            
            //test
            //cout<<bicitot[i].dista<<endl;
        }
        
    }
    
    //ordinamento
    sort(bicitot,bicitot+n,confrontaDistanza);
    
    double kmPerc;
    int id;
    do{
        //visualizazione
        for(int i=0;i<n;i++){
            if(bicitot[i].disp){
                cout<<i+1<<". id:"<<bicitot[i].id<<"   distanza:"<<bicitot[i].dista<<"   Km resta:"<<bicitot[i].kmresta<<endl;
            }
        }
        
        //chose Ebike
        cout<<"inserisci la bici che vuoi(non id):";
        cin>>id;
        while(id-1<0||id-1>n||bicitot[id-1].disp==false){
            cout<<"Non esiste o non disponibile:";
            cin>>id;
        }
        //inserimento Km che deve percorere
        cout<<"Inserisci Km da percorere:";
        cin>>kmPerc;
        while(kmPerc<0){
            cout<<"non valido\n";
            cin>>kmPerc;
        }
        if(bicitot[id-1].kmresta-kmPerc<0){
            cout<<"Non riesce ad arrivare";
        }
    }while(bicitot[id-1].kmresta-kmPerc<0);
    bicitot[id-1].kmresta-=kmPerc;
    bicitot[id-1].disp=false;
    //test
    cout<<". id:"<<bicitot[id-1].id<<"   distanza:"<<bicitot[id-1].dista<<"   Km resta:"<<bicitot[id-1].kmresta<<endl;
    
    //calc soldi e tempo
    int ritardo;
    double tempo,soldi;
    while(kmPerc<0){
        cout<<"non valido";
        cin>>kmPerc;
    }
    srand(time(NULL));
    ritardo=rand()%15+1;
    tempo=(kmPerc/20*60)+ritardo;
    soldi=tempo*0.2;
    cout<<"Tempo:"<<tempo<<"min   Costa:"<<soldi<<" Euro";
    bicitot[id-1].disp=true;
    
    return 0;
}




