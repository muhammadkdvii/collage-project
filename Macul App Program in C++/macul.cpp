#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class belanja
{
private:
    int kp;
    float harga;
    float dis;
    string np;

public:
    void masuk();
    void login();
    void registrasi();
    void menu();
    void jual();
    void beli();
    void tambah();
    void edu();
    void kom();
    void edit();
    void hapus();
    void list();
    void struk();
};



int main()
{
    belanja s;
    s.masuk();
    s.menu();
}

void belanja::masuk()
{

char konfirmasi;

    cout << "\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|-----------                        -----------|\n";
    cout << "\t\t\t\t|-----------    WELCOME TO MACUL    -----------|\n";
    cout << "\t\t\t\t|-----------                        -----------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    
    bool validInput = false;

    while (!validInput)
    {
        cout << "\n\t\t\t\t|Sudah Punya Akun? (y/n) : ";
        cin >> konfirmasi;

        if (konfirmasi == 'y')
        {
            validInput = true;
            login();
        }
        else if (konfirmasi == 'n')
        {
            validInput = true;
            registrasi();
            cout << "\n\t\t\t\tSelamat Registrasi Berhasil";
        }
        else
        {
            cout << "\n\t\t\t\tInput tidak valid. Silakan masukkan 'y' atau 'n'."<<endl;
            
        }
    }

    system("cls");
}


