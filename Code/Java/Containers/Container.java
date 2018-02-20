/*
Brandon Morrison

Contains an abstract super class Container with abstract methods add() and remove(). 
Includes methods isFull() and isEmpty() to test if the Container type is full or
empty. Also includes two abstract methods, add() and remove(), to be implemented in
the Tank and CargoBox subclasses.
*/
package container;


public abstract class Container {

    protected int capacity;
    protected int currentAmount;

    public Container() {
        capacity = 0;
        currentAmount = 0;
    }

    public Container(int capacity, int currentAmount) {
        setCapacity(capacity);
        setCurrentAmount(currentAmount);
    }

    public abstract int add(int amount);

    public abstract int remove(int amount);

    public boolean isFull() {
        boolean cond = (currentAmount >= capacity)? true: false;
        return cond;
    }

    public boolean isEmpty() {
        boolean cond = (currentAmount <= 0)? true: false;
        return cond;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCurrentAmount() {
        return currentAmount;
    }

    public void setCurrentAmount(int currentAmount) {
        this.currentAmount = currentAmount;
    }

    @Override
    public String toString() {
        return "Container{container type: "+ this.getClass().getSimpleName() + ", capacity = " + capacity + ", current amount = " + currentAmount + '}';
    }

}
