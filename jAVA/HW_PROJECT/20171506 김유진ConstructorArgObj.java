
public class ConstructorArgObj {
	public static void main(String[] args) {
		Box[] boxes = new Box[4];
		
		boxes[0] = new Box();
		boxes[1] = new Box(1,2,3);
		boxes[2] = new Box(2);
		boxes[3] = new Box(boxes[1]);
		
		for(Box b : boxes) {
		System.out.println(	b.getVol());
		}
	}
}
