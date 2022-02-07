#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


// Question 1/2
void question1(int i, double value){
  string sentence;
  cout << "The double is equal to " << setprecision(2) << fixed << value;
  cout << " and the integer values is equal to " << i << ".\n";
  cout << "\nThe end.\n";
}

// Question 3
double question2(int x, int y){
  double a = sqrt(pow(x,2) + pow(y,2));
  double b = a + pow(a,2) + pow(a,6) + pow(y,3);
  return b;
}

// Question 4 
void question4(){
  // Creating a local variable on the stack
  int stack_var = 5;  
}

// Question 5
void question5(){
  // Creating a local variable on the heap
  int *heap_var = new int;
  *heap_var = 5;
}

// Question 6
void question6(){
  // Creating a 2D array on the heap
  const int ROWS = 3;
  const int COLUMNS = 4;

  int **heap_arr = new int *[ROWS];

  for (int i=0; i < 3; i++){
    heap_arr[i] = new int [COLUMNS];
  }
}

// Question 7
double fn_a(int i); // Function returns nth term of series a(i)
double fn_b(int j); // Function returns nth term of series b(j)
double question7(int N){
  // Factor out constant terms
  double constant = 2/(N*(N-1));

  // Apply Double Sum -> Product of Sums Property
  double sum1 = 0.0;
  for (int i = 1; i < N; i++){ sum1 += fn_a(i); }
  
  double sum2 = 0.0;
  for (int j = 2; j < N; j++){ sum2 += fn_b(j); }

  return constant*sum1*sum2;
}

// Question 8
void question8(){
  for (float n=100; n<200; n = n+0.03){
    cout << n << ", ";
  }
}

// Question 10
// Function to print each iteration:
void print(int array1[], int size){
  for (int i=0; i<size; i++){
    cout << array1[i];
  }
  cout << endl;
}
void question10(int array2[], int curr_index, int size){
  if (curr_index == size-1){ 
    print(array2, size); 
    return;
    }
  for (int i=curr_index; i<size; i++) {
      swap(array2[i], array2[curr_index]);
      question10(array2, curr_index+1, size);
      swap(array2[i], array2[curr_index]);
  }
}

// Defining class to create shapes:
// Base Class:
class Shape{
  private:
    string border_color;
    string border_thickness;
    string interior_color();
  public:   
    Shape(string bord_color, string bord_thick, string int_color);
    string get_border_col();
    string get_border_thick();
    string get_interior_col();
};

class Center{ // Contains (X,Y) coordinate for center of shape to place on graph
  private:
    double x_axis;
    double y_axis;
  public:
    Center();
    Center(double x, double y);
    double get_x_axis();
    double get_y_axis();
};

class Ellipse: public Shape{ // Circle is subset of Ellipse
  private:
    double radius1; // x and y directions (radius1 = radius2 in a Circle)
    double radius2; 
    double area; // Will be defined in constructor
  public:
    Ellipse();
    Ellipse(double radius1, double radius2);
    Center center_coordinate;
    void set_center_coordinate(double x, double y);
    double get_area();
    double get_radius1();
    double get_radius2();
};

class Rectangle: public Shape{ // Square is subset of Rectangle
  private:
    double length;
    double height;
    double area;
  public:
    Rectangle();
    Center center_coordinate;
    void set_center_coordinate(double x, double y);
    double get_area();
};

class Parallellogram: public Shape{
  private:
    double vertices[4][2]; 
    double area;
  public:
    Parallellogram();
    Parallellogram(double vertices[][2]); // Passing 4 vertices to be able to graph
    double get_area();   
};

class Triangle: public Shape{
  private:
    double vertices[3][2];
    double area;
  public:
    Triangle();
    Triangle(double vertices[][2]); // Passing 3 vertices to be able to graph
    double get_area();  
};


// Driver
int main(){

  cout << "Now running Question 1/2:\n\n";
  question1(25, 17.4495);

  cout << "\n\nNow running Question 3:\n\n";
  cout << "The value of b is: " << question2(2,3);

  cout << "\n\n\nNow running Question 8:\n\n";
  cout << "Numbers in the sequence are:\n";
  //question8();

  // Question 10
  cout << "\n\nNow running Question 10:\n";
  const int n = 3;
  int array0[n];
  for (int i=0; i<n; i++){ array0[i] = i+1; };
  question10(array0, 0, n);

}