void belanja::login ()
{
    int count;
    string username,password,id,pass;
    system ("cls");
    cout << "\n\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t|***********************************************|\n";
    cout << "\t\t\t\t|                    LOGIN MENU                 |\n";
    cout << "\t\t\t\t|***********************************************|\n";
    cout << "\t\t\t\t| USERNAME: ";
    cin >> username;
    cout << "\t\t\t\t| PASSWORD: ";
    cin >> password;

    ifstream input("DatabaseAkun.txt");
    
    while(input>>id>>pass)
    {
        if(id==username && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
        cout<<username<<"\n\t\t\t\tSELAMAT ANDA BERHASIL LOGIN!";
        void menu();
    }

    else
    {
        cout <<"\n\t\t\t\tLOGIN EROR 404";
        masuk();
    }
}

void belanja::registrasi()
{
  string rAkun,rUsername,rPassword,akun,rid,rpass ;
  system ("cls");
  
  cout << "\n\t\t\t\t________________________________________________\n";
  cout << "\t\t\t\t|***********************************************|\n";
  cout << "\t\t\t\t|                REGISTRATION MENU              |\n";
  cout << "\t\t\t\t|***********************************************|\n";
  cout << "\t\t\t\t| MASUKAN AKUN ANDA: ";
  cin >> rAkun;
  cout << "\t\t\t\t| MASUKAN USERNAME: ";
  cin >> rUsername;
  cout << "\t\t\t\t| MASUKAN PASSWORD: ";
  cin >> rPassword;

  ofstream f1("DatabaseAkun.txt",ios::app);
  f1<<rAkun<< ' ' << rUsername << ' ' << rPassword <<endl;
  system("cls");
  
  main();

}

void belanja::menu()
{
    int pilih;
    string username;
    string pass;

    cout << "\n\n\t\t\t\t________________________________________________\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|-----------                        -----------|\n";
    cout << "\t\t\t\t|-----------    WELCOME TO MACUL    -----------|\n";
    cout << "\t\t\t\t|-----------                        -----------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|-----   1.JUAL SUMBER DAYA         -----------|\n";
    cout << "\t\t\t\t|-----   2.BELI SUMBER DAYA         -----------|\n";
    cout << "\t\t\t\t|-----   3.EDUKASI                  -----------|\n";
    cout << "\t\t\t\t|-----   4.KOMUNITAS                -----------|\n";
    cout << "\t\t\t\t|-----   0.KELUAR                   -----------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|----------------------------------------------|\n";
    cout << "\t\t\t\t|______________________________________________|\n";
    cout << "\t\t\t\t|Silahkan pilih Menu : ";
    cin >> pilih;

    if (pilih == 1)
    {
        jual();
    }

    else if (pilih == 2){
         beli();
    }

    else if (pilih == 3){
         edu();
    }

    else if (pilih == 4){
         kom();
    }

    else if (pilih == 0){
        cout << "\n\n\n\t\t\t\t  TERIMA KASIH TELAH MENGGUNAKAN APLIKASIH KAMI            "<<endl;
        cout << "\t\t\tJika Anda Puas Beritahu Petani Lainnya, Jika Anda Kecewa Beritahu Kami.\n\n\n";;
    }
   
}

void belanja::jual()
{
   
        int pilih;
        

            cout << "\n\t\t\t\t________________________________________\n";
            cout << "\t\t\t\t|--------------------------------------|\n";
            cout << "\t\t\t\t|-----    JUAL SUMBER DAYA ANDA   -----|\n";
            cout << "\t\t\t\t|--------------------------------------|\n";
            cout << "\t\t\t\t|--------------------------------------|\n";
            cout << "\t\t\t\t|----   1).Tambahkan Produk        ----|\n";
            cout << "\t\t\t\t|----   2).Edit Produk             ----|\n";
            cout << "\t\t\t\t|----   3).Hapus Produk            ----|\n";
            cout << "\t\t\t\t|----   4).Kembali ke Menu         ----|\n";
            cout << "\t\t\t\t|--------------------------------------|\n";
            cout << "\t\t\t\t|--------------------------------------|\n";
            cout << "\t\t\t\t|Silahkan Pilih Menu: ";
            cin >> pilih;

            if (pilih == 1)
            {
                tambah();
            }

            else if (pilih == 2)
            {
                edit();
            }

            else if (pilih == 3)
            {
                hapus();
            }

            else if (pilih == 4)
            {
                menu();
            }

            else
                {
                    cout << "\n\t\t\t\tUsername/Password salah, silahkan coba lagi.";
                }
}

void belanja:: beli()
{
    int pilih;
    cout << "\n\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t|-------    BELI SUMBER DAYA    -------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|----    1).Beli Produk            ----|\n";
    cout << "\t\t\t\t|----    2).kembali                ----|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|______________________________________|\n";
    cout << "\t\t\t\tPilih Menu: ";
    cin >> pilih;

    if (pilih == 1){
        struk();
    }

    if (pilih == 2){
        menu();
    }
} 

void belanja::tambah()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t|          TAMBAH PRODUK BARU          |\n";
    cout << "\t\t\t\t________________________________________\n";
    cout << "\t\t\t\tKode Produk: ";
    cin >> kp;
    cout << "\t\t\t\tNama Produk: ";
    cin >> np;
    cout << "\t\t\t\tHarga Produk: ";
    cin >> harga;
    cout << "\t\t\t\tDiskon: ";
    cin >> dis;

    data.open("database.txt",ios::in);

        if (!data)
        {
            data.open("database.txt", ios::app|ios::out);
            data<<""<<kp<<""<<np<<""<<harga<<""<<dis<<"\n";
            data.close();
        }

        else
        {
            data>>c>>n>>p>>d;

            while(!data.eof())
            {
                if(c ==kp)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();
        }
    
    if(token==1)
        goto m;
    else
    {
         data.open("database.txt", ios::app|ios::out);
            data<<" "<<kp<<" "<<np<<" "<<harga<<" "<<dis<<"\n";
            data.close();
    }

    cout <<"\n\n\t\t\t\t Terekam!";
    jual();

}

void belanja::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t|             EDIT PRODUK              |\n";
    cout << "\t\t\t\t________________________________________\n";
    cout << "\t\t\t\tKode Produk: ";
    cin >> pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout << "\t\t\t\tFile tidak ditemukan";
    }

    else {
        data>>kp>>np>>harga>>dis;
        
        while(data.eof())
        {
                if(pkey==kp)
                {
                cout << "\n\t\t\t\t_______________________________________\n";
                cout << "\t\t\t\tKode Baru Produk: ";
                cin >> c;
                cout << "\t\t\t\tNama Produk: ";
                cin >> n;
                cout << "\t\t\t\tHarga: ";
                cin >> p;
                cout << "\t\t\t\t_______________________________________\n";

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout << "\t\t\t\tBerhasil Mengubah";
                token++;
                }

            else
            {
                data1<<" "<<kp<<" "<<np<<" "<<harga<<" "<<dis<<"\n";
            }

            data>>kp>>np>>harga>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token==0)
        {
            cout<<"\t\t\t\tMaaf Tidak Ditemukan";
        }
   }  
}

