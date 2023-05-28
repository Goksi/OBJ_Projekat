//
// Created by Private on 5/24/2023.
//

#include "MiscUtils.h"
#include <iostream>
#include <sstream>

std::string MiscUtils::ReadString(std::istream &stream) {
    size_t len;
    stream.read(reinterpret_cast<char *>(&len), sizeof(len));
    std::string str(len, '\0');
    stream.read(&str[0], (long long) len);
    return str;
}

std::queue<std::string> *MiscUtils::SplitString(const std::string &str, char delimiter) {
    auto queue = new std::queue<std::string>();
    std::string temp;
    std::stringstream ss(str);
    while (std::getline(ss, temp, delimiter)) {
        queue->push(temp);
    }
    return queue;
}

Smestaj MiscUtils::ReadSmestaj(int lastId) {
    string naziv;
    cout << "Unesite ime smestaja: " << endl;
    getline(cin, naziv);
    string lokacija;
    cout << "Unesite lokaciju smestaja: " << endl;
    getline(cin, lokacija);
    int cena;
    cout << "Unesite cenu u dinarima za noc: " << endl;
    cin >> cena;
    int kapacitet;
    cout << "Unesite koliko maksimalno osoba moze da stane u ovaj smestaj: " << endl;
    cin >> kapacitet;
    return {lastId, naziv, lokacija, cena, kapacitet};
}
