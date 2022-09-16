# include <bits/stdc++.h>
# include "Sales_data.h"
using namespace std;

int main() {
    Sales_data item;

    cin >> item.bookNo >> item.revnue >> item.units_sold;
    cout << item.bookNo << item.revnue << item.units_sold;

    system("pause");
    return 0;
}