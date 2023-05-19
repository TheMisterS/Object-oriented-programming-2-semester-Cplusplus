#include <cmath>
#include <bits/stdc++.h>
#include "13week.h"
using namespace std;
Product::Product(float desired_price, string desired_name, string desired_category){
    price = desired_price;
    name = desired_name;
    category = desired_category;
}
float Product::get_price(){
    return price;
}
float Basket::count_total(){
    vector<Product>::iterator itr;
    float total_price = 0;
    for(itr = products.begin(); itr < products.end(); itr++){
        total_price += (*itr).get_price();
    }
    return total_price;
}
void Basket::add_product(Product desired_product){
    products.push_back(desired_product);
}
Discount::Discount(){
    next_discount = nullptr;
}
float Discount::price_with_discount(Basket desired_basket){
    if (next_discount != nullptr){
        return next_discount->price_with_discount(desired_basket);
    }
    return desired_basket.count_total();
}    
void Discount::set_next_discount(Discount* next){
    next_discount = next;
}
Relative_Discount::Relative_Discount(float desired_max_price, float desired_relative_discount){
    max_price = desired_max_price;
    relative_discount = desired_relative_discount;
}
float Relative_Discount::price_with_discount(Basket desired_basket){
   if(desired_basket.count_total() > max_price)
        {
            return desired_basket.count_total() - relative_discount;
        }
    return Discount::price_with_discount(desired_basket);
}
Percentage_Discount::Percentage_Discount(float desired_max_price, float desired_relative_discount_percentage){
    max_price = desired_max_price;
    percentage_discount = desired_relative_discount_percentage;
}
float Percentage_Discount::price_with_discount(Basket desired_basket){
   if(desired_basket.count_total() > max_price)
        {
            return desired_basket.count_total() * (1 - percentage_discount / 100);
        }
    return Discount::price_with_discount(desired_basket);
}
    void Shop::set_catalog(Product desired_product){
        catalog.push_back(desired_product);
    }
    void Shop::set_discount_type(Discount *desired_discount_type){
        discount_type = desired_discount_type;
    }
    float Shop::check_discount_price(Basket desired_basket){
        float discount_price = discount_type->price_with_discount(desired_basket); // for some reason didn't work with just a return statement
        return discount_price;
    }
int main(){
    //Products
    Product apple(50,"Apple","Fruits");
    Product orange(50,"Orange","Fruits");
    Product potato(50,"Potato","Vegetables");
    Product carrot(50,"Carrot","Vegetables");
    Product milk(25,"1L Carton of Milk","Dairy");
    Product butter(25,"500g of Butter","Dairy");
    //Discounts
    Relative_Discount three_relative(300,30);
    Relative_Discount two_relative(200,20);
    Relative_Discount one_relative(100,10);
    Percentage_Discount three_percentage(300,30);
    Percentage_Discount two_percentage(200,20);
    Percentage_Discount one_percentage(100,10);

    three_relative.set_next_discount(&two_relative);
    two_relative.set_next_discount(&one_relative);

    three_percentage.set_next_discount(&two_percentage);
    two_percentage.set_next_discount(&one_percentage);

    //Shop & Basket
    Basket MyBasket;
    Shop MyShop;
    //Test functions
    MyBasket.add_product(apple);
    MyBasket.add_product(orange);
    MyBasket.add_product(potato);
    MyBasket.add_product(carrot);
    MyBasket.add_product(milk);
    MyBasket.add_product(butter);
    cout << "Your basket's cost without discounts: " << MyBasket.count_total() << endl;
    MyShop.set_discount_type(&three_percentage);
    cout << "Using our percentage discount you would pay: " << MyShop.check_discount_price(MyBasket) << endl;
    MyShop.set_discount_type(&three_relative);
    cout << "Using our relative discount you would pay: " << MyShop.check_discount_price(MyBasket) << endl;
    return 0;
}