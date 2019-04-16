/*
Nama Program : Exercise-01
Nama : Sharashena Chairani
Kelas : B
NPM : 140810180022
*/

#include <iostream>

using namespace std;

struct Node{
    char info;
    Node* next;
};
typedef Node* pointer;
typedef pointer List;

void CreateList(List& First){
    First = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new Node;
    cout << "Masukkan data : "; cin >> pBaru->info;
    pBaru->next = NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
        First=pBaru;
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast(List& First, pointer pBaru){
    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus"<< endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    if(First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus" << endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=last;
        while(last->next!=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}

void traversal(List First){
    cout << "Tampilkan : ";
    pointer pBantu;
    if(First==NULL){
        cout << "List Kosong";
    }
    else{
        pBantu=First;
        do{
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}

int main()
{
    pointer p;
    List xn10;
    int menu;

    CreateList(xn10);

    do{
        system("cls");
        cout<<"--Tampilan Menu--"<<endl;
        cout<<"1. Insert First!"<<endl;
        cout<<"2. Insert Last!"<<endl;
        cout<<"3. Delete First!"<<endl;
        cout<<"4. Delete Last!"<<endl;
        cout<<"5. Traversal!"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"------------------"<<endl;
        cout << "Choose Menu : "; cin >> menu;
        switch(menu){
        case 1:
            CreateElement(p);
            insertFirst(xn10, p);
        break;

        case 2:
            CreateElement(p);
            insertLast(xn10,p);
        break;

        case 3:
            deleteFirst(xn10,p);
        break;

        case 4:
            deleteLast(xn10,p);
        break;

        case 5:
            traversal(xn10);
        break;
        default :
            exit(0);
        }
        system("pause");
    }while(menu!=6);
}
