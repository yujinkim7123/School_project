
public class ObjectArraylarm {
public static void main (String[] args) {
	AlarmClock[] alarms = new AlarmClock[3];
	
	alarms[0] = new AlarmClock();
	alarms[1] = new AlarmClock();
	alarms[2] = new AlarmClock();
	
	alarms[0].setAlarmTime(16);
    alarms[1].setAlarmTime(12);
    alarms[2].setAlarmTime(15);
    
    alarms[0].setNumOfAlarm(2);
    alarms[1].setNumOfAlarm(3);
    alarms[2].setNumOfAlarm(4);
    
    for(int i = 0; i < 3; i++) {
    	System.out.println("Alarm " + i + " is set at" + alarms[i].getAlarmTime() + ".");
    	alarms[i].ring();
    }

}
}
