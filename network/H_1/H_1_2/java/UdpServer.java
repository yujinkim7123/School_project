import java.net.*;
import java.io.*;

public class UdpServer {
	public static void main(String[] args) {
		DatagramSocket sSock;
		DatagramPacket sPkt;
		DatagramPacket rPkt;
		InetAddress clientIp;
		int cPort, sPort = Integer.parseInt(args[0]);
		
		try {
			sSock = new DatagramSocket(sPort);
			System.out.println("Server is running");
			
			while(true) {
				byte[] buffer = new byte[1024];
				
				rPkt = new DatagramPacket(buffer, buffer.length);
				sSock.receive(rPkt);
				
				String strIn  = new String(rPkt.getData(), 0, rPkt.getLength());
				clientIp = rPkt.getAddress();
				cPort = rPkt.getPort();
				
				System.out.println("[Client" + clientIp + ":" + cPort + "]" + strIn);
				if(strIn.trim().equals("quit"))
					break;
				
				String strOut = strIn.toUpperCase();
				sPkt = new DatagramPacket( strOut.getBytes(), strOut.getBytes().length, clientIp, cPort );
				sSock.send(sPkt);

			}
			sSock.close();
			System.out.println("UDP Sever is Closed.");
		}catch(Exception e) {
			System.out.println(e);
			
			}
		}
	}

