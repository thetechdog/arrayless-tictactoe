#include<iostream>
#include<cstring>
using namespace std;
short checkflag(char a1,char a2,char a3,char b1, char b2, char b3, char c1, char c2, char c3, short turncount);
int main(){//a - line 1, b - line 2, c - line 3
    char namex[30],name0[30],a1='?',a2='?',a3='?',b1='?',b2='?',b3='?',c1='?',c2='?',c3='?';char poz[10];short player=1,stopflag=0,turncount=0;
    cout<<R"del(__        __   _                            _        
\ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___  
 \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \
  \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |
   \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/ 
                                                     
    _                         _               
   / \   _ __ _ __ __ _ _   _| | ___  ___ ___ 
  / _ \ | '__| '__/ _` | | | | |/ _ \/ __/ __|
 / ___ \| |  | | | (_| | |_| | |  __/\__ \__ \
/_/   \_\_|  |_|  \__,_|\__, |_|\___||___/___/
                        |___/                 
 _____ _     _____         _____          _ 
|_   _(_) __|_   _|_ _  __|_   _|__   ___| |
  | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \ |
  | | | | (__ | | (_| | (__ | | (_) |  __/_|
  |_| |_|\___||_|\__,_|\___||_|\___/ \___(_)
  )del";
    cout<<endl<<"Press ENTER to continue.";
    cin.get();
    cout<<"Caution: When inputting the coordinates for your corresponding symbol, you MUST use this format: \"line,column\". For Example: 1,2."<<endl;
    cout<<"Doing anything else WILL invalidate your game."<<endl;
    cout<<"Please input the name for the first player: ";
    cin.getline(namex,30);
    cout<<"Please input the name of the second player: ";
    cin.getline(name0,30);
    while(stopflag==0){          //&& turncount<=9 was used here before, but now is redundant
        cout<<" "<<a1<<" | "<<a2<<" | "<<a3<<" "<<endl;
        cout<<"-----------"<<endl;
        cout<<" "<<b1<<" | "<<b2<<" | "<<b3<<" "<<endl;
        cout<<"-----------"<<endl;
        cout<<" "<<c1<<" | "<<c2<<" | "<<c3<<" "<<endl;
        turncount++;
        cout<<"Turn "<<turncount<<':'<<endl;
        if(player==1){
            cout<<namex<<", input the coordinates for X: "<<endl;
            cin>>poz;
            if(strcmp(poz,"1,1")==0 && a1=='?') a1='X';
            else if(strcmp(poz,"1,2")==0 && a2=='?') a2='X';
            else if(strcmp(poz,"1,3")==0 && a3=='?') a3='X';
            else if(strcmp(poz,"2,1")==0 && b1=='?') b1='X';
            else if(strcmp(poz,"2,2")==0 && b2=='?') b2='X';
            else if(strcmp(poz,"2,3")==0 && b3=='?') b3='X';
            else if(strcmp(poz,"3,1")==0 && c1=='?') c1='X';
            else if(strcmp(poz,"3,2")==0 && c2=='?') c2='X';
            else if(strcmp(poz,"3,3")==0 && c3=='?') c3='X';
            else{cout<<"The position that you're requesting is either already occupied, doesn't exist, or I cannot understand it. The game is over."; return 0;}
            player=0;
        }
        else if(player==0){
            cout<<name0<<", input the coordinates for 0: "<<endl;
            cin>>poz;
            if(strcmp(poz,"1,1")==0 && a1=='?') a1='0';
            else if(strcmp(poz,"1,2")==0 && a2=='?') a2='0';
            else if(strcmp(poz,"1,3")==0 && a3=='?') a3='0';
            else if(strcmp(poz,"2,1")==0 && b1=='?') b1='0';
            else if(strcmp(poz,"2,2")==0 && b2=='?') b2='0';
            else if(strcmp(poz,"2,3")==0 && b3=='?') b3='0';
            else if(strcmp(poz,"3,1")==0 && c1=='?') c1='0';
            else if(strcmp(poz,"3,2")==0 && c2=='?') c2='0';
            else if(strcmp(poz,"3,3")==0 && c3=='?') c3='0';
            else{cout<<"The position that you're requesting is either already occupied, doesn't exist, or I cannot understand it. The game is over."; return 0;}
            player=1;
        }
        stopflag=checkflag(a1,a2,a3,b1,b2,b3,c1,c2,c3,turncount);
        
   }
     cout<<"Final results: "<<endl;
     cout<<" "<<a1<<" | "<<a2<<" | "<<a3<<" "<<endl;
     cout<<"-----------"<<endl;
     cout<<" "<<b1<<" | "<<b2<<" | "<<b3<<" "<<endl;
     cout<<"-----------"<<endl;
     cout<<" "<<c1<<" | "<<c2<<" | "<<c3<<" "<<endl;
    if (stopflag==1) printf("The winner is... %s! Congrats! \n",namex);
    else if (stopflag==2) printf("The winner is... %s! Congrats! \n",name0);
    else if(stopflag==-1)cout<<"It's a draw."<<endl;
    return 0;
}
short checkflag(char a1,char a2,char a3,char b1, char b2, char b3, char c1, char c2, char c3, short turncount){
    //0 still going, 1 - player X has won, 2 - player 0 has won, -1 - draw
    //lines X
    if (a1==a2 && a2==a3 && a1=='X') return 1;
    if (b1==b2 && b2==b3 && b1=='X') return 1;
    if (c1==c2 && c2==c3 && c1=='X') return 1;
    //diagonals X
    if (a1==b2 && b2==c3 && a1=='X') return 1;
    if (a3==b2 && b2==c1 && a3=='X') return 1;
    //columns X
    if (a1==b1 && b1==c1 && a1=='X') return 1;
    if (a2==b2 && b2==c2 && a2=='X') return 1;
    if (a3==b3 && b3==c3 && a3=='X') return 1;
    //lines 0
    if (a1==a2 && a2==a3 && a1=='0') return 2;
    if (b1==b2 && b2==b3 && b1=='0') return 2;
    if (c1==c2 && c2==c3 && c1=='0') return 2;
    //diagonals 0
    if (a1==b2 && b2==c3 && a1=='0') return 2;
    if (a3==b2 && b2==c1 && a3=='0') return 2;
    //columns 0
    if (a1==b1 && b1==c1 && a1=='0') return 2;
    if (a2==b2 && b2==c2 && a2=='0') return 2;
    if (a3==b3 && b3==c3 && a3=='0') return 2;
    //final turn condition
    if (turncount==9) return -1;

    return 0;
}