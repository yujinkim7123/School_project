
public class PolyArgument {
	public static void main(String[] args) {
		Dog d = new Dog();
		Cat c = new Cat();
		
		Owner o = new Owner();
		
		o.command(d);
		o.command(c);
		d.fr();
	}

}
