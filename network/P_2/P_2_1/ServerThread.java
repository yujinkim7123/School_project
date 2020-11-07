import java.io.*;
import java.net.*;

public class ServerThread implements Runnable {
	Socket sSock;

	public ServerThread(Socket sock) {
		this.sSock = sock;
	}

	public void run() {
		BufferedReader in = null;
		BufferedWriter out = null;
		InetAddress clientIp;
		int cPort;
		try {
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
			System.out.println("TCP Socket is Closed.");

		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
