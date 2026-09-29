#include <iostream>
#include <string>
#include <vector>
#include "nomer_1.h"


using namespace std;

struct BaggageItem {
    string name;
    double weight;
};

struct Passenger {
    string fullName = "vrete";
    vector<BaggageItem> baggage;
};

int main() {
    cout << "#1" << endl;
    cout << nomer_1() << endl;
    cout << "\n\n#2" << endl;
    int n;
    cout << "Scol`ko passajirov?\n";
    cin >> n;

    vector<Passenger> passengers(n);
    for (int i = 0; i < n; ++i) {
        string passengerName;
        cout << "FIO #" << (i + 1) << "?\n";
        cin.ignore();
        getline(cin, passengers[i].fullName);
        int a;
        cout << "Skol`ko bagaja u #" << (i + 1) << "?\n";
        cin >> a;

        passengers[i].baggage.resize(a);
        for (int j = 0; j < a; ++j) {
            cout << "imya predmeta #" << (j + 1) << "?\n";
            cin.ignore();
            getline(cin, passengers[i].baggage[j].name);
            cout << "ves predmeta #" << (j + 1) << " v kg?\n";
            cin >> passengers[i].baggage[j].weight;
        }
    }

    int tyazhesti = 0;
    bool dofigaNesesh = false;
    double totalWeight = 0;
    int totalBaggageCount = 0;
    int srednee = 0;
    int treeItems = 0;
    double maxBaggageWeight = 0;
    string heaviestPassenger;

    for (Passenger passenger: passengers) {
        double baggageWeight = 0;
        for (BaggageItem item: passenger.baggage) {
            baggageWeight += item.weight;
            if (item.weight > 20 && passenger.baggage.size() == 1) {
                dofigaNesesh = true;
            }
        }

        if (baggageWeight > 30) {
            tyazhesti++;
        }

        totalWeight += baggageWeight;
        totalBaggageCount += passenger.baggage.size();

        if (passenger.baggage.size() > 3) {
            treeItems++;
        }

        if (baggageWeight > maxBaggageWeight) {
            maxBaggageWeight = baggageWeight;
            heaviestPassenger = passenger.fullName;
        }
    }

    cout << "Passajir s odnoi vesh`u vesom bolee 20 kg: "
            << (dofigaNesesh ? "EST`" : "NETU") << endl;


    double averageBaggageWeight = totalWeight / passengers.size();

    for (Passenger passenger: passengers) {
        double baggageWeight = 0.0;
        for (BaggageItem item: passenger.baggage) {
            baggageWeight += item.weight;
        }
        if (baggageWeight > averageBaggageWeight) {
            srednee++;
        }
    }

    cout << "Chislo passajirov s bagajom bolee 30 kg: " << tyazhesti << endl;
    cout << "Chislo passajirov s bagajom bol`she srednevo: " << srednee << endl;
    cout << "Chislo passajirov s tremya i bolee veshami: " << treeItems << endl;
    cout << "Passajir s max Weight bagaja: " << heaviestPassenger << " (" << maxBaggageWeight << " kg)" << endl;

    return 0;
}
