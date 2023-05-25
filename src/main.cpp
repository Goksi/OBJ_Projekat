#include <vector>
#include "Manager.h"
#include "KorisnikManager.h"

using namespace std;

vector<Manager *> managers;

void setupManagers(vector<Manager *> &m);

int main() {
    setupManagers(managers);
    string username;
    string password;
    cout << "Unesite username" << endl;
    cin >> username;
    cout << "Unesite password" << endl;
    cin >> password;
    Korisnik korisnik = dynamic_cast<KorisnikManager *>(managers[0])->TryLogin(username, password);
    cout << korisnik.GetUsername() << " " << korisnik.GetId();
    for (auto ptr: managers) {
        ptr->Save();
        delete ptr;
    }
    return 0;
}


void setupManagers(vector<Manager *> &m) {
    m.push_back(new KorisnikManager());
}