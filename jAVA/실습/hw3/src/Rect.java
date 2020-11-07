
public class Rect {
	int width;
	int length;
	Rect(){
		width = -1;
		length = -1;
	}
	Rect(int w, int l){
		width = w;
		length = l;
	}
	Rect(int l){
		width = l;
		length = l;
	}
	double getArea() {
		return width * length;
	}
}
