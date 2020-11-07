
public class RPSGame {
	public static void main(String[] args) {
		GameHelper helper = new GameHelper();
		RPS rps = new RPS();
		String[] s = { "rock", "paper", "scissors" };
		int rand, numOfWin = 0, numOfLost = 0;
		String com, usr, res;
		while (numOfWin < 2 && numOfLost < 2) {
			rand = (int) (Math.random() * 3);
			com = s[rand];
			rps.setCom(com);
			usr = helper.getUserInput("enter one of rock, paper, scissors:");
			res = rps.checkCom(usr);
			if (res.equals("Win")) {
				numOfWin++;
				System.out.println(numOfWin + "/" + numOfLost + ": usr-" + usr + ", com -" + com);
			} else if (res.equals("lost")) {
				numOfLost++;
				System.out.println(numOfWin + "/" + numOfLost + ": usr-" + usr + ",com-" + com);
			} else
				System.out.println(numOfWin + "/" + numOfLost + ": usr-" + usr + ", com" + com);
		}

		if (numOfWin > numOfLost)
			System.out.println("Win!");
		else
			System.out.println("Lost!");
	}

}
