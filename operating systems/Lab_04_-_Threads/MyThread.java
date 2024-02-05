public class MyThread extends Thread {
    public MyThread() {
        super("MyThread");
    }
    public void run() {
        //Code
        System.out.println("aqui empieza el th1");
 for (int i =0;i<99 ;i++ ) 
    	{
    		System.out.println("Carlos Montiel!!!!!");
        	
    	}
    }

//Started with a "new MyThread().start()" call
public static void main(String[] args) {
	Thread th = new MyThread();
	Thread th2 = new Thread(new MyRunnable());
    th2.start();
	th.start();
}
}