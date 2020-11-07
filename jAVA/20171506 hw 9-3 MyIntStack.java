
public class MyIntStack implements MyStack {
    private final int MAX = 3;
    private int[] stack = new int[MAX];
    private int index = -1;
    
    
	@Override
	public void push(int n) {
	     if(index != MAX-1) {
	    	 stack[++index] = n;
	     }
	     else
	    	 System.out.println("Stack is full");
	}

	@Override
	public int pop() {
		
		if(index == -1) {
			System.out.println("Stack is empty!");
				return 0;
		}
		else
			return stack[index--];
}
}