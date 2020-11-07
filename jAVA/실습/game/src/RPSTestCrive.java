
public class RPSTestCrive {
	public static void main(String[] args) {
		String usr, com;
		String res;
		RPS rps = new RPS();
		
		com = "rock";
		
		rps.setCom(com);
		
		usr = "scissors";
		
		res = rps.checkCom(usr);
		
		System.out.println(res + ", usr-"+ usr + ", com-" + com);
		
		
		
		
		
	}

}
