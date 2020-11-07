import java.util.ArrayList;
public class Rect {
   int width;
   int height;
   static ArrayList<Rect> rectarr = new ArrayList<Rect>();
   
   Rect(int w, int l){
	   width = w;
	   height = l;
	   rectarr.add(this);
   }
   public static ArrayList<Rect> all(){
	   
	 return rectarr;
	   
   }
   
   double getArea() {
	   return width * height;
   }

}
