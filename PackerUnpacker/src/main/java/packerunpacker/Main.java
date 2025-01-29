package packerunpacker;

import java.util.Scanner;

public class Main
{
    public static void main(String args[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("1. Pack Files");
        System.out.println("2. Unpack Files");
        System.out.print("Choose an option: ");
        int choice = sobj.nextInt();
        sobj.nextLine(); // Consume the newline

        if(choice == 1)
        {
            System.out.print("Enter Directory Name: ");
            String dir = sobj.nextLine();
            System.out.print("Enter Packed File Name: ");
            String packedFile = sobj.nextLine();
            Packer packer = new Packer(dir, packedFile);
        }
        else if(choice == 2)
        {
            System.out.print("Enter Packed File Name: ");
            String packedFile = sobj.nextLine();
            Unpacker unpacker = new Unpacker(packedFile);
        }
        else
        {
            System.out.println("Invalid choice.");
        }

        sobj.close();
    }
}
