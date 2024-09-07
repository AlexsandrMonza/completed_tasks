#include <iostream>
#include <math.h>

enum class Colors {
    WHITE,
    BLACK,
    RED,
    YELLOW,
    ORANGE,
    GREEN,
    BLUE,
    PURPLE,
    PINK,
    BROWN,
    GREY,
    NONE
};

class Form
{
private:
    double xCentr=0.0f;
    double yCentr=0.0f;
    std::string colors;
public:

    //Сетеры
    void SetX ()
    {
        std::cin>>xCentr;
    }
    void SetY ()
    {
        std::cin>>yCentr;
    }
    void SetColors ()
    {
        std::cin>>colors;
    }

    //Гетеры
    double GetX ()
    {
        return xCentr;
    }
    double GetY ()
    {
        return yCentr;
    }
    std::string GetColors ()
    {
    return colors;
    }
};

class Circle :public Form
{
private:
    Colors color;
    const double pi=3.14;
    double radiusCircle=0.0f;
    double squareCircle=0.0f;
public:

    //Seters
    void SetRadiusCircle ()
    {
        std::cin>>radiusCircle;
        squareCircle=pow (radiusCircle,2)*pi;
    }
    void SetColor (Colors color){
        this->color=color;
    }

    //Geters
    double GetSquareCircle (){
        return squareCircle;
    }
    double GetRadius (){
        return radiusCircle;
    }
    Colors GetColor(){
        return color;
    }
};

class Triangle :public Form
{
private:
    Colors color;
    double length=0.0f;
    double heigth=0.0f;
public:

    //Seters
    void SetLength (){
        std::cin>>length;
        heigth=length*sqrt(3)/2;
    }
    void SetColor (Colors color){
        this->color=color;
    }

    //Geters
    double GetLength (){
        return length;
    }
    double GetHeingth (){
        return heigth;
    }
    double GetSquareTriangle (){
        return  sqrt(3)/4*pow(length,2);
    }
    Colors GetColor (){
        return color;
    }
};

class Quadrant :public Form
{
private:
    Colors color;
    double length = 0.0f;
    double square = 0.0f;
public:

    //Seters
    void SetLength (){
        std::cin>>length;
    }
    void SetColor (Colors color){
        this->color=color;
    }

    //Geters
    double GetLength (){
        return length;
    }
    double GetSquare (){
        return square = pow (length,2);
    }
    Colors GetColor (){
        return color;
    }
};

class Rectangle :public Form
{
private:
    Colors color;
    double length=0.0f;
    double heingth=0.0f;
public:

    //Seters
    void SetLength (){
        std::cin>>length;
    }
    void SetHeingth (){
        std::cin>>heingth;
    }
    void SetColor (Colors color){
        this->color=color;
    }

    //Geters
    double GetLength (){
        return length;
    }
    double GetHeingth (){
        return heingth;
    }
    double GetSquare (){
        return length*heingth;
    }
    Colors GetColor (){
        return color;
    }
};



