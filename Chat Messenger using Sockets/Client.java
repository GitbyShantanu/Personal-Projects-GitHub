import java.io.*;
import java.net.*;

class DemoClient
{
    public static void main(String Arg[]) throws Exception
    {
        System.out.println("\n---------------------------------------------------------------");
        System.out.println("Client of Chat messanger is running...\n");

        Socket sobj = new Socket("localhost",2100);
        System.out.println("Client is waiting for server to accept the request..");

        if(sobj.isConnected())
        {
            System.out.println("Client and server connection is successfull.\n");

            PrintStream ps = new PrintStream(sobj.getOutputStream());

            BufferedReader br1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
            BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

            System.out.println("Chat Messanger is started...\n");

            String str1,str2;

            while (true) 
            {
                System.out.println("Enter message for server : ");
                str1 = br2.readLine();

                if (str1.equals("end")) 
                {
                    break;
                }
                ps.println(str1);
                
                str2 = br1.readLine();
                System.out.println("Server says : " + str2);
            }

            sobj.close();
            ps.close();
            br1.close();
            br2.close();
        }
        else
        {
            System.out.println("Failed to connect to server...\n");
        }
            
        System.out.println("\nThank you for using Chat Messanger...");
        System.out.println("\n---------------------------------------------------------------");
    }
}