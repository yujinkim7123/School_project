
public class Box {
int width;
int length;
int height;

Box(){
	width = -1;
	length = -1;
	height = -1;
}
Box(int w, int l, int h){
	width = w;
	length = l;
	height = h;
}
Box(int l){
	width = l;
	length = l;
	height = l;
}
Box (Box b){
	width = b.width;
	length = b.length;
	height = b.height;
}
double getVol() {
	return width*length*height;
}
}
