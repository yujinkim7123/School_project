
public class hello {
	public static void main(String[] args) {
		SimpleBS dot = new SimpleBS();
		int[] locations = { 2, 3, 4 };
		dot.setLoctionCells(locations);
		String userGuess = "0";
		String result = dot.checkYourself(userGuess);
		String testResult = "failed";
		if(result.equals("hit")) {
			testResult = "passed";
		}
		System.out.println(testResult);
	}
}