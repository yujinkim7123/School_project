
import java.io.*;
import java.net.*;

public class TcpServer {

	public static void main(String[] args) {

		ServerSocket listener = null;
		Socket sSock = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		int sPort = 80;
		DataOutputStream out2 = null;
		FileInputStream fis = null;
		try {
			listener = new ServerSocket(sPort);
			System.out.println("Server is running.");
			int data;
			while (true) {
				sSock = listener.accept();
				in = new BufferedReader(new InputStreamReader(sSock.getInputStream()));
				out = new BufferedWriter(new OutputStreamWriter(sSock.getOutputStream(), "utf-8"));
				out2 = new DataOutputStream(sSock.getOutputStream());
				System.out.println("Client is connected");
				
				String strIn = in.readLine();
				if (strIn == null || strIn.equals("\r\n")) {
					sSock.close();
					System.out.println("TCP Server is Closed.");
					continue;
				}

				int idx = strIn.indexOf('/');
				String str = strIn.substring(idx + 1);
				int idx2 = str.indexOf(' ');
				String result = str.substring(0, idx2);
				try {
					fis = new FileInputStream(result);
					if (result.equals("index.html")) {
						out.write("HTTP/1.1 200 OK\r\n");
						out.write("Contnet-Type: " + "text/html" + "\r\n");
						out.write("\r\n");
						out.flush();
						while ((data = fis.read()) != -1) {
							out2.write(data);
						}
						out2.close();
					} else if (result.equals("iot.png")) {
						out.write("HTTP/1.1 200 OK\r\n");
						out.write("Content-Type:image/png\r\n");
						out.write("\r\n");
						out.flush();
						while ((data = fis.read()) != -1) {
							out2.write(data);
						}
						out2.close();
					}
				} catch (FileNotFoundException e) {
					out.write("HTTP/1.1 404 Not Found\r\n");
					out.write("\r\n");
					out.write("<HTML><HEAD><TITLE>Not Found</TITLE></HEAD>");
					out.write("<BODY>Not Found</BODY></HTML>");
					out.flush();
					out2.close();
				}
                //out.flush();
                // out2.close();
				sSock.close();
				System.out.println("TCP Server is Closed.");
			}
			// listener.close();
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
