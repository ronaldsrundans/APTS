#include <iostream>
#include <fstream>

using namespace std;

int new_dog_id = 100000;

struct elem{
    int data;
    elem *next;
};

class Stack{
public:
    elem *s, *b;
    Stack() { s = NULL; };
    ~Stack() {
        while (s != NULL) {
            elem *tmp = s;
            s = s->next;
            delete tmp;
        }
    };
    bool is_empty() {
        if (s == NULL) return true;
        return false;
    };
    void push( int a){
        elem *tmp = new elem;
        tmp->data = a;
        tmp->next = NULL;
        if (s == NULL) {
            s = b = tmp;
        } else {
            b->next = tmp;
            b = tmp;
        }
    };
     int pop(){
        if (s==NULL) return 0;
        int a;
        a = s->data;
        elem *tmp = s;
        s = s->next;
        delete tmp;
        return a;
    }
};

struct suns {
    char vards[52];
    int id;
    bool dead;
    suns *mate, *tevs, *next;
};

class Suns {
public:
    suns *oldFirst, *oldLast, *newFirst, *newLast;
    Suns(){
        oldFirst = NULL;
        oldLast = NULL;
        newFirst = NULL;
        newLast = NULL;
    };
    suns* ret_new_dog( int id) {
        suns *tmp = NULL;
        if (id <= 99999) tmp = oldFirst;
        if (id >= 100000 && id <= 120000) tmp = newFirst;

        while (tmp != NULL) {
            if (tmp->id == id) {
                return tmp;
            }
            tmp = tmp->next;
        }
        return NULL;
    };

