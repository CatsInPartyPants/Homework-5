// Homework-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

double manager_wage(double stwage, double sales);

int main()
{
    //task 1

    int user_pizza_select=0, count_of_pizzas=0, user_drink_select=0, count_of_drinks=0; // data received from user

    double pizza_price_prisciutto = 5.50, pizza_price_louis = 7.20, pizza_price_detroit = 10.20, pizza_price_pesto = 15.80; //pizza price
    double price_cocacola = 2.1, price_sprite = 1.7, price_juice = 3.1; // drinks price
    double total_order=0,drinks_price_total = 0, discount = 0, discount_for_drinks=0; // price tag
    double user_pizza_price=0, user_drink_price=0; // price user selected
    int show_pizza_count=0; // pizza count for show in order

    string name_prisciutto = " Prosciutto e funghi Pizza";// pizza names
    string name_louis = " St. Louis-Style Pizza";
    string name_detroit = " Detroit-Style Pizza";
    string name_pesto = " Pizza pesto Genovese";
    string user_pizza_name; // pizza name user selected

    string name_cocacola = " Coca-cola";// drinks names
    string name_sprite = " Sprite";
    string name_juice = " Juice";
    string user_drink_name; //drink name user selected

    enum pizzas {prosciutto=1, louis, detroit, pesto};
    enum drinks{cocacola=1, sprite, juice};

    //menu for pizza
    cout << "Pizza shop!\n";
    cout << "Please, select pizza you want to buy:\n";
    cout << "If total order will be more then $50, discount will be 20%!" << endl;
    cout << "Every 5 pizza is free, and if you buy more then 3 drinks that cost over $2, discount for drinks 20%!\n\n" << endl;
    cout << "Pizza menu:\n\n";

    cout << "$" << pizza_price_prisciutto << name_prisciutto << ", for select press 1" << endl;
    cout << "$" << pizza_price_louis << name_louis << ", for select press 2" << endl;
    cout << "$" << pizza_price_detroit << name_detroit << ", for select press 3" << endl;
    cout << "$" << pizza_price_pesto << name_pesto << ", for select press 4" << endl;
    cin >> user_pizza_select;

    system("CLS");

    cout << "How much pizzas do you want to buy?" << endl;
    cin >> count_of_pizzas;
    show_pizza_count = count_of_pizzas;
    count_of_pizzas -= count_of_pizzas / 5; //every 5 pizza free
    system("CLS");

    //menu for drinks
    cout << "What drink do you want to buy?\n\n";
    cout << "$" << price_cocacola << name_cocacola << ", for select press 1" << endl;
    cout << "$" << price_sprite << name_sprite << ", for select press 2" << endl;
    cout << "$" << price_juice << name_juice << ", for select press 3" << endl;
    cin >> user_drink_select;

    cout << "How much drinks do you want to buy?" << endl;
    cin >> count_of_drinks;
    system("CLS");


    switch (user_pizza_select)
    {
    case prosciutto:
        user_pizza_price = pizza_price_prisciutto;
        user_pizza_name = name_prisciutto;
        break;
    case louis:
        user_pizza_price = pizza_price_louis;
        user_pizza_name = name_louis;
        break;
    case detroit:
        user_pizza_price = pizza_price_detroit;
        user_pizza_name = name_detroit;
        break;
    case pesto:
        user_pizza_price = pizza_price_pesto;
        user_pizza_name = name_pesto;
        break;
    }

    switch (user_drink_select)
    {
    case cocacola:
        user_drink_price = price_cocacola;
        user_drink_name = name_cocacola;
        break;
    case sprite:
        user_drink_price = price_sprite;
        user_drink_name = name_sprite;
        break;
    case juice:
        user_drink_price = price_juice;
        user_drink_name = name_juice;
        break;
    }

    if (count_of_drinks > 3 && user_drink_price > 2)
    {
        drinks_price_total = (count_of_drinks * user_drink_price) - ((count_of_drinks * user_drink_price / 100) * 20);
        discount_for_drinks = (count_of_drinks * user_drink_price / 100) * 20;
    }
    else
    {
        drinks_price_total = count_of_drinks * user_drink_price;
    }

    total_order = drinks_price_total + (count_of_pizzas * user_pizza_price);

    if (total_order > 50)
    {
        total_order -= (total_order / 100) * 20;
        discount += (total_order / 100) * 20 + discount_for_drinks+ ((show_pizza_count * user_pizza_price) - (count_of_pizzas * user_pizza_price));
    }
    else
    {
        discount += discount_for_drinks+ ((show_pizza_count * user_pizza_price) - (count_of_pizzas * user_pizza_price));
    }

    // order
    cout << "Your order:\n\n";
    cout << "The cost of " << show_pizza_count << " " << user_pizza_name << ", is $" << count_of_pizzas * user_pizza_price << endl;
    cout << "Discount for pizzas is $" << (show_pizza_count * user_pizza_price) - (count_of_pizzas * user_pizza_price) << endl;
    cout << "The cost of " << count_of_drinks << " counts of " << user_drink_name << ", is $" << drinks_price_total << endl;
    cout << "Discount for drinks is $" << discount_for_drinks << endl<< endl;
    cout << "\t\t\t\t\tTotal order is $" << round(total_order*100)/100 << endl;
    cout << "\t\t\t\t\tYour total discount is $" << round(discount*100)/100 << endl;



    //task 2

    const int Count_of_managers=3;
    double standart_wage = 200;
    double manager_sales[Count_of_managers]{0};
    double manager1_wage = 0, manager2_wage = 0, manager3_wage = 0;
    
    for (int i = 0; i < Count_of_managers; i++) {
        cout << "enter the sales of " << i+1 << " manager->";
        cin >> manager_sales[i];
    }
    manager1_wage = manager_wage(standart_wage, manager_sales[0]);
    manager2_wage = manager_wage(standart_wage, manager_sales[1]);
    manager3_wage = manager_wage(standart_wage, manager_sales[2]);

    if (manager1_wage > manager2_wage && manager1_wage > manager3_wage)
    {
        cout << "\nmanager 1 recieve a bonus!\n\n";
        manager1_wage +=  200;
    }
    else if(manager2_wage > manager3_wage)
    {
        cout << "\nmanager 2 recieve a bonus!\n\n";
        manager2_wage +=  200;
    }
    else
    {
        cout << "\nmanager 3 recieve a bonus!\n\n";
        manager3_wage +=  200;
    }
    cout << "Wage of the managers this month: \n";
    cout << "Manager 1 wage:" << manager1_wage << "$\n";
    cout << "Manager 2 wage:" << manager2_wage << "$\n";
    cout << "Manager 3 wage:" << manager3_wage << "$\n";

}

double manager_wage(double stwage, double sales)
{
    double mngwage = 0;
    if (sales < 500) {
        mngwage = stwage + (sales / 100) * 3;
    }
    else if(sales <1000)
    {
        mngwage = stwage + (sales / 100) * 5;
    }
    else
    {
        mngwage = stwage + (sales / 100) * 8;
    }
    return mngwage;
}