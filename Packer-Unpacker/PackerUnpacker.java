//Complete Packer-Unpacker Project.

import java.io.*;
import java.util.*;

class PackerUnpacker
{   
    public static void Packer() throws Exception
    {
        System.out.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        System.out.println("--------------------------  Welcome to Packer ------------------------------");
        System.out.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

        Scanner sobj = new Scanner(System.in);
        boolean bret = false;

        System.out.print("Enter name of Directory which contains all files that you want to pack: ");
        String DirectoryName = sobj.nextLine();

        System.out.print("Enter name of packed file that you want to create : ");
        String PackedFile = sobj.nextLine();

        File fobjPack = new File(PackedFile);

        bret = fobjPack.createNewFile();
        if(bret == false)
        {
            System.out.println("Unable to create packed file...");
            return;
        }

        System.out.println("Packed file gets succesfully created in current directory.");

        File fobj = new File(DirectoryName);

        bret = fobj.isDirectory();
        if(bret == true)
        {
            File Arr[] = fobj.listFiles();
            System.out.println("Number of files in the directory are : "+Arr.length);

            String Header = null;

            // To write the data into packed file
            FileOutputStream fcombine = new FileOutputStream(PackedFile);
            int iRet = 0;
            byte Buffer[] = new byte[1024];
            
            System.out.println("Packing activity started...");

            // Travel Directory
            for(int i = 0; i < Arr.length; i++)
            {
                // Create header
                Header = Arr[i].getName() + " " + Arr[i].length();
                System.out.println("File packed with the name : "+Arr[i].getName());

                // Add extra white spaces at the end of header
                for(int j = Header.length(); j < 100; j++)
                {
                    Header = Header + " ";
                }

                // Convert string header into byte array
                byte hArr[] = Header.getBytes();

                // Write header into packed file
                fcombine.write(hArr,0,100);

                // To read the file from directory
                FileInputStream fiobj = new FileInputStream(Arr[i]);

                // write the data into packed file after header
                while((iRet = fiobj.read(Buffer)) != -1 )
                {
                    fcombine.write(Buffer,0,iRet);
                }
                fiobj.close();
            }

            System.out.println("Packing activity completed..");
            System.out.println("Total file packed succesfully : "+Arr.length);
                        
            System.out.println("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            System.out.println("----------------------- Thank you for using Packer -------------------------");
            System.out.println("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
        }
        else 
        {
            System.out.println("There is no such directory");
        }
    }

    public static void Unpacker() throws Exception
    {
        System.out.println();
        System.out.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        System.out.println("-------------------------- Welcome to UnPacker -----------------------------");
        System.out.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

        Scanner sobj = new Scanner(System.in);
        
        int iRet = 0, iCnt = 0;
        byte bHeader[] = new byte[100];
        byte Buffer[] = new byte[1024];

        System.out.print("Enter the name of packed file that you want to unpack : ");
        String PackedFile = sobj.nextLine();

        File fobj = new File(PackedFile);
        FileInputStream fiobj = new FileInputStream(fobj);

        while((iRet = fiobj.read(bHeader,0,100)) > 0)
        {
            String hstr = new String(bHeader);

            hstr = hstr.trim();
            String Token[] = hstr.split(" ");

            System.out.println("File Name is : "+Token[0]);
            System.out.println("File Size is : "+Token[1]);

            File newfileobj = new File(Token[0]);
            newfileobj.createNewFile();

            int FileSize = Integer.parseInt(Token[1]);

            fiobj.read(Buffer,0,FileSize);

            FileOutputStream foobj = new FileOutputStream(newfileobj);
            foobj.write(Buffer,0,FileSize);

            iCnt++;
            System.out.println(Token[0]+" unpacked successfully.");
            System.out.println("----------------------------------------------------------------------------");
        }
        System.out.println("Unpacking activity completed.");
        System.out.println("Total Number Files unpacked is : "+iCnt);

        System.out.println("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
        System.out.println("------------------ Thank you for using Packer UnPacker ---------------------");
        System.out.println("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");

    }

    public static void main(String args[])
    {   
        try
        {
            Packer();
            Unpacker();
        }
        catch(IOException ioeobj)
        {
            System.out.println(ioeobj+" Exception Handled.");
        }
        catch(Exception eobj)
        {
            System.out.println(eobj+" Exception Handled.");
        }
    }
}
