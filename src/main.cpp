#include <vector>
#include "Manager.h"
#include "KorisnikManager.h"
#include "CommandHandler.h"
#include "LoginCommand.h"
#include "RegisterCommand.h"
#include "HotelManager.h"
#include "ApartmanManager.h"

using namespace std;

vector<Manager *> managers;

CommandHandler mainHandler("mainHandler");

void setupManagers(vector<Manager *> &m);

int main() {
    setupManagers(managers);
    auto *korisnikManager = dynamic_cast<KorisnikManager *>(managers[0]);
    mainHandler.AddCommand("login", new LoginCommand(managers));
    mainHandler.AddCommand("register", new RegisterCommand(korisnikManager));
    cout << R"(
  _   _      _             _         _
 | \ | |    | |           | |       (_)
 |  \| | ___| | ___ __ ___| |_ _ __  _ _ __   ___
 | . ` |/ _ \ |/ / '__/ _ \ __| '_ \| | '_ \ / _ \
 | |\  |  __/   <| | |  __/ |_| | | | | | | |  __/
 |_| \_|\___|_|\_\_|  \___|\__|_| |_|_|_| |_|\___|
    )" << endl;
    cout << "Dobrodosli u aplikaciju koja nudi kupovinu kako trajnog smestaja, tako i raznih privremenih resenja !"
         << endl << endl;
    cout << "Da bi nastavili sa koriscenjem, morate da se ulogujete koriscenjem komande "
            "\"login <username>\", ili se registrujte komandom \"register\" !" << endl;

    mainHandler.ListenStdin();
    for (auto ptr: managers) {
        ptr->Save();
        delete ptr;
    }
    return 0;
}


void setupManagers(vector<Manager *> &m) {
    m.push_back(new KorisnikManager());
    m.push_back(new HotelManager());
    m.push_back(new ApartmanManager());
}