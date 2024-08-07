# Customized Student Management System (CSMS)

Welcome to the Customized Student Management System (CSMS), a robust application developed in Java using custom data structures. This project showcases the implementation of various student-related database operations using linked lists to manage student records efficiently.

## Features

- **Insertion of Records:** Add new student records to the database with unique roll numbers.
- **Display All Records:** View all student records in the database.
- **Filter by City:** Retrieve student records based on the city.
- **Filter by Name:** Retrieve student records based on the name.
- **Aggregate Functions:**
  - **Count:** Count the total number of student records.
  - **Sum:** Calculate the total marks of all students.
  - **Average:** Compute the average marks of students.
  - **Minimum:** Find the student with the lowest marks.
  - **Maximum:** Find the student with the highest marks.
- **Update Records:** Update the city of a student based on the roll number.
- **Delete Records:** Delete a student record based on the roll number.

## Supported Queries

1. **Insert a Record:**
   ```java
   obj.InsertIntoTable("Name", "City", Marks);
   ```
   Example:
   ```java
   obj.InsertIntoTable("Amit", "Pune", 89);
   ```

2. **Display All Records:**
   ```java
   obj.SelectStarFrom();
   ```

3. **Filter by City:**
   ```java
   obj.SelectStarFromWhereCity("City");
   ```
   Example:
   ```java
   obj.SelectStarFromWhereCity("Pune");
   ```

4. **Filter by Name:**
   ```java
   obj.SelectStarFromWhereName("Name");
   ```
   Example:
   ```java
   obj.SelectStarFromWhereName("Amit");
   ```

5. **Count Records:**
   ```java
   obj.SelectCount();
   ```

6. **Sum of Marks:**
   ```java
   obj.SelectSum();
   ```

7. **Average of Marks:**
   ```java
   obj.SelectAvg();
   ```

8. **Minimum Marks:**
   ```java
   obj.SelectMin();
   ```

9. **Maximum Marks:**
   ```java
   obj.SelectMax();
   ```

10. **Update City:**
    ```java
    obj.UpdateCity(RollNumber, "NewCity");
    ```
    Example:
    ```java
    obj.UpdateCity(3, "Nashik");
    ```

11. **Delete a Record:**
    ```java
    obj.Deletefrom(RollNumber);
    ```
    Example:
    ```java
    obj.Deletefrom(4);
    ```

## Implementation Details

### Node Class

The `node` class represents a student record with the following attributes:
- **Roll Number (Rno):** Auto-incremented unique identifier.
- **Name:** Name of the student.
- **City:** City of the student.
- **Marks:** Marks obtained by the student.

### DBMS Class

The `DBMS` class manages the linked list of student records and provides methods to perform various operations on the data:
- **InsertIntoTable:** Inserts a new student record at the end of the list.
- **SelectStarFrom:** Displays all student records.
- **SelectStarFromWhereCity:** Filters and displays student records based on the city.
- **SelectStarFromWhereName:** Filters and displays student records based on the name.
- **SelectCount:** Counts the total number of student records.
- **SelectSum:** Calculates the sum of marks of all students.
- **SelectAvg:** Computes the average marks of students.
- **SelectMin:** Finds the student with the lowest marks.
- **SelectMax:** Finds the student with the highest marks.
- **UpdateCity:** Updates the city of a student based on the roll number.
- **Deletefrom:** Deletes a student record based on the roll number.

## Usage Example

```java
public class CSMS {
    public static void main(String[] args) {
        DBMS obj = new DBMS();

        obj.InsertIntoTable("Amit", "Pune", 89);
        obj.InsertIntoTable("Pooja", "Mumbai", 95);
        obj.InsertIntoTable("Gauri", "Pune", 90);
        obj.InsertIntoTable("Rahul", "Satara", 80);
        obj.InsertIntoTable("Neha", "Pune", 78);

        obj.SelectStarFrom();
        obj.SelectStarFromWhereCity("Pune");
        obj.SelectStarFromWhereName("Amit");

        obj.SelectCount();
        obj.SelectSum();
        obj.SelectAvg();
        obj.SelectMin();
        obj.SelectMax();

        obj.UpdateCity(3, "Nashik");
        obj.SelectStarFrom();

        obj.Deletefrom(4);
        obj.SelectStarFrom();

        obj.InsertIntoTable("Ajay", "Goa", 99);
        obj.SelectStarFrom();
    }
}
```

## Future Scope

### Enhancements
1. **Database Integration:** Integrate with a relational database management system (RDBMS) for persistent storage.
2. **Graphical User Interface (GUI):** Develop a user-friendly GUI to interact with the system.
3. **Advanced Search:** Implement more advanced search and filtering options based on multiple criteria.
4. **Sorting:** Add functionality to sort student records based on various attributes like name, marks, and city.
5. **Pagination:** Implement pagination for displaying large sets of records.
6. **Authentication:** Add user authentication and role-based access control for secure data management.

### Additional Features
1. **Data Export/Import:** Enable exporting and importing student data in various formats (e.g., CSV, Excel).
2. **Report Generation:** Implement automated report generation for summary and detailed reports.
3. **Notifications:** Add email or SMS notifications for updates and alerts.
4. **Mobile Application:** Develop a mobile application for managing student records on-the-go.

## Conclusion

The Customized Student Management System (CSMS) demonstrates the efficient management of student records using a linked list data structure in Java. This project highlights the implementation of various SQL-like operations, providing a solid foundation for further enhancements and features.

Enjoy exploring and extending this project to suit your needs!