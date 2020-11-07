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
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String strOut = null;
			while (true) {
				String strIn = in.readLine();
				clientIp = sSock.getInetAddress();
				cPort = sSock.getPort();
				System.out.println("[Client" + clientIp + ":" + cPort + "] " + strIn);
				if (strIn.trim().equals("quit"))
					break;
				strOut = br.readLine();
				out.write(strOut + "\n");
				System.out.println("[Server" + sSock.getLocalAddress() + ":" + sSock.getLocalPort() + "] " + strOut );
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
