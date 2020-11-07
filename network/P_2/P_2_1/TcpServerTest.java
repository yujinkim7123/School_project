import java.io.*;
import java.net.*;

public class TcpServerTest {
	public static void main(String[] args) { 
	ServerSocket listener = null;
	Socket sSock = null;
	int sPort = 80;
	try{
		listener = new ServerSocket(sPort);
		System.out.println("Server is running.");
		while (true) {
			sSock = listener.accept();
			System.out.println("Client is connected");
			Thread th = new Thread(new ServerThread(sSock));
			th.start();
		}
	}catch(Exception e)
	{
		System.out.println(e);
	}
}

}
