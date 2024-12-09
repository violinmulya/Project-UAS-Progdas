#include <iostream> // Untuk input dan output data
#include <string>   // Untuk menggunakan tipe data string
using namespace std; // Supaya tidak perlu menulis "std::" sebelum fungsi standar

class Pengguna {
private:
    string username;     // Untuk menyimpan username pengguna
    string password;     // Untuk menyimpan password pengguna
    string nama;         // Untuk menyimpan nama pengguna
    string email;        // Untuk menyimpan email pengguna
    string noHP;         // Untuk menyimpan nomor HP pengguna

public:
    // Fungsi untuk mendaftarkan pengguna (register)
    void daftarPengguna() {
        cout << "Masukkan username Anda: ";
        cin >> username; // Input username
        cout << "Masukkan password Anda: ";
        cin >> password; // Input password
        cout << "Masukkan nama Anda: ";
        cin.ignore(); // Menghindari masalah dengan getline setelah cin
        getline(cin, nama); // Input nama pengguna
        cout << "Masukkan email Anda: ";
        getline(cin, email); // Input email pengguna
        cout << "Masukkan nomor HP Anda: ";
        getline(cin, noHP); // Input nomor HP pengguna
        cout << "Pendaftaran berhasil!\n\n";
    }

    // Fungsi untuk login pengguna
    bool login() {
        string inputUsername, inputPassword;
        // Username dan password yang valid
        string validUsername = "zahraelfa";
        string validPassword = "kerenbanget45";

        cout << "Masukkan username: ";
        cin >> inputUsername; // Input username
        cout << "Masukkan password: ";
        cin >> inputPassword; // Input password

        // Memeriksa apakah username dan password sesuai dengan yang valid
        if (inputUsername == validUsername && inputPassword == validPassword) {
            return true; // Login berhasil
        } else {
            cout << "Username atau password salah!\n";
            return false; // Login gagal
        }
    }

    // Fungsi untuk logout
    void logout() {
        cout << "Anda telah berhasil logout.\n";
    }
};

class LayananLaundry {
private:
    string jenisLayanan;  // Untuk menyimpan jenis layanan laundry
    float hargaPerKg;     // Untuk menyimpan harga per kg laundry
    float berat;          // Untuk menyimpan berat laundry
    bool statusPembayaran; // Untuk memeriksa apakah pembayaran sudah cukup
    float total;          // Total biaya laundry
    string ulasan;        // Ulasan dari pengguna    
    int rating;           // Rating dari pengguna

public:
    LayananLaundry() {
        hargaPerKg = 5000; // Set harga per kg sebesar 5000
    }

    // Fungsi untuk menambah layanan laundry
    void tambahLayanan() {
        // Input jenis layanan laundry
        cout << "Jenis layanan laundry (cuci kering, cuci setrika, dll): ";
        cin.ignore();            // Membersihkan input buffer
        getline(cin, jenisLayanan); // Input jenis layanan laundry
        cout << "Masukkan berat laundry (kg): ";
        cin >> berat;             // Input berat laundry
    }

    // Fungsi untuk menghitung total biaya
    float hitungTotal() {
        total = berat * hargaPerKg; // Menghitung total biaya
        return total;
    }

    // Fungsi untuk verifikasi pembayaran
    bool verifikasiPembayaran(float pembayaran, string metodePembayaran) {
        if (pembayaran >= total) {
            statusPembayaran = true;
            return true; // Pembayaran berhasil
        } else {
            statusPembayaran = false;
            return false; // Pembayaran gagal
        }
    }

    // Fungsi untuk menampilkan status pembayaran
    void tampilkanStatusPembayaran(float pembayaran) {
        if (statusPembayaran) {
            float kembalian = pembayaran - total; // Hitung kembalian
            if (kembalian > 0) {
                cout << "Pembayaran berhasil! Kembalian Anda: Rp" << kembalian << "\n";
            } else {
                cout << "Pembayaran berhasil! Tidak ada kembalian.\n";
            }
        } else {  cout << "Pembayaran tidak cukup. Total biaya: Rp" << total << ", Anda membayar: Rp" << pembayaran << "\n";
        }
    }

    // Fungsi untuk menampilkan status pesanan
    void tampilkanStatusPesanan() {
        if (statusPembayaran) {
            cout << "Status pesanan: Dalam Proses\n";
        } else {
            cout << "Status pesanan: Belum Dikonfirmasi\n";
        }
    }
// Fungsi untuk memberikan rating dan ulasan
    void beriRatingDanUlasan() {
        if (statusPembayaran) {
            cout << "Masukkan rating (1-5): ";    
            cin >> rating; // Input rating
            cin.ignore(); // Menghindari masalah dengan getline setelah cin
            cout << "Masukkan ulasan Anda: ";
            getline(cin, ulasan); // Input ulasan

            // Menampilkan ulasan dan rating yang diberikan
            cout << "\nTerima kasih atas ulasan Anda!\n";
            cout << "Rating: " << rating << "/5\n";
            cout << "Ulasan: " << ulasan << "\n";
        } else {
            cout << "Anda belum melakukan pembayaran. Tidak bisa memberikan ulasan.\n";
        }
    }
};

int main() {
    Pengguna pengguna1;        // Membuat objek pengguna
    LayananLaundry laundry1;   // Membuat objek layanan laundry
    bool loggedIn = false;     // Status login
    int pilihan;               // Pilihan menu untuk pengguna

    cout << "=== Aplikasi Laundry ===\n\n";

    // Menu login dan register
    while (!loggedIn) {
        cout << "1. Login\n";
        cout << "2. Daftar\n";
        cout << "3. Keluar\n"; // Menambahkan pilihan untuk keluar
        cout << "Masukkan pilihan (1, 2, atau 3): ";
        cin >> pilihan;

        if (pilihan == 1) {
            loggedIn = pengguna1.login(); // Cek login
        } else if (pilihan == 2) {
            pengguna1.daftarPengguna(); // Daftar pengguna baru
            loggedIn = true; // Secara otomatis login setelah daftar
        } else if (pilihan == 3) {
            cout << "Terima kasih! Sampai jumpa.\n";
            return 0; // Keluar dari aplikasi
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    // Pilih layanan laundry
    cout << "=== Pemesanan Layanan Laundry ===\n";
    laundry1.tambahLayanan(); // Menambahkan layanan

    // Hitung total biaya
    float totalBiaya = laundry1.hitungTotal();
    cout << "Total biaya laundry: Rp" << totalBiaya << "\n";

    // Pembayaran
    string metodePembayaran;
    float pembayaran;
    cout << "Pilih metode pembayaran (transfer/tunai): ";
    cin >> metodePembayaran; // Input metode pembayaran

    cout << "Masukkan jumlah pembayaran: Rp";
    cin >> pembayaran; // Input jumlah pembayaran

    // Verifikasi pembayaran
    if (laundry1.verifikasiPembayaran(pembayaran, metodePembayaran)) {
        laundry1.tampilkanStatusPembayaran(pembayaran); // Tampilkan jika berhasil
    } else {
        laundry1.tampilkanStatusPembayaran(pembayaran); // Tampilkan jika gagal
    }

    // Tampilkan status pesanan
    laundry1.tampilkanStatusPesanan();

    // Memberikan rating dan ulasan setelah pesanan selesai
    laundry1.beriRatingDanUlasan();

    // Menambahkan opsi logout setelah selesai
    pengguna1.logout();

    return 0; // Program selesai
}