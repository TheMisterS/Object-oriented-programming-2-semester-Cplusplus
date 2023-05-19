#ifndef week13
#define week13
#include <bits/stdc++.h>
using namespace std;
class Product{
    float price;
    string name, category;
 public:
    float get_price();
    Product(float desired_price, string desired_name, string desired_category);
};
class Basket{
    float total_price;
    vector<Product> products;
 public:
    float count_total();
    void add_product(Product desired_product);
};
class Discount{
    Discount* next_discount;
 public:
    Discount();
    virtual float price_with_discount(Basket desired_basket);
    void set_next_discount(Discount* next);
};
class Relative_Discount : public Discount{
    float max_price, relative_discount;
 public:
    Relative_Discount(float desired_max_price, float desired_relative_discount);
    float price_with_discount(Basket desired_basket);
};
class Percentage_Discount : public Discount{
    float max_price, percentage_discount;
 public:
    Percentage_Discount(float desired_max_price, float desired_relative_discount_percentage);
    float price_with_discount(Basket desired_basket);
};
class Shop{
    vector <Product> catalog;
    Discount *discount_type;
 public:
    void set_catalog(Product desired_product);
    void set_discount_type(Discount *desired_discount_type);
    float check_discount_price(Basket desired_basket);
};
#endif // week13