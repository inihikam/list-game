#include "pustaka.h"

int main(){

    string namaGame;
    int choose, tahun;
    do{
        system("cls");
        cout << endl;
        cout << " =============================" << endl;
        cout << " =     PROGRAM LIST GAME     =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Insert Game            =" << endl;
        cout << " = 2. Delete Game            =" << endl;
        cout << " = 3. Show Game              =" << endl;
        cout << " = 4. Exit Program           =" << endl;
        cout << " =============================" << endl;
        cout << " Pilihan : ";
        cin >> choose;

        switch (choose){
            case 1 : system("cls");{
                cout << "Masukkan nama game : ";
                cin.ignore();
                getline(cin, namaGame);
                cout << "Masukkan tahun rilis game : ";
                cin >> tahun;
                insertData(namaGame, tahun);
                getch();
                break;
            }
            case 2 : system("cls");{
                if (isEmpty()){
                    cout << "Maaf list kosong!\n";
                } else {
                    delData();
                }
                
                getch();
                break;
            }
            case 3 : system("cls");{
                showData();
                getch();
                break;
            }
            case 4 : system("cls");{
                return 0;
                break;
            }
            
            default : system("cls");{
                cout << "Maaf pilihan tidak ada!\n";
                getch();
                break;
            }
        }
    } while (choose != 4);
    


    return 0;
}