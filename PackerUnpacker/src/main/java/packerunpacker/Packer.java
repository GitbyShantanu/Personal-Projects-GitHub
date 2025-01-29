package packerunpacker;

import java.io.*; 

public class Packer 
{
    public Packer(String DirectoryName, String PackedFile) throws Exception 
    {
        // Create File object for the directory
        File fobj = new File(DirectoryName);

        // Check if it's a valid directory
        if (!fobj.isDirectory()) 
        {
            System.out.println("Invalid Directory.");
            return;
        }

        // Create FileOutputStream for writing header and data into packed file // (combine.txt)
        // This also creates the newfile (packedfile).
        FileOutputStream fcombine = new FileOutputStream(PackedFile);

        // Get list of files in the directory(this returns File array)
        File Arr[] = fobj.listFiles();

        for (File file : Arr) // Iterate through each file
        {
            // Create header with filename and size
            String Header = file.getName() + " " + file.length();
            
            while (Header.length() < 100)
            {
                Header = Header + " "; // Pad header to 100 characters
            } 

            // Write header to packed file in byte[] array format.
            fcombine.write(Header.getBytes());

            // Create FileInputStream for reading the current file.
            FileInputStream fiobj = new FileInputStream(file);

            // Create buffer for reading file content
            byte Buffer[] = new byte[1024];
            int iRet = 0;

            // Read file content and write to packed file until it reaches end of file
            while ((iRet = fiobj.read(Buffer)) != -1) 
            {
                fcombine.write(Buffer, 0, iRet);
            }
            
            fiobj.close(); // Close FileInputStream 
            // for next file in Arr, we will create FIS again thats why we release FIS here.  
        }

        // Close the FileOutputStream to ensure all data is written to the file,
        // release system resources, and unlock the file for other processes.
        fcombine.close(); 

        System.out.println("Packing Completed.");
    }
}