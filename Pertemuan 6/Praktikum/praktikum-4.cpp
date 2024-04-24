#include<iostream>
#include<string>
using namespace std;

class karyawan{
    private:
        long int gaji;
        string nama;
        int umur;
    public:
        void setgaji(long int x){
            gaji = x;
        }
        
        void setnama(string y){
            nama = y;
        }
        
        void setumur(int z){
            umur = z;
        }
        
        long int getgaji(){
            return gaji;
        }
        
        string getnama(){
            return nama;
        }
        
        int getumur(){
            return umur;
        }   
};

int main(){
    karyawan ky;
    
    int umur;
    long int gaji;
    string nama;
    cout<<"Masukkan nama karyawan: ";
    getline(cin, nama);
    cout<<"Masukkan gaji karyawan: ";
    cin>>gaji;
    cout<<"Masukkan usia karyawan: ";
    cin>>umur;
    ky.setnama(nama);
    ky.setgaji(gaji);
    ky.setumur(umur);
    
    cout<<"Nama: "<<ky.getnama()<<endl;
    cout<<"Gaji: "<<ky.getgaji()<<endl; // Mengatur jumlah desimal menjadi 2
    cout<<"Umur: "<<ky.getumur()<<endl;
    
    return 0;   
}

