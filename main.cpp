#include <iostream>
#include "list.h"
#include "operation.h"
#include "my_data.h"


using namespace std;

void mainMenu();
List L, L_passed;

int main() {
    createList(L);
    createList(L_passed);

    mainMenu();

    return 0;
}

void mainMenu() {
    address P;
    infotype x;
    /**
    * IS : List has been created
    * PR : prints menu to user
    *       1. insert new data
    *       2. print all data (List L)
    *       3. find and print a data by ID
    *       4. edit data by ID
    *       5. delete data by ID
    *       6. separate passed member
    *       7. print all data (List L2)
    *       0. exit
    */
    //-------------your code here-------------
    int choice;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. view member"<<endl;
        cout<<"3. find and view"<<endl;
        cout<<"4. find and edit"<<endl;
        cout<<"5. find and delete"<<endl;
        cout<<"6. separate passed member"<<endl;
        cout<<"7. view passed member"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        switch(choice) {
        case 1:
            {
                x = create_data();
                P = allocate(x);
                insertFirst(L,P);
                break;
            }
        case 2 :
            {
                printInfo(L);
                break;
            }
        case 3 :
            {
                cout<<"ID yang dicari :";
                cin>> x.ID;
                address temu ;
                temu = findElm(L,x);
                if ( temu != NULL)
                {
                    view_data(info(P));
                }
                else
                {
                    cout<<"Maaf data tidak ditemukan"<<endl;
                }
                break;
            }
        case 4 :
            {
                cout<<"ID yang akan diedit :";
                cin>> x.ID;
                address ubah;
                ubah = findElm(L,x);
                if ( ubah != NULL)
                {
                    edit_data(info(P));
                }
                else
                {
                    cout<<"Maaf ID anda tidak dapat diedit."<<endl;
                }
                break;
            }
        case 5 :
            {
                infotype a;
                address cari;
                cari  = findElm(L, a);
                cout<"Mencari ID : ";
                cin>>a.ID;
                if ( cari == first(L))
                {
                    deleteFirst(L,cari);
                }
                else if ( cari == last(L))
                {
                    deleteLast(L, cari);
                }
                else
                {
                    deleteAfter(L, prev(cari), cari);
                }
                cout<<"Penghapusan Berhasil";
                break;
            }
        case 6 :
            {
                savePassedMember(L,L_passed);
                break;
            }
        case 7 :
            {
                printInfo(L_passed);
                break;
            }
        }
        if (choice == 0)
        {
            break;
        }
    } while(true);

    //----------------------------------------
}
