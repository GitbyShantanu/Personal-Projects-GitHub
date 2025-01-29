package packerunpacker;

import java.io.*;

public class Unpacker
{
    public Unpacker(String PackedFile) throws Exception
    {
        FileInputStream fiobj = new FileInputStream(PackedFile);
        byte bHeader[] = new byte[100];
        byte Buffer[] = new byte[1024];

        while(fiobj.read(bHeader) > 0)
        {
            String hstr = new String(bHeader).trim();
            String Token[] = hstr.split(" ");
            String fileName = Token[0];
            int fileSize = Integer.parseInt(Token[1]);

            FileOutputStream foobj = new FileOutputStream(fileName);
            fiobj.read(Buffer, 0, fileSize);
            foobj.write(Buffer, 0, fileSize);
            foobj.close();

            System.out.println(fileName + " Unpacked.");
        }

        fiobj.close();
        System.out.println("Unpacking Completed.");
    }
}
