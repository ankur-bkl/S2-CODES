class Pen { // blueprint
    // PROPERTIES
    String color;
    String type; // gell or ball
    // METHODS

    public void write() {
        System.out.println("writing  something");
    }

    public void printColor() {
        System.out.println(this.color);
    }

    public void printType() {
        System.out.println(this.type);
    }
}

class Student {
    String name;
    int age;
    int rollNo;

    public void printInfo() {
        System.out.println(this.name);
        System.out.println(this.age);
        System.out.println(this.rollNo);
    }
}

public class OOPS { // main function
    public static void main(String[] args) {

        // PEN 1
        Pen pen1 = new Pen(); // OBJECT ---> Pen() is a constructor use to create object
        pen1.color = "blue";
        pen1.type = "gel";
        pen1.write(); // to call the method write()
        pen1.printColor(); // to print the color

        // PEN 2
        Pen pen2 = new Pen();
        pen2.color = "black";
        pen2.type = "ball";
        pen2.printColor();
        pen2.printType();

        // STUDENT 1
        Student student1 = new Student();
        student1.name = "Ankur";
        student1.age = 21;
        student1.rollNo = 114;

        student1.printInfo();

    }

}
