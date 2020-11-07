import java.io.*;
import java.net.*;

public class TcpServer {
	
	public static void main(String[] args) {
		ServerSocket listener = null;
		Socket sSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		InetAddress clientIp;
		int cPort, sPort = Integer.parseInt(args[0]);
		try {
			listener = new ServerSocket(sPort);
			System.out.println("Server is running.");
			sSock = listener.accept();
			System.out.println("Client is connected");
			in = new BufferedReader(new InputStreamReader(sSock.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(sSock.getOutputStream()));
			while (true) {
				String strIn = in.readLine();
				clientIp = sSock.getInetAddress();
				cPort = sSock.getPort();
				System.out.println("[Client" + clientIp + ":" + cPort + "] " + strIn);
				if (strIn.trim().equals("quit"))
					break;
				String strOut = strIn.toUpperCase();
				out.write(strOut + "\n");
				out.flush();
			}
			sSock.close();
			listener.close();
			System.out.println("TCP Server is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
