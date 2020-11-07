
import java.io.*;
import java.net.*;

public class Multisimplechatclient {
	public static void main(String[] args) {
		Socket cSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		String serverIp = args[0];
		int port = Integer.parseInt(args[1]);
		try {
			cSock = new Socket(serverIp, port);
			Thread th = new Thread(new ChatReceiverThread(cSock));
			th.start();
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(cSock.getOutputStream()));
			String strOut = null;
			System.out.println("Client is running.");
			while (true) {
				strOut = in.readLine();
				out.write(strOut + "\n");
				out.flush();
				System.out.println("[" + cSock.getLocalAddress() + ":" + cSock.getLocalPort() + "] " + strOut);
				if (strOut.trim().equals("quit"))
					break;
			}
			cSock.close();
			System.out.println("TCP Client is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
