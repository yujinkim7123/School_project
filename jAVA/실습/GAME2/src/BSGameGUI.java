import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BSGameGUI {
	private GameHelper helper = new GameHelper();
	private ArrayList<BS> bsList = new ArrayList<BS>();
	private int numOfGuesses = 0;
	private String userGuess;
	int[] intGuess = new int[2];

	private int gl = helper.getGridLength() + 1;
	private int gs = gl * gl;

	public JLabel labelScore;

	public JPanel[] panels;

	private JTextArea ta;

	private JTextField tf;

	private static final char[] CHOR = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	private static final char[] CVER = { '0', '1', '2', '3', '4', '5', '6' };

	public static void main(String[] args) {
		BSGameGUI gui = new BSGameGUI();
		gui.go();
	}

	public void go() {
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setPreferredSize(new Dimension(800, 1000));

		JLabel[] horLabel = new JLabel[gl - 1];
		JLabel[] verLabel = new JLabel[gl - 1];
		makeLable(horLabel, verLabel);

		BoxLayout boxLayout = new BoxLayout(frame.getContentPane(), BoxLayout.X_AXIS);
		frame.setLayout(boxLayout);

		GridLayout gLayout = new GridLayout(gl, gl, 10, 10);
		JPanel topPanel = new JPanel();
		topPanel.setPreferredSize(new Dimension(800, 800));
		topPanel.setLayout(gLayout);

		panels = new JPanel[gs];
		createCells(topPanel, panels, horLabel, verLabel);

		ta = new JTextArea(5, 30);
		ta.setEditable(false);
		ta.setLineWrap(true);
		ta.setFont(new Font("Arial", Font.PLAIN, 30));
		JScrollPane scrPanel = new JScrollPane(ta);
		scrPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrPanel.setPreferredSize(new Dimension(800, 200));

		JPanel botPanel = new JPanel();
		tf = new JTextField(2);
		tf.setFont(new Font("Arial", Font.PLAIN, 70));

		tf.addActionListener(new FieldListener());
		botPanel.add(tf);

		frame.add(topPanel);
		frame.add(scrPanel);
		frame.add(botPanel);
		frame.pack();
		frame.setVisible(true);

		setUpGame();
	}

	public void makeLable(JLabel[] hl, JLabel[] vl) {
		for (int i = 0; i < gl - 1; i++) {
			hl[i] = new JLabel();
			vl[i] = new JLabel();
			hl[i].setText(Character.toString(CHOR[i]));
			vl[i].setText(Character.toString(CVER[i]));
			hl[i].setFont(new Font("Arial", Font.PLAIN, 50));
			vl[i].setFont(new Font("Arial", Font.PLAIN, 50));

		}
	}

	public void createCells(JPanel p, JPanel[] ps, JLabel[] hl, JLabel[] vl) {
		for (int i = 0, j = 0; i < panels.length; i++) {
			if (i == 0) {
				p.add(labelScore = new JLabel("0"));
				labelScore.setFont(new Font("Arial", Font.PLAIN, 70));
			} else if (i < gl) {
				p.add(hl[i - 1]);
				continue;
			} else if (i % gl == 0) {
				p.add(vl[j++]);
				continue;
			} else {
				ps[i] = new Cell();
				p.add(ps[i]);
			}
		}
	}

	public void setUpGame() {
		BS one = new BS();
		one.setName("C");
		BS two = new BS();
		two.setName("Java");
		BS three = new BS();
		three.setName("C++");
		bsList.add(one);
		bsList.add(two);
		bsList.add(three);
		ta.setText("your goal is to sink three ships.: ");
		ta.append("C, Java, C++\n");
		ta.append("Try to sink them all" + "in the fewest number of guesses.\n");
		for (BS bs : bsList) {
			ArrayList<String> newLoc = helper.placeBS(3);
			bs.setLocationCells(newLoc);
		}
	}

	public void checkUserGuess(String userGuess) {
		if (userGuess.length() != 2) {
			ta.append("Shoot on the target grid like A0!\n");
			ta.setCaretPosition(ta.getText().length() - 1);
		} else {
			int x, y;
			boolean check = checkTwoChars(userGuess, intGuess);

			if (!check) {
				ta.append("Out of the target grid!\n");
				ta.setCaretPosition(ta.getText().length() - 1);
			} else {
				numOfGuesses++;
				String result = "miss";
				labelScore.setText(Integer.toString(numOfGuesses));
				x = intGuess[0];
				y = intGuess[1];
				for (BS bs : bsList) {
					result = bs.checkYourself(userGuess);
					if (result.equals("hit")) {
						((Cell) panels[(x + 1) + (y + 1) * gl]).setColor(Color.red);
						panels[(x + 1) + (y + 1) * gl].repaint();
						ta.append(result + "\n");
						ta.setCaretPosition(ta.getText().length() - 1);
						break;
					}
					if (result.equals("kill")) {
						((Cell) panels[(x + 1) + (y + 1) * gl]).setColor(Color.red);
						ta.append(result + "\n");
						ta.append("you sunk " + bs.getName() + "!\n");
						ta.setCaretPosition(ta.getText().length() - 1);

						bsList.remove(bs);
						if (bsList.isEmpty())
							this.finishGame();
						break;
					}
				}

				if (result.equals("miss")) {
					if (((Cell) panels[(x + 1) + (y + 1) * gl]).getColor() == Color.gray) {
						((Cell) panels[(x + 1) + (y + 1) * gl]).setColor(Color.yellow);
						panels[(x + 1) + (y + 1) * gl].repaint();
					}
					ta.append(result + "\n");
					ta.setCaretPosition(ta.getText().length() - 1);
				}
			}
		}
	}

	private boolean checkTwoChars(String s, int[] g) {
		char ch = s.charAt(0);
		char cv = s.charAt(1);
		boolean onTargetHor = false;
		boolean onTargetVer = false;

		for (int i = 0; i < gl - 1; i++) {
			if (ch == CHOR[i]) {
				g[0] = i;
				onTargetHor = true;
				break;
			}
		}
		for (int i = 0; i < gl - 1; i++) {
			if (cv == CVER[i]) {
				g[1] = i;
				onTargetVer = true;
				break;

			}
		}

		if (onTargetHor && onTargetVer)
			return true;
		else
			return false;
	}

	private void finishGame() {
		ta.append("All battleships are dead!\n");
		ta.append("It only took you" + numOfGuesses + " guesses\n");
		ta.setCaretPosition(ta.getText().length() - 1);
	}

	class FieldListener implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			userGuess = tf.getText();
			tf.setText("");
			ta.append(userGuess + "\n");
			ta.setCaretPosition(ta.getText().length() - 1);
			if (!bsList.isEmpty()) {
				checkUserGuess(userGuess);
			} else
				finishGame();

		}
	}
}