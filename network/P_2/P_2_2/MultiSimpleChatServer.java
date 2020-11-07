import java.io.*;
import java.net.*;

public class MultiSimpleChatServer {
	public static void main(String[] args) {
		ServerSocket listener = null;
		Socket sSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		int sPort = Integer.parseInt(args[0]);
		try {
			listener = new ServerSocket(sPort);
			System.out.println("Server is running.");
			sSock = listener.accept();
			System.out.println("Client is connected");
			Thread th = new Thread(new ChatReceiverThread(sSock));
			th.start();
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(sSock.getOutputStream()));
			while (true) {
				String strOut = in.readLine();
				out.write(strOut + "\n");
				out.flush();
				System.out.println("[" + sSock.getLocalAddress() + ":" + sSock.getLocalPort() + "] " + strOut);
				if (strOut.trim().equals("quit"))
					break;
			}
			sSock.close();
			listener.close();
			System.out.println("TCP Server is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
