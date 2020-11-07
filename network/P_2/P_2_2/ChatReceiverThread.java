import java.io.*;
import java.net.*;

public class ChatReceiverThread implements Runnable {

	Socket sock;

	public ChatReceiverThread(Socket sock) {
		this.sock = sock;
	}

	@Override
	public void run() {
		BufferedReader in = null;
		try {
			in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			while (true) {
				String strIn = in.readLine();
				System.out.println("[" + sock.getInetAddress() + ":" + sock.getPort() + "] " + strIn);
				if (strIn.trim().equals("quit"))
					break;
			}
			System.out.println("TCP Receiver Thread is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
