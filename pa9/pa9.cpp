#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

void Prices(const map<string, vector<double>>& prices) {
    cout << left << setw(15) << "Name:";
    for (const auto& store : {"eBay", "Amazon", "BestBuy", "OfficeMax", "Staples"}) {
        cout << setw(10) << store;
    }
    cout << endl;

    for (const auto& item : prices) {
        cout << left << setw(15) << item.first;
        for (const auto& price : item.second) {
            cout << setw(10) << price;
        }
        cout << endl;
    }
}

void AveragePrices(const map<string, vector<double>>& prices) {
    vector<pair<string, double>> avgPrices;

    for (const auto& item : prices) {
        double avg = accumulate(item.second.begin(), item.second.end(), 0.0) / item.second.size();
        avgPrices.push_back({item.first, avg});
    }

    sort(avgPrices.begin(), avgPrices.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    cout << "Average Prices (in ascending order):" << endl;
    for (const auto& item : avgPrices) {
        cout << left << setw(15) << item.first << "Avg: " << item.second << endl;
    }
}

void BestPrices(const map<string, vector<double>>& prices) {
    vector<string> stores = {"eBay", "Amazon", "BestBuy", "OfficeMax", "Staples"};

    cout << "Best Prices Offered by Stores:" << endl;
    for (const auto& item : prices) {
        auto minPriceIt = min_element(item.second.begin(), item.second.end());
        int storeIndex = distance(item.second.begin(), minPriceIt);
        cout << left << setw(15) << item.first << "Best Price offered by: " << stores[storeIndex] << endl;
    }
}

int main() {
    map<string, vector<double>> prices = {
        {"IPhone14", {999.99, 978.99, 1009.99, 995.00, 1002.50}},
        {"IPad Pro", {1499.00, 1459.98, 1545.99, 1500.00, 1480.00}},
        {"Noise Cancelling Headphones", {299.99, 279.99, 289.99, 295.00, 285.00}},
        {"Back Roller", {49.99, 44.99, 39.99, 45.00, 42.50}},
        {"Bike", {499.99, 479.99, 509.99, 495.00, 502.50}}
    };

    Prices(prices);
    AveragePrices(prices);
    BestPrices(prices);
}