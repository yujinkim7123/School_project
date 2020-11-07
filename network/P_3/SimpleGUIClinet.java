import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.*;

public class SimpleGUIClinet extends JFrame implements ActionListener {
      JLabel name = new JLabel("포트 번호"), name2 = new JLabel("IP"), name3 = new JLabel("이름");
      JTextField space1 = new JTextField(5), space2 = new JTextField(5), space3 = new JTextField(5),
    		  space4 = new JTextField(5);
      JButton click1 = new JButton("설정"), click2 = new JButton("연결"); 
      JTextArea mainspace  = new  JTextArea(11,5);
      JPanel panel1 = new JPanel(), panel2 = new JPanel(), panel3 = new JPanel();
      JScrollPane scroll;
      FlowLayout f1 = new FlowLayout();
      String port;
      int Port;
      String serverIp;
      BufferedReader br;
      ServerSocket listener = null;
      Socket cSock = null;
      BufferedReader din = null;
      BufferedWriter out = null;
      Thread th ;
      String myname = "김유진";
     boolean connect;
      // 생성자
      public SimpleGUIClinet() {
    	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
          f1.setAlignment(FlowLayout.CENTER);
          panel1.setLayout(f1);
          setTitle("IoT 톡");
          mainspace.setEditable(false); 
          scroll = new JScrollPane(mainspace);
          scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
          scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER); 
        
          panel2.setLayout(new BoxLayout(panel2, BoxLayout.Y_AXIS));
              panel1.add(name2);
              panel1.add(space4);
              panel1.add(name);
              panel1.add(space1);
              panel1.add(click2);
              panel3.add(name3);
              panel3.add(space2);
              panel3.add(click1);
              panel2.add(panel3);
              panel2.add(scroll);
              panel2.add(space3);
             
             getContentPane().add(panel1, BorderLayout.NORTH);
             getContentPane().add(panel2);
             
            
             click2.addActionListener(this);
             click1.addActionListener(this);
             space3.addActionListener(this);
            setSize(400, 300);
            setVisible(true);
      
              
      }
 
      
      class Receiver extends JTextArea implements Runnable {
         public void run() {
        	 try {
        		 
        		din = new BufferedReader(new InputStreamReader(cSock.getInputStream()));
            
        		 while (true) {
        			 String strIn = din.readLine();
        			 mainspace.append("     "+strIn + "\n");
        			 if(strIn.trim().equals("quit"))
        				 break;		 
        		 }   
        		 
         }catch(Exception e) {
   		  System.out.println(e.getMessage());
   	  }
        	 
    	  }
      }
      
    
      
      @Override
      public void actionPerformed(ActionEvent e) {
        if(e.getSource() == click2) {
         port = space1.getText();
         serverIp = space4.getText();
         int Port = Integer.parseInt(port);
         try {
            cSock = new Socket(serverIp, Port);    
            out = new BufferedWriter(new OutputStreamWriter(cSock.getOutputStream()));
            mainspace.append("서버에 연결 완료\n");
            th = new Thread(new Receiver());
            th.start();
            click2.setEnabled(false);
            	} catch (Exception e1) {
        	   System.out.println(e1);
           }
        }
        
        if(e.getSource() == click1) {
        	String prv = myname;
        	myname = space2.getText();        	
        	try {
        		out = new BufferedWriter(new OutputStreamWriter(cSock.getOutputStream()));
				out.write("***" + prv + "의 이름이 " + myname + "(으)로 변경되었습니다.***" + "\n");
				out.flush();
				 mainspace.append("***" + prv + "의 이름이 " + myname + "(으)로 변경되었습니다.***"+ "\n");
				
			} catch (Exception e2) {
				System.out.println(e2);
			}
        } 
        
        if (e.getSource() == space3) {
        	try {
        	  	String strOut = space3.getText();
        	     out.write(myname + ":" + strOut + "\n");
        	     out.flush();
        	      mainspace.append( myname + ":" + strOut + "\n");
        	     	if (strOut.trim().equals("quit")) {
        	      	cSock.close();        	      	
        	     	}
        	      }catch (Exception e2) {
        			System.out.println(e2);
        		}
        }
      }
     
      public static void main(String[] args) {
         
         new SimpleGUIClinet();
         
      }
   }

