
public class RPS {
	private String comStr;

	void setCom(String s) {
		comStr = s;
	}

	String checkCom(String usrStr) {
		String result = "draw";
		switch(usrStr) {
		case"rock":
			switch(comStr) {
			case "paper":
				result = "lost";
				break;
			case"scissors":
				result = "Win";
				break;
	      default:
	          result = "draw";
			}break;
		case"paper" : 
			switch(comStr) {
			case "rock":
				result = "Win";
				break;
			case"scissors":
				result = "lost";	
				break;
			default:
				result = "draw";
			}break;
		case"scissors":
			switch(comStr) {
			case"rock":
				result = "lost";
				break;
			case"paper":
				result = "Win";
				break;
			default:
				result = "draw";
			}break;
			}
		return result;

	}

}
