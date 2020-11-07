
public class simplebsgame {
	public static void main(String[] args) {
		int numOfGuesses = 0;
		GameHelper helper = new GameHelper();
		SimpleBS theBS = new SimpleBS();
		int randomNum = (int) (Math.random() * 5);
		int[] locations = { randomNum, randomNum + 1, randomNum + 2 };
		theBS.setLocationCells(locations);
		boolean isAlive = true;
		while (isAlive == true) {
			String guess = helper.getUserInput("enter a number");
			String result = theBS.checkYourself(guess);
			numOfGuesses++;
			if (result.equals("kill")) {
				isAlive = false;
				System.out.println("You took " + numOfGuesses + " guesses");
			}
		}
	}

}
