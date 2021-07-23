#include <iostream>
#include <fstream>
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"
#include "load.h"

using namespace std;

int main() { 


  cout << "\nPart 2.2: Use the Carton Class in Main.cpp\n";

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions.
    Carton obj1;

  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  cout << "Before~" << endl;
  cout << "Carton Width: " << obj1.get_width() << endl;
  cout << "Carton Height: " << obj1.get_height() << endl;
  obj1.Display(cout);

  obj1.set_width(10);
  obj1.set_height(9);
  cout << "\n\nAfter~" << endl;
  cout << "Carton Width: " << obj1.get_width() << endl;
  cout << "Carton Height: " << obj1.get_height() << endl;

  // Use the Carton object to call the Display method to print to cout.
  obj1.Display(cout);


  cout << "\n\nPart 3.3: Use the Flat Class in Main.cpp\n";

  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  Address address2;
  address2.name = "John Baron";
  address2.street_address =  "653 S 60 W";
  address2.city = "Tokyo";
  address2.state = "California";
  address2.zip = "54321";

  Flat flat1;
  Flat flat2(address2, 0.52, 1.2, 5.8, 0.6);

  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  cout << "Before~" << endl;
    cout << "Flat 1 Height: " << flat1.get_height() << endl
         << "Flat 1 Thickness: " << flat1.get_thickness() << endl;

    flat1.set_height(7.5);
    flat1.set_thickness(0.7);
    cout << "After~" << endl;
    cout << "Flat 1 Height: " << flat2.get_height() << endl
         << "Flat 1 Thickness: " << flat2.get_thickness() << endl;

    cout << "\nFlat 2 Height: " << flat2.get_height() << endl
         << "Flat 2 Thickness: " << flat2.get_thickness() << endl;

  // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.
  cout << "\nFlat 1 Volume: " << flat1.Volume() << endl;
  flat1.Display(cout);

    cout << "\n\nFlat 2 Volume: " << flat2.Volume() << endl;
    flat2.Display(cout);


  cout << "\n\nPart 4.3: Use the Tube Class in Main.cpp";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
    Address address3;
    address2.name = "Sherry Underwood";
    address2.street_address =  "653 S 60 W";
    address2.city = "Prague";
    address2.state = "Kansas";
    address2.zip = "12345";

  Tube tube1;
  Tube tube2(address3, 17.2, 25, 12.85);

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
    cout << "\nBefore~" << endl;
    cout << "Tube 1 Circumference: " << tube1.get_circumference() << endl;

    tube1.set_circumference(0.7);
    cout << "After~" << endl;
    cout << "Tube 1 Circumference: " << tube1.get_circumference() << endl;

    cout << "\nTube 2 Circumference: " << tube2.get_circumference() << endl;

  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.
    cout << "\nTube 1 Volume: " << tube1.Volume() << endl;
    cout << "Tube 1 Girth: " << tube1.Girth() << endl;
    tube1.Display(cout);

    cout << "\n\nTube 2 Volume: " << tube2.Volume() << endl;
    cout << "Tube 2 Girth: " << tube2.Girth() << endl;
    tube2.Display(cout);


  cout << "\n\nPart 5.3: Use the Load Class in Main.cpp";

  // 1. Create a Load object.
    Load load1;

  // 2. Use the Load object to call the getter methods.
  // Print out the results to see how these getters are working.
  // Do this right after the Load object is created and after it
  // is filled from the file.
  load1.FillLoad("../../load_1.txt");

  cout << "Total Items: " << load1.get_count() << endl;
  cout << "Total Volume: " << load1.get_total_volume() << endl;
  cout << "Total Weight: " << load1.get_total_weight() << endl;


  //3. Use the Load object to call the FillLoad method.
  // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // to see how these work when making deliveries.

  ofstream out("../../example_load_main.txt");
  load1.DisplayNextDelivery(out);
  load1.ItemDelivered();
  load1.NotDeliverable();
  load1.ItemDelivered();
  cout << "How Many Delivered?: " << load1.HowManyDelivered() << endl;
  cout << "How Many Not Delivered?: " << load1.HowManyNotDelivered() << endl;


  return 0; 
}