#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class untuk Admin
class Admin {
private:
    string adminId;     // ID Admin
    string name;        // Nama Admin
    string email;       // Email Admin
    string username;    // Username Admin
    string password;    // Password Admin

public:
    // Constructor
    Admin(string id, string adminName, string adminEmail, string adminUsername, string adminPassword) {
        adminId = id;
        name = adminName;
        email = adminEmail;
        username = adminUsername;
        password = adminPassword;
    }

    // Fungsi untuk autentikasi login
    bool authenticate(string inputUsername, string inputPassword) {
        if (inputUsername == username && inputPassword == password) {
            return true;
        }
        else {
            return false;
        }
    }

    // Fungsi untuk mengelola data pesanan
    void manageData(vector<string>& orders) {
        cout << "Mengelola Data Pesanan:\n";
        for (size_t i = 0; i < orders.size(); i++) {
            cout << i + 1 << ". " << orders[i] << endl;
        }
    }

    // Fungsi untuk memperbarui status pesanan
    void updateStatus(vector<string>& orders, int orderIndex, string newStatus) {
        if (orderIndex >= 0 && orderIndex < orders.size()) {
            orders[orderIndex] = newStatus;
            cout << "Status pesanan diperbarui menjadi: " << newStatus << endl;
        }
        else {
            cout << "Indeks pesanan tidak valid!" << endl;
        }
    }

    // Fungsi untuk menambahkan pesanan
    void addOrder(vector<string>& orders, string orderDescription) {
        orders.push_back(orderDescription);
        cout << "Pesanan baru berhasil ditambahkan: " << orderDescription << endl;
    }

    // Fungsi untuk menghapus pesanan
    void removeOrder(vector<string>& orders, int orderIndex) {
        if (orderIndex >= 0 && orderIndex < orders.size()) {
            orders.erase(orders.begin() + orderIndex);
            cout << "Pesanan berhasil dihapus." << endl;
        }
        else {
            cout << "Indeks pesanan tidak valid!" << endl;
        }
    }

    // Fungsi untuk mencari pesanan berdasarkan ID
    void searchOrder(const vector<string>& orders, string searchTerm) {
        bool found = false;
        for (size_t i = 0; i < orders.size(); i++) {
            if (orders[i].find(searchTerm) != string::npos) {
                cout << "Pesanan ditemukan: " << orders[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Pesanan dengan kata kunci '" << searchTerm << "' tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk menghasilkan laporan
    void generateReports(const vector<string>& orders) {
        cout << "Laporan Pesanan:\n";
        for (size_t i = 0; i < orders.size(); i++) {
            cout << "Pesanan " << i + 1 << ": " << orders[i] << endl;
        }
    }

    // Getter untuk informasi admin
    void viewAdminInfo() {
        cout << "Admin Info:\n";
        cout << "ID: " << adminId << endl;
        cout << "Nama: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

int main() {
    vector<string> orders = { "Pesanan #1 - Pending", "Pesanan #2 - Diproses", "Pesanan #3 - Selesai" };

    // Membuat objek Admin
    Admin admin1("A001", "Elfa Bintang Vio", "elfabintangvio@mail.com", "AdminEBV", "elfabintangvio");

    // Autentikasi Admin
    string username, password;
    cout << "Masukkan username admin: ";
    cin >> username;
    cout << "Masukkan password admin: ";
    cin >> password;

    // Verifikasi kredensial admin
    if (!admin1.authenticate(username, password)) {
        cout << "Login gagal. Username atau password salah!" << endl;
        return 0; // Keluar dari program jika login gagal
    }

    cout << "Login berhasil!\n\n";

    // Menampilkan informasi admin
    admin1.viewAdminInfo();
    cout << endl;

    int choice;
    do {
        // Menu Admin
        cout << "\nMenu Admin:\n";
        cout << "1. Mengelola Data Pesanan\n";
        cout << "2. Menambahkan Pesanan\n";
        cout << "3. Menghapus Pesanan\n";
        cout << "4. Mencari Pesanan\n";
        cout << "5. Menghasilkan Laporan\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            admin1.manageData(orders);
            break;
        case 2: {
            string newOrder;
            cout << "Masukkan deskripsi pesanan baru: ";
            cin.ignore();
            getline(cin, newOrder);
            admin1.addOrder(orders, newOrder);
            break;
        }
        case 3: {
            int orderIndex;
            cout << "Masukkan indeks pesanan yang akan dihapus: ";
            cin >> orderIndex;
            admin1.removeOrder(orders, orderIndex - 1); // indeks berbasis 1, tapi dihapus berbasis 0
            break;
        }
        case 4: {
            string searchTerm;
            cout << "Masukkan kata kunci untuk mencari pesanan: ";
            cin >> searchTerm;
            admin1.searchOrder(orders, searchTerm);
            break;
        }
        case 5:
            admin1.generateReports(orders);
            break;
        case 6:
            cout << "Keluar dari aplikasi...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }

    } while (choice != 6);

    return 0;
}
