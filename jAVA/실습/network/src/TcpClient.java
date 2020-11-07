import java.io.*;
import java.net.*;

public class TcpClient {
	
	public static void main(String[] args) {
		Socket cSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		String serverIp = args[0];
		int port = Integer.parseInt(args[1]);
		try {
			cSock = new Socket(serverIp, port);
			in = new BufferedReader(new InputStreamReader(cSock.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(cSock.getOutputStream()));
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String strOut = null;
			System.out.println("Client is running.");
			System.out.println("input your message");
			while (true) {
				strOut = br.readLine();
				out.write(strOut + "\n");
				System.out.println("[Client" + cSock.getLocalAddress() + ":" + cSock.getLocalPort() + "] " + strOut );
				out.flush();
				if (strOut.trim().equals("quit"))
					break;
				String strIn = in.readLine();
				System.out.println("[Server" + cSock.getInetAddress() + ":" + cSock.getPort() + "] " + strIn);
			}
			cSock.close();
			System.out.println("TCP Client is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}