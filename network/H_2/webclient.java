import java.io.*;
import java.net.*;

public class webclient {
	
	public static void main(String[] args) {
		Socket cSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		String serverIp = args[0];
		int port = 80;

		try {
			cSock = new Socket(serverIp, port);
			in = new BufferedReader(new InputStreamReader(cSock.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(cSock.getOutputStream()));
			System.out.println("Client is running.");
			out.write("GET / HTTP/1.1\\r\n");
			out.write( "Host: www.hanbit.co.kr\r\n");
			out.write( "\r\n");
			out.flush();
			int strIn = in.read();
			char str = (char)strIn;
			while (strIn != -1) {
				System.out.print(str);
	            strIn = in.read();
				str = (char)strIn;
			}
			cSock.close();
			System.out.println("TCP Client is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}