void belanja::hapus()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout << "\n\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t             HAPUS PRODUK                \n";
    cout << "\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\tKode Produk: ";
    cin >> pkey;
   
    data.open("database.txt",ios::in);
    
    if (!data)
    {
        cout<<"\t\t\t\tfile tidak ditemukan";
    }

    else
    {
        data1.open("database.txt",ios::app|ios::out);
        data>>kp>>np>>harga>>dis;
        while(!data.eof())
        {
            if(kp==pkey)
            {
                cout <<"\t\t\t\tProduk Berhasil di Hapus";
                token++;
            }
            else{
                data1<<" "<<kp<<" "<<np<<" "<<harga<<" "<<dis<<"\n";
            }
            data>>kp>>np>>harga>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\t\t\t\tMaaf Tidak di temukan";
        }
    }

}

void belanja::list()
{
    fstream data;
    data.open("database.txt",ios::in);

    
     data>>kp>>np>>harga>>dis;

     while(!data.eof())
     {

        cout<<"\t\t\t\t"<<kp<<"\t"<<np<<"\t"<<harga<<"\n";
        data>>kp>>np>>harga>>dis;

     }
     data.close();
}

void belanja::struk()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    string pilih;
    int c=0;
    float jumlah=0;
    float dis=0;
    float total=0;

    cout << "\n\n\t\t\t\t__________________________________________\n";
    cout <<"\t\t\t\t                  STOK PRODUK                  \n";
    cout << "\t\t\t\t__________________________________________\n";

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\t\t\t\tStok Kosong";
        cout << "\n\n\t\t\t\t__________________________________________\n";
    }

    else
    {
        data.close();

        list();
         cout << "\n\n\n\t\t\t\t__________________________________________\n";
         cout <<"\t\t\t\t           silakan lakukan pemesanan       \n";
         cout << "\t\t\t\t__________________________________________\n";
         
         do
         {
            m:
            cout<<"\t\t\t\tMasukan Kode Produk: ";
            cin>>arrc[c];
            cout<<"\t\t\t\tMasukan Jumlah Produk: ";
            cin>>arrq[c];

            for(int i=0; i<c ; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\t\t\t\tKode Yang sama.Silahkan Coba Lagi";

                    goto m;
                }
            }
            c++;
            cout<<"\t\t\t\tApakah Mau Beli Produk Lainnya? (y/n) : ";
            cin>>pilih;
            cout << "\t\t\t\t__________________________________________\n";
         }
         while(pilih=="y");
         cout << "\n\n\t\t\t\t________________________________________________\n";
         cout <<"\t\t\t\t                  RINCIAN BELANJA                \n";
         cout << "\t\t\t\t________________________________________________\n";
         cout << "\t\t\t\t|No| Produk | Banyak | Harga | Jumlah | Diskon |";
         for (int i=0;i<c;i++)
         {
            data.open("database.txt",ios::in);
            data>>kp>>np>>harga>>dis;
            while(!data.eof())
            {
                if(kp==arrc[i])
                {
                    jumlah=harga*arrq[i];
                    dis=jumlah-(jumlah*dis/100);
                    total=total+dis;
                    cout << "\n\t\t\t\t"<<kp<<"\t"<<np<<"\t"<<arrq[i]<<"\t"<<harga<<"\t"<<jumlah<<"\t"<<dis;
                }
                data>>kp>>np>>harga>>dis;
            }
         }
         data.close();
    }

    cout << "\n\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t Total Jumlah : "<<total;
    beli();
   
}

