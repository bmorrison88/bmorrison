package container;

/*
    Test the usage of super classes, abstract methods, method overriding, and 
 *  method overloading.  
 */
public class ContainerTester {
    
    public static void main(String[] args) {
        Tank t1 = new Tank("Badgers");
        CargoBox c1 = new CargoBox();
        
        c1.setCapacity(100);
        c1.setCurrentAmount(50);
        t1.setCapacity(200);
        t1.setCurrentAmount(100);
        c1.add(-2);
        
        System.out.println(c1);
        System.out.println(t1);
    }
}
