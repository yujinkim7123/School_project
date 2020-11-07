
public class Box extends Rect {
int height;
Box(){
	super();
}
Box(int w, int l,int h){
	super(w,l);
	height = h;
	
}
Box(int l){
	super(l);
	height = l;
}
double getVol() {
	return getArea() * height;
}
}