void belanja::edu(){
    int pilih;
    cout << "\n\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t|-------        EDUCATION       -------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|----  1).Cara Merawat Tanaman     ----|\n";
    cout << "\t\t\t\t|----  2).Cara Mengatasi Hama      ----|\n";
    cout << "\t\t\t\t|----  3).Bagaimana Cara Menanam   ----|\n";
    cout << "\t\t\t\t|----  4).Ciri Tanaman tidak Sehat ----|\n";
    cout << "\t\t\t\t|----  5).Tingkatkan Hasil Produksi----|\n";
    cout << "\t\t\t\t|----  0).Kembali                  ----|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|______________________________________|\n";
    cout << "\t\t\t\tPilih Menu: ";
    cin >> pilih;

    if (pilih == 1)
    {
        int kembali;
        cout << "\n\t\t\t\t_______________________________________________________________________________________\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****                 BAGAIMANA SIH CARA MERAWAT TANAMAN AGAR SEHAT               *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****  0.Kembali                                                                  *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
        cout << "\t\t\t\t| ";
        cin >> kembali;

        if (kembali==0)
        {
            edu();
        }
    }

    else if (pilih == 2)
    {
        int kembali;
        cout << "\n\t\t\t\t_______________________________________________________________________________________\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****            MENGATASI HAMA TANAMAN YANG MENGGANGU KESEHATAN TANAMAN          *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****  0.Kembali                                                                  *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
        cout << "\t\t\t\t| ";
        cin >> kembali;

        if (kembali==0)
        {
            edu();
        }
    }

    else if (pilih == 3)
    {
        int kembali;
        cout << "\n\t\t\t\t_______________________________________________________________________________________\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****               BAGAIMANA CARANYA MENANAM YANG BAIK DAN BENAR                 *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****  0.Kembali                                                                  *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
        cout << "\t\t\t\t| ";
        cin >> kembali;

        if (kembali==0)
        {
            edu();
        }
    }

    else if (pilih == 4)
    {
        int kembali;
        cout << "\n\t\t\t\t_______________________________________________________________________________________\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****                     CIRI-CIRI TANAMAN YANG TIDAK SEHAT                      *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****  0.Kembali                                                                  *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
        cout << "\t\t\t\t| ";
        cin >> kembali;

        if (kembali==0)
        {
            edu();
        }
    }

    else if (pilih == 5)
    {
        int kembali;
        cout << "\n\t\t\t\t_______________________________________________________________________________________\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****       BAGAIMAN CARANYA MENINGKATKAN HASIL PRODUKSI PERKEBUNAN KALIAN        *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****         Lorem ipsum dolor sit amet, consectetur adipiscing elit.            *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|*****  0.Kembali                                                                  *****|\n";
        cout << "\t\t\t\t|*****                                                                             *****|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|***************************************************************************************|\n";
        cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
        cout << "\t\t\t\t| ";
        cin >> kembali;

        if (kembali==0)
        {
            edu();
        }
    }

    else if (pilih == 0)
    {
        menu();
    }
}

void belanja::kom()
{
    int kembali;
    string tweets[5];

    tweets[0] = "Aplikasinya bagus banget dan berguna ya bapak bapak,gimana menurut bapak bapak?";
    tweets[1] = "Iya ini bagus banget,mempermudah banget buat pekerjaan kita";
    tweets[2] = "eh pak ini ada ular masuk sawah saya";
    tweets[3] = "Usir aja pak @petani3,bapak kan pawang ular wkkwk";
    tweets[4] = "eh pak barusan saya ke apotek beli obat tidur,pas nyampe rumah saya takut obatnya bangun. ";

    cout<<"\n\n\t\t\t\t_____________________________________________________________________________________________________\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\n\t\t\t\t| @petani " << i + 1 << ": " << tweets[i] <<"\n" << endl;
    }
    cout<<"\n\n\t\t\t\t___________\n";
    cout<<"\t\t\t\t|0.kembali|"<<endl;
    cout<<"\t\t\t\t***********\n";
    cout<<"\t\t\t\t_____________________________________________________________________________________________________\n";
    cout<<"\t\t\t\t";
    cin>>kembali;

    if (kembali==0){
        menu();
    }
}