int main () {
    Circle circle;
    Triangle triangle;
    Quadrant square;
    Rectangle rectangle;
    std::string figure;
    std::string color;

    std::cout<<"Figure? (Circle, Triangle, Square, Rectangle)\n";
    std::cin>>figure;

    if (figure=="Circle") {
        std::cout<<"Coordinate centr X and Y:\n";
        circle.SetX();
        circle.SetY();
        std::cout << "Radius circle:\n";
        circle.SetRadiusCircle ();

        std::cout<<"Input color cicle (White, Black, Red, Yellow, Orange, Green, Blue, Purple, Pink, Brown, Grey):\n";
        std::cin>>color;

        if (color=="White"){
            circle.SetColor(Colors::WHITE);
        }
        else if (color=="Black"){
            circle.SetColor (Colors::BLACK);
        }
        else if (color=="Red"){
            circle.SetColor (Colors::RED);
        }
        else if (color=="Yellow"){
            circle.SetColor (Colors::YELLOW);
        }
        else if (color=="Orange"){
            circle.SetColor (Colors::ORANGE);
        }
        else if (color=="Green"){
            circle.SetColor (Colors::GREEN);
        }
        else if (color=="Blue"){
            circle.SetColor (Colors::BLUE);
        }
        else if (color=="Purple"){
            circle.SetColor (Colors::PURPLE);
        }
        else if (color=="Pink"){
            circle.SetColor (Colors::PINK);
        }
        else if (color=="Brown"){
            circle.SetColor (Colors::BROWN);
        }
        else if (color=="Grey"){
            circle.SetColor (Colors::GREY);
        }
        else {
            circle.SetColor (Colors::NONE);
        }


        if (circle.GetColor()==Colors::WHITE){
            std::cout<<"Color circle: White\n";
        }
        else if (circle.GetColor()==Colors::BLACK){
            std::cout<<"Color circle: Black\n";
        }
        else if (circle.GetColor()==Colors::RED){
            std::cout<<"Color circle: Red\n";
        }
        else if (circle.GetColor()==Colors::YELLOW){
                std::cout<<"Color circle: Yellow\n";
        }
        else if (circle.GetColor()==Colors::ORANGE){
            std::cout<<"Color circle: Orange\n";
        }
        else if (circle.GetColor()==Colors::GREEN){
            std::cout<<"Color circle: Green\n";
        }
        else if (circle.GetColor()==Colors::BLUE){
            std::cout<<"Color circle: Blue\n";
        }
        else if (circle.GetColor()==Colors::PURPLE){
            std::cout<<"Color circle: Purple\n";
        }
        else if (circle.GetColor()==Colors::PINK){
            std::cout<<"Color circle: Pink\n";
        }
        else if (circle.GetColor()==Colors::BROWN){
            std::cout<<"Color circle: Brown\n";
        }
        else if (circle.GetColor()==Colors::GREY){
            std::cout<<"Color circle: Grey\n";
        }
        else if (circle.GetColor()==Colors::NONE) {
            std::cout<<"Color circle: None\n";
        }

        std::cout << "Square circle: " << circle.GetSquareCircle () << "\n";
        std::cout<<"Perimetr:\n";
        std::cout<<"Point A X="<<circle.GetX()-circle.GetRadius()-0.1<<" Y="<<circle.GetY()-circle.GetRadius()-0.1<<"\n";
        std::cout<<"Point B X="<<circle.GetX()-circle.GetRadius()-0.1<<" Y="<<circle.GetY()+circle.GetRadius()+0.1<<"\n";
        std::cout<<"Point C X="<<circle.GetX()+circle.GetRadius()+0.1<<" Y="<<circle.GetY()+circle.GetRadius()+0.1<<"\n";
        std::cout<<"Point D X="<<circle.GetX()+circle.GetRadius()+0.1<<" Y="<<circle.GetY()-circle.GetRadius()-0.1<<"\n";
    }

    if (figure=="Triangle"){
        std::cout<<"Coordinate centr X and Y:\n";
        triangle.SetX();
        triangle.SetY();
        std::cout<<"Side length triangle:\n";
        triangle.SetLength();
        std::cout<<"Input color triangle (White, Black, Red, Yellow, Orange, Green, Blue, Purple, Pink, Brown, Grey):\n";
        std::cin>>color;

        if (color=="White"){
            triangle.SetColor(Colors::WHITE);
        }
        else if (color=="Black"){
            triangle.SetColor (Colors::BLACK);
        }
        else if (color=="Red"){
            triangle.SetColor (Colors::RED);
        }
        else if (color=="Yellow"){
            triangle.SetColor (Colors::YELLOW);
        }
        else if (color=="Orange"){
            triangle.SetColor (Colors::ORANGE);
        }
        else if (color=="Green"){
            triangle.SetColor (Colors::GREEN);
        }
        else if (color=="Blue"){
            triangle.SetColor (Colors::BLUE);
        }
        else if (color=="Purple"){
            triangle.SetColor (Colors::PURPLE);
        }
        else if (color=="Pink"){
            triangle.SetColor (Colors::PINK);
        }
        else if (color=="Brown"){
            triangle.SetColor (Colors::BROWN);
        }
        else if (color=="Grey"){
            triangle.SetColor (Colors::GREY);
        }
        else {
            triangle.SetColor (Colors::NONE);
        }

        if (triangle.GetColor()==Colors::WHITE){
            std::cout<<"Color triangle: White\n";
        }
        else if (triangle.GetColor()==Colors::BLACK){
            std::cout<<"Color triangle: Black\n";
        }
        else if (triangle.GetColor()==Colors::RED){
            std::cout<<"Color triangle: Red\n";
        }
        else if (triangle.GetColor()==Colors::YELLOW){
            std::cout<<"Color triangle: Yellow\n";
        }
        else if (triangle.GetColor()==Colors::ORANGE){
            std::cout<<"Color triangle: Orange\n";
        }
        else if (triangle.GetColor()==Colors::GREEN){
            std::cout<<"Color triangle: Green\n";
        }
        else if (triangle.GetColor()==Colors::BLUE){
            std::cout<<"Color triangle: Blue\n";
        }
        else if (triangle.GetColor()==Colors::PURPLE){
            std::cout<<"Color triangle: Purple\n";
        }
        else if (triangle.GetColor()==Colors::PINK){
            std::cout<<"Color triangle: Pink\n";
        }
        else if (triangle.GetColor()==Colors::BROWN){
            std::cout<<"Color triangle: Brown\n";
        }
        else if (triangle.GetColor()==Colors::GREY){
            std::cout<<"Color triangle: Grey\n";
        }
        else if (triangle.GetColor()==Colors::NONE) {
            std::cout<<"Color triangle: None\n";
        }

        std::cout<<"Square triangle: "<<triangle.GetSquareTriangle()<<"\n";
        std::cout<<"Perimetr:\n";
        std::cout<<"Point A X="<<(triangle.GetX()-triangle.GetLength()/2)-0.1<<" Y="<<(triangle.GetY()-triangle.GetHeingth()/2)-0.1<<"\n";
        std::cout<<"Point B X="<<(triangle.GetX()-triangle.GetLength()/2)-0.1<<" Y="<<(triangle.GetY()+triangle.GetHeingth()/2)+0.1<<"\n";
        std::cout<<"Point C X="<<(triangle.GetX()+triangle.GetLength()/2)+0.1<<" Y="<<(triangle.GetY()+triangle.GetHeingth()/2)+0.1<<"\n";
        std::cout<<"Point D X="<<(triangle.GetX()+triangle.GetLength()/2)+0.1<<" Y="<<(triangle.GetY()-triangle.GetHeingth()/2)-0.1<<"\n";
    }

    if (figure == "Square"){
        std::cout<<"Coordinate centr X and Y:\n";
        square.SetX();
        square.SetY();
        std::cout<<"Side length quadrant:\n";
        square.SetLength();
        std::cout<<"Input color quadrant (White, Black, Red, Yellow, Orange, Green, Blue, Purple, Pink, Brown, Grey):\n";
        std::cin>>color;

        if (color=="White"){
            square.SetColor(Colors::WHITE);
        }
        else if (color=="Black"){
            square.SetColor (Colors::BLACK);
        }
        else if (color=="Red"){
            square.SetColor (Colors::RED);
        }
        else if (color=="Yellow"){
            square.SetColor (Colors::YELLOW);
        }
        else if (color=="Orange"){
            square.SetColor (Colors::ORANGE);
        }
        else if (color=="Green"){
            square.SetColor (Colors::GREEN);
        }
        else if (color=="Blue"){
            square.SetColor (Colors::BLUE);
        }
        else if (color=="Purple"){
            square.SetColor (Colors::PURPLE);
        }
        else if (color=="Pink"){
            square.SetColor (Colors::PINK);
        }
        else if (color=="Brown"){
            square.SetColor (Colors::BROWN);
        }
        else if (color=="Grey"){
            square.SetColor (Colors::GREY);
        }
        else {
            square.SetColor (Colors::NONE);
        }

        if (square.GetColor()==Colors::WHITE){
            std::cout<<"Color quadrant: White\n";
        }
        else if (square.GetColor()==Colors::BLACK){
            std::cout<<"Color quadrant: Black\n";
        }
        else if (square.GetColor()==Colors::RED){
            std::cout<<"Color quadrant: Red\n";
        }
        else if (square.GetColor()==Colors::YELLOW){
            std::cout<<"Color quadrant: Yellow\n";
        }
        else if (square.GetColor()==Colors::ORANGE){
            std::cout<<"Color quadrant: Orange\n";
        }
        else if (square.GetColor()==Colors::GREEN){
            std::cout<<"Color quadrant: Green\n";
        }
        else if (square.GetColor()==Colors::BLUE){
            std::cout<<"Color quadrant: Blue\n";
        }
        else if (square.GetColor()==Colors::PURPLE){
            std::cout<<"Color quadrant: Purple\n";
        }
        else if (square.GetColor()==Colors::PINK){
            std::cout<<"Color quadrant: Pink\n";
        }
        else if (square.GetColor()==Colors::BROWN){
            std::cout<<"Color quadrant: Brown\n";
        }
        else if (square.GetColor()==Colors::GREY){
            std::cout<<"Color quadrant: Grey\n";
        }
        else if (square.GetColor()==Colors::NONE) {
            std::cout<<"Color quadrant: None\n";
        }

        std::cout<<"Square quadrant: "<<square.GetSquare()<<"\n";
        std::cout<<"Perimetr:\n";
        std::cout<<"Point A X="<<(square.GetX()-square.GetLength()/2)-0.1<<" Y="<<(square.GetY()-square.GetLength()/2)-0.1<<"\n";
        std::cout<<"Point B X="<<(square.GetX()-square.GetLength()/2)-0.1<<" Y="<<(square.GetY()+square.GetLength()/2)+0.1<<"\n";
        std::cout<<"Point C X="<<(square.GetX()+square.GetLength()/2)+0.1<<" Y="<<(square.GetY()+square.GetLength()/2)+0.1<<"\n";
        std::cout<<"Point D X="<<(square.GetX()+square.GetLength()/2)+0.1<<" Y="<<(square.GetY()-square.GetLength()/2)-0.1<<"\n";
    }

    if (figure == "Rectangle"){
        std::cout<<"Coordinate centr X and Y:\n";
        rectangle.SetX();
        rectangle.SetY();
        std::cout<<"Side length rectangle:\n";
        rectangle.SetLength();
        std::cout<<"Side heingth rectangle:\n";
        rectangle.SetHeingth();
        std::cout<<"Input color rectangle (White, Black, Red, Yellow, Orange, Green, Blue, Purple, Pink, Brown, Grey):\n";
        std::cin>>color;

        if (color=="White"){
            rectangle.SetColor(Colors::WHITE);
        }
        else if (color=="Black"){
            rectangle.SetColor (Colors::BLACK);
        }
        else if (color=="Red"){
            rectangle.SetColor (Colors::RED);
        }
        else if (color=="Yellow"){
            rectangle.SetColor (Colors::YELLOW);
        }
        else if (color=="Orange"){
            rectangle.SetColor (Colors::ORANGE);
        }
        else if (color=="Green"){
            rectangle.SetColor (Colors::GREEN);
        }
        else if (color=="Blue"){
            rectangle.SetColor (Colors::BLUE);
        }
        else if (color=="Purple"){
            rectangle.SetColor (Colors::PURPLE);
        }
        else if (color=="Pink"){
            rectangle.SetColor (Colors::PINK);
        }
        else if (color=="Brown"){
            rectangle.SetColor (Colors::BROWN);
        }
        else if (color=="Grey"){
            rectangle.SetColor (Colors::GREY);
        }
        else {
            rectangle.SetColor (Colors::NONE);
        }

        if (rectangle.GetColor()==Colors::WHITE){
            std::cout<<"Color rectangle: White\n";
        }
        else if (rectangle.GetColor()==Colors::BLACK){
            std::cout<<"Color rectangle: Black\n";
        }
        else if (rectangle.GetColor()==Colors::RED){
            std::cout<<"Color rectangle: Red\n";
        }
        else if (rectangle.GetColor()==Colors::YELLOW){
            std::cout<<"Color rectangle: Yellow\n";
        }
        else if (rectangle.GetColor()==Colors::ORANGE){
            std::cout<<"Color rectangle: Orange\n";
        }
        else if (rectangle.GetColor()==Colors::GREEN){
            std::cout<<"Color rectangle: Green\n";
        }
        else if (rectangle.GetColor()==Colors::BLUE){
            std::cout<<"Color rectangle: Blue\n";
        }
        else if (rectangle.GetColor()==Colors::PURPLE){
            std::cout<<"Color rectangle: Purple\n";
        }
        else if (rectangle.GetColor()==Colors::PINK){
            std::cout<<"Color rectangle: Pink\n";
        }
        else if (rectangle.GetColor()==Colors::BROWN){
            std::cout<<"Color rectangle: Brown\n";
        }
        else if (rectangle.GetColor()==Colors::GREY){
            std::cout<<"Color rectangle: Grey\n";
        }
        else if (rectangle.GetColor()==Colors::NONE) {
            std::cout<<"Color rectangle: None\n";
        }

        std::cout<<"Square rectangle: "<<rectangle.GetSquare()<<"\n";
        std::cout<<"Perimetr:\n";
        std::cout<<"Point A X="<<(rectangle.GetX()-rectangle.GetLength()/2)-0.1<<" Y="<<(rectangle.GetY()-rectangle.GetHeingth()/2)-0.1<<"\n";
        std::cout<<"Point B X="<<(rectangle.GetX()-rectangle.GetLength()/2)-0.1<<" Y="<<(rectangle.GetY()+rectangle.GetHeingth()/2)+0.1<<"\n";
        std::cout<<"Point C X="<<(rectangle.GetX()+rectangle.GetLength()/2)+0.1<<" Y="<<(rectangle.GetY()+rectangle.GetHeingth()/2)+0.1<<"\n";
        std::cout<<"Point D X="<<(rectangle.GetX()+rectangle.GetLength()/2)+0.1<<" Y="<<(rectangle.GetY()-rectangle.GetHeingth()/2)-0.1<<"\n";
    }
}