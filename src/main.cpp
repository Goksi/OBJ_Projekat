#include <iostream>
#include <vector>
#include "Manager.h"
#include "KorisnikManager.h"

using namespace std;

vector<Manager> managers;

void setupManagers(vector<Manager> &m);

int main() {
    setupManagers(managers);
    return 0;
}


void setupManagers(vector<Manager> &m) {
    m.push_back(KorisnikManager());
}