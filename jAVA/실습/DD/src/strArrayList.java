import java.util.ArrayList;
public class strArrayList {
public static void main(String[] args) {
	ArrayList<String> strList = new ArrayList<String>();
	strList.add("Media");
	strList.add("Labs");
	strList.add("SCH");
	strList.add("Internet");
	strList.add("Things");
	strList.add("IoT");

	while(!strList.isEmpty()) {
		String s;
		s = strList.get(0);
		  strList.remove(0);
		   
		int l = s.length();
		if(l > 4)System.out.println("The length of '" + s + "' is " +  l+ ".");
	
	
	
	
}
}
