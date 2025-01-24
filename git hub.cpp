#include <iostream>
#include <string>
using namespace std;

// Base class: Plaza
class Plaza {
protected:
    string plazaName;
    string location;

public:
    Plaza(string name, string loc) : plazaName(name), location(loc) {}

    void displayPlazaDetails() {
        cout << "Plaza Name: " << plazaName << endl;
        cout << "Location: " << location << endl;
    }
};

// Base class: Inventory
class Inventory {
protected:
    int totalItems;

public:
    Inventory(int items) : totalItems(items) {}

    void displayInventory() {
        cout << "Total Items in Inventory: " << totalItems << endl;
    }
};

// Derived class: Shop (Multiple Inheritance from Plaza and Inventory)
class Shop : public Plaza, public Inventory {
protected:
    string shopName;
    string ownerName;

public:
    Shop(string plazaName, string location, int items, string shopName, string ownerName)
        : Plaza(plazaName, location), Inventory(items), shopName(shopName), ownerName(ownerName) {}

    void displayShopDetails() {
        displayPlazaDetails();
        cout << "Shop Name: " << shopName << endl;
        cout << "Owner Name: " << ownerName << endl;
    }
};

// Derived class: MobileAccessories (Multilevel Inheritance from Shop)
class MobileAccessories : public Shop {
private:
    int totalMobileAccessories;

public:
    MobileAccessories(string plazaName, string location, int items, string shopName, string ownerName, int accessories)
        : Shop(plazaName, location, items, shopName, ownerName), totalMobileAccessories(accessories) {}

    void displayAccessoriesDetails() {
        displayShopDetails();
        cout << "Total Mobile Accessories: " << totalMobileAccessories << endl;
    }
};

// Main function
int main() {
    // Creating an object of MobileAccessories
    MobileAccessories mobileShop("City Center Plaza", "Main Market, Gujrat", 500, "Tech World", "Mohsin Ali", 300);

    // Displaying details
    cout << "Mobile Accessories Plaza Management System" << endl;
    cout << "------------------------------------------" << endl;
    mobileShop.displayAccessoriesDetails();

    return 0;
}
