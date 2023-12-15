int main () {

    srand (static_cast<unsigned int>(time(nullptr)));

    int angka_rahasia = rand () %100 + 1;
    int tebakan;
    int jumlah_tebakan;

    cout<<"SELAMAT DATANG DI TEBAK MENEBAK ANGKA"<<endl;
    cout<<"Hayo tebak hayo dari 1-100"<<endl;

    while(true) {
    cout<<"Masukan Tebakan Anda : ";
    cin>> tebakan;jumlah_tebakan++;

    if (tebakan < angka_rahasia){
        cout<<"Tebakan Anda Terlalu Kecil.Coba Lagi."<<endl;
    }

    else if (tebakan > angka_rahasia){
        cout<<"Tebakan Anda Terlalu Besar.Coba Lagi."<<endl;
    }

    else {
        cout<<"SELAMAT!!! Anda Menebak Anga Dengan Benar ("<<angka_rahasia<<") dalam "<<jumlah_tebakan<<" kali tebakan"<<endl;
        break;
    }
    }
    
    cout<<"Terima Kasih Telah Bermain"<<endl;

}