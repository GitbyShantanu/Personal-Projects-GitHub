import java.io.*;
import java.net.*;

class Server
{
    public static void main(String args[]) throws Exception
    {
        System.out.println("\n---------------------------------------------------------------");
        System.out.println("Server of Chat Messanger is running...\n");

        ServerSocket ssobj = new ServerSocket(2100);
        System.out.println("Server is in Listening mode at port : 2100");

        Socket sobj = ssobj.accept();
        System.out.println("Client and server connection is successfull.\n");

        PrintStream ps = new PrintStream(sobj.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Chat messanger is started...\n");

        String str1,str2;

        while (true)
        {
            str1 = br1.readLine();
            System.out.println("Client says : "+str1);
            if(str1 == null)
            {
                System.out.println("");
                break;
            }

            System.out.println("Enter messege for Client : ");
            str2 = br2.readLine();
            ps.println(str2);
        }

        System.out.println("Thank you for using Chat Messanger...");
        System.out.println("\n---------------------------------------------------------------\n");

        ssobj.close();
        sobj.close();
        ps.close();
        br1.close();
        br2.close();
    }
}