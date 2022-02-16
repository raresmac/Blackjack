#include <bits/stdc++.h>

using namespace std;

///declarare
bool carti[53];
int nras1,nras2;
int s1,s2;
int v1[21],v2[21];
char c1[42][4],c2[42][4],text[11];

///subprograme
void mana(int v[]);
int unrandcabaietii();
void afisare(int nr,int v[21],char m[42][4]);
void afisaredupa(int nr,int x,char m[42][4]);
void graficaromb(int nr,char c[42][4]);
void graficainima(int nr,char c[42][4]);
void graficafrunza(int nr,char c[42][4]);
void graficatrefla(int nr,char c[42][4]);
void graficaspate();

int main()
{
    srand(time(0));
    {///legenda
        cout<<"Legenda:\n"
            <<"Poti alege:\n"
            <<"1 - hit (Mai primesti o carte)\n"
            <<"2 - stand (Ramai cu acele carti)\n";
        cout<<"--------------------------------------------\n\n";
    }
    int a,i,banca=100,bet,joc=0;
    bool ok1=1,ok2=1;
    while(ok1){
        if(banca==0) break;
        s1=0,s2=0;
        int nr1=0,nr2=0;
        ok2=1;
        cout<<"Banca ta este de "<<banca<<"\n\n";
        if(joc==1) cout<<"Acesta a fost primul joc\n\n";
        else if(joc==2) cout<<"Acesta a fost al "<<joc<<"lea joc\n";
        if(joc){
            cout<<"Apasa 1 pentru a continua\n";
            cin>>text;
            if(text[0]!='1') ok1=0;
            cout<<'\n';
        }
        if(ok1){
            for(i=0;i<52;++i) carti[i]=0;
            cout<<"Alege miza: ";
            cin>>bet;
            cout<<'\n';
            while(bet>banca || bet<=0){
                if(bet>banca || bet<=0) cout<<"Ai ales o miza invalida!\n";
                cout<<"Alege miza: ";
                cin>>bet;
            }
            banca-=bet;
            joc++;
            {///generare
                mana(v1);
                mana(v2);
                a=v1[0];
                if(a/4<8) s1+=a/4+2;
                else if(a/4<12) s1+=10;
                else {s1+=11;nras1++;}
                a=v1[1];
                if(a/4<8) s1+=a/4+2;
                else if(a/4<12) s1+=10;
                else {s1+=11;nras1++;}
                a=v2[0];
                if(a/4<8) s2+=a/4+2;
                else if(a/4<12) s2+=10;
                else {s2+=11;nras2++;}
                a=v2[1];
                if(a/4<8) s2+=a/4+2;
                else if(a/4<12) s2+=10;
                else {s2+=11;nras2++;}
            }
            {///afisare
                afisare(nr1,v1,c1);
                nr1++;
                afisare(nr1,v1,c1);
                afisare(nr2,v2,c2);
                nr2++;
                afisare(nr2,v2,c2);
            }
            {///grafica
                cout<<"Cartile tale sunt: \n";
                if(c1[1][0]==4) graficaromb(0,c1);
                else if(c1[1][0]==3) graficainima(0,c1);
                else if(c1[1][0]==6) graficafrunza(0,c1);
                else if(c1[1][0]==5) graficatrefla(0,c1);
                if(c1[3][0]==4) graficaromb(1,c1);
                else if(c1[3][0]==3) graficainima(1,c1);
                else if(c1[3][0]==6) graficafrunza(1,c1);
                else if(c1[3][0]==5) graficatrefla(1,c1);
                cout<<"Cartile adversarului sunt: \n";
                if(c2[1][0]==4) graficaromb(0,c2);
                else if(c2[1][0]==3) graficainima(0,c2);
                else if(c2[1][0]==6) graficafrunza(0,c2);
                else if(c2[1][0]==5) graficatrefla(0,c2);
                graficaspate();
            }
            if(s1==21) {cout<<"Blackjack!Primesti de 2 ori miza!\n";banca+=3*bet;}
            else{
            {///joc
                while(ok2){
                    cout<<"Hit sau Stand?\n";
                    cin>>text;
                    cout<<'\n';
                    if(text[0]=='1'){
                        nr1++;
                        a=unrandcabaietii();
                        if(a/4<8) s1+=a/4+2;
                        else if(a/4<12) s1+=10;
                        else {nras1++;s1+=11;}
                        if(s1>21 && nras1>0) {s1-=10;nras1--;}
                        afisaredupa(nr1,a,c1);
                        if(c1[2*nr1+1][0]==4) graficaromb(nr1,c1);
                        else if(c1[2*nr1+1][0]==3) graficainima(nr1,c1);
                        else if(c1[2*nr1+1][0]==6) graficafrunza(nr1,c1);
                        else if(c1[2*nr1+1][0]==5) graficatrefla(nr1,c1);
                        if(s1>21) {cout<<"Ai pierdut!\n\n";ok2=0;}
                    }
                    else{
                        while(s2<=16){
                            nr2++;
                            a=unrandcabaietii();
                            if(a/4<8) s2+=a/4+2;
                            else if(a/4<12) s2+=10;
                            else {nras2++;s2+=11;}
                            afisaredupa(nr2,a,c2);
                            if(s2==21) break;
                        }
                        if(s2>21 && nras2>0) {s2-=10;nras2--;}
                        if(s2>21 || s1>s2) {cout<<"Ai castigat!\n\n";banca+=bet*2;}
                        else if(s2>s1) cout<<"Ai pierdut!\n\n";
                        else {cout<<"Egalitate!\n";banca+=bet;}
                        cout<<"Cartile robotului erau: \n\n";
                        for(i=0;i<=nr2;++i)
                            if(c2[2*i+1][0]==4) graficaromb(i,c2);
                            else if(c2[2*i+1][0]==3) graficainima(i,c2);
                            else if(c2[2*i+1][0]==6) graficafrunza(i,c2);
                            else if(c2[2*i+1][0]==5) graficatrefla(i,c2);
                        ok2=0;
                    }
                }
            }
            }
        }
    }
    if(banca>=100) cout<<"Felicitari! Ai ajuns la "<<banca<<" dolari!\n";
    else if(banca>0) cout<<"Imi pare rau! Ai ramas cu "<<banca<<" dolari\n";
    else cout<<"Imi pare rau, ai ramas fara bani!\n";
    return 0;
}
void graficaromb(int nr,char c[42][4]){
    nr=2*nr;
    cout<<"__________\n"
        <<"|"<<c[nr];
        if(c[nr][0]!='1') cout<<' ';
        cout<<"      |\n"
        <<"|   --   |\n"
        <<"|  -  -  |\n"
        <<"| -    - |\n"
        <<"|  -  -  |\n"
        <<"|   --   |\n"
        <<"|        |\n"
        <<"|______";
        if(c[nr][0]!='1') cout<<'_';
        cout<<c[nr]<<"|\n\n";
}
void graficainima(int nr,char c[42][4]){
    nr=2*nr;
    cout<<"__________\n"
        <<"|"<<c[nr];
        if(c[nr][0]!='1') cout<<' ';
        cout<<"      |\n"
        <<"|        |\n"
        <<"| --__-- |\n"
        <<"| -    - |\n"
        <<"|  -  -  |\n"
        <<"|   --   |\n"
        <<"|        |\n"
        <<"|______";
        if(c[nr][0]!='1') cout<<'_';
        cout<<c[nr]<<"|\n\n";
}
void graficafrunza(int nr,char c[42][4]){
    nr=2*nr;
    cout<<"__________\n"
        <<"|"<<c[nr];
        if(c[nr][0]!='1') cout<<' ';
        cout<<"      |\n"
        <<"|        |\n"
        <<"|    -   |\n"
        <<"|   ---  |\n"
        <<"|  ----- |\n"
        <<"|    -   |\n"
        <<"|        |\n"
        <<"|______";
        if(c[nr][0]!='1') cout<<'_';
        cout<<c[nr]<<"|\n\n";
}
void graficatrefla(int nr,char c[42][4]){
    nr=2*nr;
    cout<<"__________\n"
        <<"|"<<c[nr];
        if(c[nr][0]!='1') cout<<' ';
        cout<<"      |\n"
        <<"|        |\n"
        <<"|   __   |\n"
        <<"| __||__ |\n"
        <<"||__  __||\n"
        <<"|  |__|  |\n"
        <<"|        |\n"
        <<"|______";
        if(c[nr][0]!='1') cout<<'_';
        cout<<c[nr]<<"|\n\n";
}
void graficaspate(){
    cout<<"__________\n"
        <<"| - - - -|\n"
        <<"|- - - - |\n"
        <<"| - - - -|\n"
        <<"|- - - - |\n"
        <<"| - - - -|\n"
        <<"|- - - - |\n"
        <<"| - - - -|\n"
        <<"|________|\n\n";
}
void mana(int v[21]){
   for(int i=0;i<2;i++) {
      int num=(rand()%52);
      while(carti[num]==1) num=(rand()%52);
      v[i]=num;
      carti[num]=1;
   }
}
int unrandcabaietii(){
    int num=(rand()%52);
    while(carti[num]==1) num=rand()%52;
    carti[num]=1;
    return num;
}
void afisare(int nr,int v[21],char m[42][4]){
    int r=v[nr]/4;
    if(r<8) m[2*nr][0]=r+50;
    else if(r==12) m[2*nr][0]='A';
    else{
        if(r==8) {m[2*nr][0]='1';m[2*nr][1]='0';}
        else if(r==9) m[2*nr][0]='J';
        else if(r==10) m[2*nr][0]='Q';
        else if(r==11) m[2*nr][0]='K';
    }
    if(m[2*nr][0]!='1') m[2*nr][1]='\0';
    m[2*nr][2]='\0';
    r=v[nr]%4;
    if(r==0) m[2*nr+1][0]=4;
    else if(r==1) m[2*nr+1][0]=3;
    else if(r==2) m[2*nr+1][0]=6;
    else m[2*nr+1][0]=5;
    m[2*nr+1][1]='\0';
}
void afisaredupa(int nr,int x,char m[42][4]){
    int r=x/4;
    if(r<8) m[2*nr][0]=r+50;
    else if(r==12) m[2*nr][0]='A';
    else{
        if(r==8) {m[2*nr][0]='1';m[2*nr][1]='0';}
        else if(r==9) m[2*nr][0]='J';
        else if(r==10) m[2*nr][0]='Q';
        else if(r==11) m[2*nr][0]='K';
    }
    if(m[2*nr][0]!='1') m[2*nr][1]='\0';
    m[2*nr][2]='\0';
    r=x%4;
    if(r==0) m[2*nr+1][0]=4;
    else if(r==1) m[2*nr+1][0]=3;
    else if(r==2) m[2*nr+1][0]=6;
    else m[2*nr+1][0]=5;
    m[2*nr+1][1]='\0';
}
