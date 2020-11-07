
public class AlarmClock {
private int time;
private int alarm;


public void setAlarmTime(int t) {
	time = t;
}
public int getAlarmTime() {
	return time; 
}
public void setNumOfAlarm(int n) {
	alarm = n;
}
public void ring() {
	
	for(int i = 0; i < alarm; i++) {
		System.out.print("Ring!");
	}
	System.out.println();
}
}