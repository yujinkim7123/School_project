import java.util.Date;

public class TimeTick {
	public static final int interval = 1000;

	public static void main(String[] args) {
		long l1, l2;
		l1 = new Date().getTime();
		while (true) {
		l2 = new Date().getTime();	
		if((l2 - l1)> interval) {
			System.out.println("BAMM!!!");
			l1 = l2;
		}
		}
	}

}
