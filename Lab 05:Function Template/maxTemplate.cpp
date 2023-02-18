#include <iostream>
#include <string>

using namespace std;
//Make a template out of the prototype
template <class Item>
Item myMax(Item, Item);

int main()
{
    int i_one = 3, i_two = 5;

    cout << "The max of " << i_one << " and " << i_two << " is " << myMax(i_one, i_two) << endl;

    //Test your template on float and string types
    string uno = "donkey";
    string dos = "apple";
    cout << "The max of " << dos << " and " << uno << " is " << myMax(dos, uno) << endl;

    float x = 123.456;
    float y = 33.289;

    cout << "The max of " << y << " and " << x << " is " << myMax(y, x) << endl;


    return 0;
}

//Make a template out of this function. Don't forget the return type.
template <class Item>
Item myMax(Item one, Item two)
{
    Item bigger;
    if (one < two) {
        bigger = two;
    }
    else {
        bigger = one;
    }
    return bigger;
}