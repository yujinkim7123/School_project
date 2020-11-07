import java.util.Date;

public class dog {
	public static void main(String[] args) {
		System.out.println(String.format("%tc", new Date()));
		System.out.println(String.format("%tr", new Date()));

		Date d = new Date();
		System.out.println(String.format("%tA %tB %td", d,d,d));
		System.out.println(new Date().getTime());

	}
}