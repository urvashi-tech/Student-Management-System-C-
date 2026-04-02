# Student-Management-System-C-

 **1. Introduction**

This project is a Student Management System developed using C++. It is designed to store and manage student details such as ID, Name, Marks, and Course. The system uses Object-Oriented Programming (OOP) concepts like encapsulation, inheritance, and polymorphism. It provides a menu-driven interface for performing various operations efficiently.


 **2. Objectives of the Project**

* To understand Object-Oriented Programming concepts in C++
* To implement a real-world student management system
* To practice arrays, loops, and conditional statements
* To apply concepts like searching, sorting, and stack operations
* To improve logical thinking and problem-solving skills

---

 **3. Methodology / System Design**

**Working Process**

1. The program displays a menu with multiple options.
2. The user selects an operation.
3. The system performs the required action.
4. The process continues until the user exits.



 **System Features**

* Add Student details
* Display all students
* Search student by ID
* Delete student record
* Undo last deleted record (using stack)
* Sort students by marks (Ascending / Descending)



 **Data Storage**

* Student data is stored using **array of objects**
* Stack is used for **Undo Delete operation**
* Variable `n` keeps track of total students



 **4. OOP Concepts Used**

  **Encapsulation**

* Data members (id, name, marks, course) are declared inside a class
* Access is controlled using public functions like `setData()` and `display()`


 **Inheritance**

```cpp
class StudentSystem : public Student
```

* StudentSystem class inherits properties of Student class
* Enables code reusability



### **Polymorphism**

* Function overloading is used in sorting:

cpp
void sortStudent()
void sortStudent(bool ascending)


* Same function name with different behavior



## **5. Implementation / Source Code Explanation**

### **Class Structure**

* `Student` class → stores data and basic operations
* `StudentSystem` class → manages all student records



### **Add Student**

* Takes input using `setData()`
* Stores in array of objects
* Increments count `n`



### **Display Students**

* Loop runs from `0` to `n-1`
* Displays all student records



### **Search Student**

* Takes ID as input
* Linear search is applied
* Displays record if found



### **Delete Student**

* Searches student by ID
* Stores deleted record in stack
* Shifts remaining elements



### **Undo Delete**

* Uses stack (LIFO)
* Restores last deleted student



### **Sorting**

* Bubble sort is used
* Can sort in:

  * Ascending order
  * Descending order



## **6. Conclusion**

This project helped in understanding advanced C++ concepts such as Object-Oriented Programming, arrays, searching, sorting, and stack operations. It demonstrates how a real-world system can be developed using programming logic. The project can be further improved by adding file handling, GUI interface, and database integration.

