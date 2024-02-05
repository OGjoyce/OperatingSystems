public class MyRunnable implements Runnable {
    public void run() {
        //Code
        System.out.println("aqui empieza el thread2");
        for (int i =0;i<99 ;i++ ) 
    	{
    		System.out.println("Carlos Montiel");
        	
    	}
    }

    public static void main(String[] args) throws Exception {
    	Thread th = new Thread(new MyRunnable());
    	th.start();
    }
}
