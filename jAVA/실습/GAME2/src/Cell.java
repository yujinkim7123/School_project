import javax.swing.*;
import java.awt.*;

public class Cell extends JPanel {
	private Color color = Color.GRAY;
	
	public void setColor(Color c) {
		color = c;
	}
	
	public Color getColor() {
		return color;
	}
	
	public void paintComponent(Graphics g) {
		g.setColor(color);
		g.fillRect(0, 0, this.getWidth(), this.getHeight());
	}

}
