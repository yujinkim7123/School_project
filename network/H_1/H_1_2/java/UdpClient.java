import java.io.*;
import java.net.*;

public class UdpClient {
	public static void main(String[] args) {
		DatagramSocket cSock;
		DatagramPacket sPkt, rPkt;
		String serverIp = args[0];
		int port = Integer.parseInt(args[1]);
		;
		try {
			cSock = new DatagramSocket();
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String strOut = null;
			System.out.println("Client is running.");
			System.out.println("Enter the word to translate into capitals");
			while ((strOut = br.readLine()) != null) {
				sPkt = new DatagramPacket(strOut.getBytes(), strOut.getBytes().length, InetAddress.getByName(serverIp),
						port);
				cSock.send(sPkt);
				if (strOut.trim().equals("quit"))
					break;
				byte[] buffer = new byte[1024];
				rPkt = new DatagramPacket(buffer, buffer.length);
				cSock.receive(rPkt);
				String strIn = new String(rPkt.getData(), 0, rPkt.getLength());
				System.out.println("[Server" + InetAddress.getByName(serverIp) + ":" + port + "] " + strIn);
			}
			cSock.close();
			System.out.println("UDP Client is Closed.");
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}