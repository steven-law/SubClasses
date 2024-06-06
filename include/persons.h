#include <Arduino.h>
#include <date.h>

class Person
// Attributes and methods that are declared as "private"
// in the superclass are not accessible in the subclass.
// If you declare attributes/methods as “protected”,
// subclasses can access them, but not “foreign” classes
{
public:
    byte myID;
    byte Potentiometer[16];
    const char *SurName;
    const char *FirstName;
    byte DayOfBirth;
    byte MonthOfBirth;
    int YearOfBirth;
    // Constructor
    Person(const char *sName, const char *fName)
    {
        SurName = sName;
        FirstName = fName;
    }
    const char *getSurName() { return SurName; }
    const char *getFirstName() { return FirstName; }

    virtual void set_myID(byte id) { myID = id; }
    virtual byte get_myID() { return myID; }
    virtual void set_Potentiometer(byte n, byte v) { Potentiometer[n] = v; }
    virtual byte get_Potentiometer(byte n) { return Potentiometer[n]; }
    virtual void print_Potentiometer(byte n) { Serial.printf("PotiNr %d is %d\n", n, Potentiometer[n]); }

    virtual void printName()
    {
        // Serial.print("Surname: ");
        // Serial.print(SurName);
        // Serial.print("  Firstname: ");
        // Serial.println(FirstName);
        Serial.printf("SurName: %s, FirstName: %s\n", SurName, FirstName);
    }
};

class Student : public Person
// Student is declared as a subclass of Person
// The keyword “public” means that all methods (and, if applicable, attributes)
// declared as public in the superclass are also public in the subclass.
{
public:
    int sinceYear;
    Date Studienbeginn;
    Student(const char *sName, const char *fName, int sYear, int t, int m, int j) : Person(sName, fName), Studienbeginn(t, m, j)
    // Note that the subclass constructor must call the superclass constructor
    //(at least if there is no default superclass constructor).
    {
        sinceYear = sYear;
    }
    int getSinceYear() { return sinceYear; }
};

class Professor : public Person
{
public:
    byte department;
    Professor(const char *sName, const char *fName, byte dept) : Person(sName, fName)
    {
        department = dept;
    }
    byte getDepartment() { return department; }
    void printName()
    // You can redefine a function in a subclass that is already defined in the superclass. "Override", “Redefinition”
    /*
          When the compiler calls a method f() for an object of class C,
          it first checks whether f() is defined in this class.
          If so, it takes this implementation of f().

          Otherwise, it checks whether f() is defined in the superclass B of C.
          If so, it takes the implementation defined there.

          Otherwise, it climbs further up the class hierarchy,
          and if necessary, it reports the method as undefined at the end.
    */
    {
        Person::printName();
        /*  C++ allows functions with the same name,
            but different argument types.

            A function is only overwritten in the subclass
            if you define a function there with:
              +  the same name,
              +  the same number of parameters and the same
              +  parameter types, and
              +  the same result type.

            Otherwise: Two functions in the subclass.
        */
        Serial.printf("Professor in Department %d\n", department);
    }
};
