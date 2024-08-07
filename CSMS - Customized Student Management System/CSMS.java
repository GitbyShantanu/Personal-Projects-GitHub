//Full Application of Customized Student Management System Using Data Structures in Java.

class node
{
    private static int Counter = 1;

    public int Rno;
    public String Name;
    public String City;
    public int Marks;

    public node next;

    public node(String B, String C, int D)
    {
        Rno = Counter;
        Counter++;

        Name = B;
        City = C;
        Marks = D;

        next = null;
    }
}

class DBMS
{
    private node first;

    public DBMS()
    {
        first = null;

        System.out.println("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        System.out.println("\n-------------Customised Student Management System---------------\n");
        System.out.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");

        System.out.println("DBMS initailised succesfully...");
        System.out.println("Student Table gets created succesfully...");
    }

    // InsertLast
    //1. insert into table student values(1,'Amit','Pune',89);
    public void InsertIntoTable(String Name, String City, int Marks)
    {
        System.out.println("\nQUERY: Insert into student values("+Name+","+City+","+Marks+");");
        node newn = new node(Name,City,Marks);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        System.out.println("One record gets inserted succesfully...");
    }

    // Display
    //2. select * from student;
    public void SelectStarFrom()
    {   
        System.out.println("\nQUERY : Select * from student;");
        System.out.println("Data from the student table is : ");

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

    //3. select * from student where city = '_____';
    public void SelectStarFromWhereCity(String str)
    {
        System.out.println("\nQUERY : Select * from student where city = "+str+";");
        System.out.println("Data from the student table where city is : "+str);

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(str.equals(temp.City))
            {
                System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            }
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

    //4. select * from student where Name = '_____';
    public void SelectStarFromWhereName(String str)
    {
        System.out.println("\nQUERY : Select * from student where Name = "+str+";");
        System.out.println("Data from the student table where Name is : "+str);

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(str.equals(temp.Name))
            {
                System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            }
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

    //5. select Count(Rno) from student;
    public void SelectCount()
    {
        System.out.println("\nQUERY : Select Count(Rno) from student;");
        node temp = first;
        int iCnt = 0;

        while(temp != null)
        {
            temp = temp.next;
            iCnt++;
        }
        System.out.println("Number of records in the table : "+iCnt);
    }

    //6. Select Sum(Marks) from student;
    public void SelectSum()
    {
        System.out.println("\nQUERY : Select Sum(Marks) from student;");
        int iSum = 0;
        node temp = first;
        while(temp != null)
        {
            iSum = iSum + temp.Marks;
            temp = temp.next;
        }
        System.out.println("Sum of Marks from student table is : "+iSum);
    }

    //7. Select Average(Marks) from student;
    public void SelectAvg()
    {
        System.out.println("\nQUERY : Select Average(Marks) from student;");
        node temp = first;
        int iSum = 0, iCnt = 0;
        float fAvg = 0.0f;

        while(temp != null)
        {
            iCnt++;
            iSum = iSum + temp.Marks;
            temp = temp.next;
        }

        fAvg = (float)(iSum/iCnt);
        System.out.println("Average of Marks in Student table is : "+fAvg);
    }

    //8. Select Min(Marks) from Student;
    public void SelectMin()
    {
        System.out.println("\nQUERY : Select Min(Marks) from student;");
        node temp = first;
        int iMin = 0;

        if(first != null)
        {
            iMin = temp.Marks;
        }

        while(temp != null)
        {
            if(temp.Marks < iMin)
            {
                iMin = temp.Marks;
            }
            temp = temp.next;
        }
        System.out.println("Minimum marks from Student table is : "+iMin);
    }

    //9. Select Max(Marks) from Student;
    public void SelectMax()
    {
        System.out.println("\nQUERY : Select Max(Marks) from student;");
        node temp = first;
        int iMax = 0;

        if(first != null)
        {
            iMax = temp.Marks;
        }

        while(temp != null)
        {
            if(temp.Marks > iMax)
            {
                iMax = temp.Marks;
            }
            temp = temp.next;
        }
        System.out.println("Maximum marks from Student table is : "+iMax);
    }

    //10. Update student set city = "____" where Rno = "__";
    public void UpdateCity(int no,String str)
    {
        System.out.println("\nQUERY : Update student set city = "+str+" where Rno = "+no+";");
        node temp = first;

        while(temp != null)
        {
            if(temp.Rno == no)
            {
                temp.City = str;
            }
            temp = temp.next;
        }
        System.out.println("Student table gets updated at Rno = "+no+"...");
    }

    //11. Delete from student where Rno = "__";
    public void Deletefrom(int no)
    {
        System.out.println("\nQUERY : Delete from student where Rno = "+no+";");
        node temp = first;

        if(temp == null)    //if LL is empty.
        {
            return;
        }
        else if(temp.Rno == no)  //if Rno is 1.
        {
            first = first.next;
            return;
        }
        else
        {
            while(temp != null)
            {
                if(temp.next.Rno == no)
                {
                    temp.next = temp.next.next;
                    break;
                }
                temp = temp.next;
            }
        }
        System.out.println("One Record from student at Rno : "+no+" gets deleted...");
    }
}

class CSMS
{
    public static void main(String Arg[])
    {
        DBMS obj = new DBMS();

        obj.InsertIntoTable("Amit","Pune",89);
        obj.InsertIntoTable("Pooja","Mumbai",95);
        obj.InsertIntoTable("Gauri","Pune",90);
        obj.InsertIntoTable("Rahul","Satara",80);
        obj.InsertIntoTable("Neha","Pune",78);

        obj.SelectStarFrom();
        obj.SelectStarFromWhereCity("Pune");
        obj.SelectStarFromWhereName("Amit");

        obj.SelectCount();  //Aggregate functions from SQL
        obj.SelectSum();
        obj.SelectAvg();
        obj.SelectMin();
        obj.SelectMax();

        obj.UpdateCity(3,"Nashik");
        obj.SelectStarFrom();

        obj.Deletefrom(4);
        obj.SelectStarFrom();

        obj.InsertIntoTable("Ajay","Goa",99);
        obj.SelectStarFrom();
    }
}

/*
Supported Queries

1 : Insert into student values('Amit','Pune',78);
2 : Select * from student;
3 : Select *  from student where City = "Pune";
4 : Select *  from student where Name = "Amit";
5 : Select Count(Rno) from student;
6 : Select Sum(Marks) from student;
7 : Select Average(Marks) from student;
8 : Select Min(Marks) from student;
9 : Select Max(Marks) from student;
10 : Update student set city = "______" where Rno = "__";
11 : Delete from student where Rno = "__";

*/