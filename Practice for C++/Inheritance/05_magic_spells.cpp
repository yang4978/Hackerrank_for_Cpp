//https://www.hackerrank.com/challenges/magic-spells/problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
  if (spell->revealScrollName()!=""){
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::journal;
        int l1 = s1.size();
        int l2 = s2.size();
        int chess[l1+1][l2+1];

        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0 || j==0){
                    chess[i][j] = 0;
                }
                else if(s1[i-1]==s2[j-1]){
                    chess[i][j] = chess[i-1][j-1]+1;
                }
                else{
                    chess[i][j] = max(chess[i-1][j],chess[i][j-1]);
                }
            }
        }
        cout<<chess[l1][l2]<<endl;
    }

    else{
        
        if(Fireball *fire_temp = dynamic_cast<Fireball*> (spell)){
            fire_temp->revealFirepower();
            delete fire_temp;
        }

        else if (Frostbite *frost_temp = dynamic_cast<Frostbite *>(spell)) {
          frost_temp->revealFrostpower();
          delete frost_temp;
        }

        else if (Waterbolt *water_temp = dynamic_cast<Waterbolt *>(spell)) {
          water_temp->revealWaterpower();
          delete water_temp;
        }

        else if(Thunderstorm *thunder_temp = dynamic_cast<Thunderstorm*> (spell)){
            thunder_temp->revealThunderpower();
            delete thunder_temp;
        }
    }
    

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
