package packerunpacker;

import java.io.*;

public class Packer
{
    public Packer(String DirectoryName, String PackedFile) throws Exception
    {
        File fobj = new File(DirectoryName);
        if(!fobj.isDirectory())
        {
            System.out.println("Invalid Directory.");
            return;
        }

        FileOutputStream fcombine = new FileOutputStream(PackedFile);
        File Arr[] = fobj.listFiles();

        for(File file : Arr)
        {
            String Header = file.getName() + " " + file.length();
            while(Header.length() < 100) Header += " ";

            fcombine.write(Header.getBytes());

            FileInputStream fiobj = new FileInputStream(file);
            byte Buffer[] = new byte[1024];
            int iRet;
            while((iRet = fiobj.read(Buffer)) != -1)
            {
                fcombine.write(Buffer, 0, iRet);
            }
            fiobj.close();
        }

        fcombine.close();
        System.out.println("Packing Completed.");
    }
}
