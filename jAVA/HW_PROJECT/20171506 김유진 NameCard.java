
public class NameCard {
private String name;
private int id;

public NameCard() {
	name = "Java";
	id = 11111111;
}
public NameCard(String s) {
	name = s;
	id = 11111111;
}
public NameCard(int i) {
	name = "Java";
	id = i;
}
public NameCard(String s, int i) {
	name = s;
	id = i;
}

public String getName() {
	return name;
}
public int getId() {
	return id;
}
}
