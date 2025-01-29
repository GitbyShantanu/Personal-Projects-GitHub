package packerunpacker; // Package declaration

import java.util.Scanner;

public class Main {
    public static void main(String args[]) throws Exception //Entry point method.
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("1. Pack Files");
        System.out.println("2. Unpack Files");
        // Prompt for choice
        System.out.print("Choose an option: ");

        int choice = sobj.nextInt(); // Read choice (leaves \n in buffer)
        sobj.nextLine(); // Consume leftover \n to avoid skipping next input!

        if (choice == 1)    // Pack files
        {
            System.out.print("Enter Directory Name: ");
            String dir = sobj.nextLine();
            System.out.print("Enter Packed File Name: ");
            String packedFile = sobj.nextLine();

            Packer packer = new Packer(dir, packedFile); // Create Packer object
        } 
        else if (choice == 2) // Unpack files
        { 
            System.out.print("Enter Packed File Name: ");
            String packedFile = sobj.nextLine();

            Unpacker unpacker = new Unpacker(packedFile); // Create unpacker object
        } 
        else // Invalid choice
        { 
            System.out.println("Invalid choice.");
        }

        // Close Scanner
        sobj.close();
    }
}