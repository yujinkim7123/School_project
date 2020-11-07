
public class SimpleBS {
	int[] locationCells;
    int length;
	public void setLocationCells(int[] locs) {
		locationCells = locs;
		length = locationCells.length;
	}

	public String checkYourself(String stringGuess) {
		int guess = Integer.parseInt(stringGuess);
		int i = 0;
		String result = "miss";
		for (int cell : locationCells) {
			if (guess == cell) {
				result = "hit";
				int j;
		    	for(j = i; j < locationCells.length - 1; j++)
		    	{		    		
		    	locationCells[j] = locationCells[j+1];
		    	}
		    	locationCells[length-1] = 0;
		    	length--;
		        } 
			
			i++;
		}
		if (length == 0) {
			result = "kill";
		}
		System.out.println(result);
		return result;
	}

}
