
public class Constructors {
	public static void main(String[] args) {
		NameCard nc[] = new NameCard[4];
		
		nc[0] = new NameCard();
		nc[1] = new NameCard("Media");
		nc[2] = new NameCard(19991234);
		nc[3] = new NameCard("Lads", 19999999);
		
		
		for(NameCard n : nc) {
			System.out.println(n.getName() + ", " + n.getId());
			
		}
	}
}
