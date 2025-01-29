package packerunpacker;

import java.io.*;

public class Unpacker 
{
    public Unpacker(String PackedFile) throws Exception 
    {
        // Open packed file for reading
        FileInputStream fiobj = new FileInputStream(PackedFile); 

        byte bHeader[] = new byte[100]; // Header buffer
        byte Buffer[] = new byte[1024]; // file Data buffer

        while (fiobj.read(bHeader) > 0) // Read header until it reaches end of file.
        { 
            String hstr = new String(bHeader).trim(); // Header string
            String Token[] = hstr.split(" "); // Split filename and size into tokens
            String fileName = Token[0]; // Filename
            int fileSize = Integer.parseInt(Token[1]); // Filesize (extract int from String)

            // This Create new unpackedfile and Open file for writing. 
            FileOutputStream foobj = new FileOutputStream(fileName);

            fiobj.read(Buffer, 0, fileSize); // Read file data from packed file
            foobj.write(Buffer, 0, fileSize); // Write file data into unpacked files respectively.

            foobj.close(); // Close output file (flush data, release resources)
            System.out.println(fileName + " Unpacked.");
        }

        fiobj.close(); // Close input file (flush data, release resources)
        System.out.println("Unpacking Completed.");
    }
}