    bool check_new_space(){ return (new_dog_id >= 100000 && new_dog_id <= 120000); };
    bool dog_exists( int id){
        suns *tmp = NULL;
        if (id <= 99999) {
            tmp = oldFirst;
        } else if (id >= 100000 && id <= 120000){
            tmp = newFirst;
        }
        while (tmp != NULL) {
            if (tmp->id == id) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    };

    int get_name_size(char *string){
        int length;
        for (length=0; *string!='\0'; string++){ length++; }
        return length;
    };

    void register_old(int id, ifstream &in, ofstream &out){
        if (id <= 99999){
            char pedina;
            if (dog_exists(id) == false) {
                suns *jauns = new suns;
                jauns->id = id;
                jauns->mate = NULL;
                jauns->tevs = NULL;
                jauns->next = NULL;
                jauns->dead = false;

                in >> pedina;
                in.get(pedina);

                for (int i=0; i < 51; i++){
                    jauns->vards[i] = '\0';
                }
                for (int i=0; pedina!='"'; i++){
                    jauns->vards[i] = pedina;
                    in.get(pedina);
                }
                if (oldFirst == NULL) {
                    oldFirst = jauns;
                    oldLast = jauns;
                } else {
                    oldLast->next = jauns;
                    oldLast = jauns;
                }
                out << "ok" << endl;
            } else {
                out << "no" << endl;
                while (pedina != '\n') in.get(pedina);
            }
        }
    };

    bool if_name_belongs(char* vecaks, char* jaunais, int &poz){
        int pozicija = poz;
        int flag=1;
        int i, foundPos = 0;
        while (jaunais[foundPos]!='\0') {
            if (jaunais[foundPos]==vecaks[pozicija]) {
                i = 1;
                while((jaunais[i+foundPos]!=' ' && jaunais[i+foundPos]!='\0') || (vecaks[i+pozicija]!=' ' && vecaks[i+pozicija]!='\0')) {
                    if (jaunais[i+foundPos]==vecaks[i+pozicija]) {
                        i++;
                        flag=1;
                    } else {
                        flag=0;
                        break;
                    }
                }
                if (flag == 0) {
                    while (jaunais[foundPos]!=' ' && jaunais[foundPos]!='\0') {
                        foundPos++;
                    }
                } else {
                    poz += i+1;
                    return true;
                }
            } else {
                while (1) {
                    if (jaunais[foundPos] == ' ' || jaunais[foundPos] == '\0') {
                        break;
                    }
                    foundPos++;
                }
                foundPos++;
            }
        }
        while (vecaks[poz]!=' ' && vecaks[poz]!='\0') {
            poz++;
        }
        poz++;
        return false;
    }

    void register_new(char* vards, ofstream &out, suns *mate=NULL, suns *tevs=NULL){
        if (new_dog_id <= 120000) {
            suns *jauns = new suns;
            jauns->id = new_dog_id;

            for ( int i=0; vards[i]!='\0'; i++){
                jauns->vards[i] = vards[i];
                jauns->vards[i+1]='\0';
            }
            int tmp_garums=get_name_size(jauns->vards);
            jauns->mate = mate;
            jauns->tevs = tevs;
            jauns->next = NULL;
            jauns->dead = false;

            char* mates_vards = mate->vards;
            char* teva_vards = tevs->vards;

            int mgar, tgar;

            if (mate == NULL) {
                mgar = 0;
            }else{
                mgar = get_name_size(mates_vards);
            }
            if (tevs == NULL) {
                tgar = 0;
            } else {
                tgar = get_name_size(teva_vards);
            }
            if (newFirst == NULL) {
                newFirst = jauns;
                newLast = jauns;
            } else {
                newLast->next = jauns;
                newLast = jauns;
            }
            new_dog_id++;

            int mpoz=0, tpoz=0;
            int sledzis = 1, tmp_poz;
            while (mpoz < mgar || tpoz < tgar) {
                if (sledzis == 1) {
                    if (mpoz < mgar) {
                        tmp_poz = mpoz;
                        if (if_name_belongs(mates_vards, jauns->vards, tmp_poz) == true) {
                            mpoz = tmp_poz;
                            continue;
                        } else {
                            if (tmp_garums+tmp_poz-mpoz <= 51) {
                                jauns->vards[tmp_garums++] = ' ';
                                while (mpoz != tmp_poz-1) {
                                    jauns->vards[tmp_garums++] = mates_vards[mpoz++];
                                    jauns->vards[tmp_garums] = '\0';
                                }
                                mpoz++;
                                sledzis = 0;
                            } else {
                                continue;
                            }
                        }
                    }
                    sledzis = 0;
                } else {
                    if (tpoz < tgar) {
                        tmp_poz = tpoz;
                        if (if_name_belongs(teva_vards, jauns->vards, tmp_poz) == true) {
                            tpoz = tmp_poz;
                            continue;
                        } else {
                            if (tmp_garums+tmp_poz-tpoz-1 <= 51) {
                                jauns->vards[tmp_garums++] = ' ';
                                while (tpoz != tmp_poz-1) {
                                    jauns->vards[tmp_garums++] = teva_vards[tpoz++];
                                    jauns->vards[tmp_garums] = '\0';
                                }
                                tpoz++;
                                sledzis = 1;
                            } else {
                                continue;
                            }
                        }
                    }
                    sledzis = 1;
                }
            }
            out << jauns->id << " " << '"' << jauns->vards << '"' << endl;
        } else return;
    };

    void set_dead(int id, ofstream &out){
        suns *tmp = NULL;
        if (id <= 99999) {
            tmp = oldFirst;
        } else if (id >= 100000 && id <= 120000){
            tmp = newFirst;
        }
        if (tmp != NULL) {
            while (tmp != NULL) {
                if (tmp->id == id) {
                    tmp->dead = true;
                    out << "ok" << endl;
                    return;
                }
                tmp = tmp->next;
            }
        }
        out << "no" << endl;
    };

    int inStr(char *pattern, char *str) {
        int i, foundPos = 0;
        while(str[foundPos]!=0) {
            if (str[foundPos]==pattern[0]) {
                i = 1;
                while(pattern[i]!=0 && str[foundPos+i]!=0 && str[foundPos+i]==pattern[i]) { i++; }
                if (pattern[i]==0 && (str[foundPos+i]==' ' || str[foundPos+i]=='\0')) {
                    return foundPos;
                } else if (str[foundPos+i]==0) {
                    return -1;
                }
            }
            foundPos++;
        }
        return -1;
    }

    void find_dog(char vards[51], ofstream &out){
        int skaits = 0;
        suns *tmp = oldFirst;
        int poz;
        Stack st;
        while (tmp != NULL) {
            poz = inStr(vards, tmp->vards);
            if (poz != -1) {
                skaits++;
                st.push(tmp->id);
            }
            tmp = tmp->next;
        }
        tmp = newFirst;
        while (tmp != NULL) {
            poz = inStr(vards, tmp->vards);
            if (poz != -1) {
                skaits++;
                st.push(tmp->id);
            }
            tmp = tmp->next;
        }
        int vert;
        out << skaits << " ";
        if (skaits != 0) {
            if (st.is_empty() == false) {
                while (st.is_empty() == false) {
                    vert = st.pop();
                    out << vert << " ";
                }
                out << endl;
            }
        } else out << endl;

    };

    void get_dog_name(int id, ofstream &out){
        suns *tmp = NULL;
        if (id <= 99999) {
            tmp = oldFirst;
        } else if (id >= 100000 && id <= 120000){
            tmp = newFirst;
        }
        while (tmp != NULL) {
            if (tmp->id == id) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            if (tmp->dead == false) {
                out << '"' << tmp->vards << '"' << endl;
            } else {
                out << "dead - " << '"' << tmp->vards << '"' << endl;
            }
        } else {
            out << "no" << endl;
        }
    };
};

int main()
{
    ifstream inFile("suns.in", ios::in);
    ofstream outFile("suns.out", ios::out);
    Suns s;
    char darbiba;
     int id;
    char vards[52];
    for ( int i=0; i<=51; i++){
        vards[i] = '\0';
    }
    inFile >> darbiba;
    while (darbiba != 'Q') {
        switch (darbiba) {
            case 'R':
            {
                inFile >> id;
                s.register_old(id, inFile, outFile);
                for ( int i=0; vards[i]!=0; i++){ vards[i] = '\0'; }
            }
                break;
            case 'D':
            {
                inFile >> id;
                s.set_dead(id, outFile);
            }
                break;
            case 'F':
            {
                inFile >> vards;
                s.find_dog(vards, outFile);
                for ( int i=0; vards[i]!=0; i++){ vards[i] = '\0'; }
            }
                break;
            case 'I':
            {
                inFile >> id;
                s.get_dog_name(id, outFile);
            }
                break;
            case 'N':
            {
                int mate, tevs, skaits;
                inFile >> mate >> tevs >> skaits;

                suns *mother = s.ret_new_dog(mate);
                suns *father = s.ret_new_dog(tevs);
                if ((mother==NULL && mate!=0) || (father==NULL && tevs!=0)) {
                    outFile << "no" << endl;
                    break;
                }
                for (int i=0; i<skaits; i++) {
                    inFile >> vards;
                    s.register_new(vards, outFile, mother, father);
                    for (int i=0; vards[i]!=0; i++){ vards[i] = '\0'; }
                }
            }
                break;
            default: break;
        };
        inFile >> darbiba;
    }
    outFile << "quit";
    inFile.close();
    outFile.close();
    return 0;
}
