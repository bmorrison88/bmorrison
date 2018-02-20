/*
Brandon Morrison

Contains a Tank subclass that extends super class Container. Tank subclass 
overrides both the add() and remove() methods of the super class Container. Tank 
subclass also overrides the setCapacity() and setCurrentAmount() of the super class
to prevent bad data from being entered.
 */
package container;


public class Tank extends Container {

    private String contentType;

    public Tank() {

    }

    public Tank(String contentType) {
        this.contentType = contentType;
    }

    public Tank(String contentType, int capacity, int currentAmount) {
        this.contentType = contentType;
        setCapacity(capacity);
        setCurrentAmount(currentAmount);
    }

    @Override
    public void setCapacity(int capacity) {
        if (capacity >= 0) {
            this.capacity = capacity;
        } else {
            capacity = 0;
        }
    }

    @Override
    public void setCurrentAmount(int currentAmount) {
        if (currentAmount <= capacity && currentAmount >= 0) {
            this.currentAmount = currentAmount;
        } else {
            currentAmount = 0;
        }
    }

    @Override
    public int add(int amount) {
        if (amount < 0) {
            return 0;
        } else {
            currentAmount += amount;
            if (currentAmount > capacity) {
                currentAmount = capacity;
            }
            return amount;
        }
    }

    @Override
    public int remove(int amount) {
        if (amount < 0) {
            return 0;
        } else {
            currentAmount -= amount;
            if (currentAmount < 0) {
                currentAmount = 0;
            }
            return amount;
        }
    }

    public void drain() {
        currentAmount = 0;
    }

    public String getContentType() {
        return contentType;
    }

    public void setContentType(String contentType) {
        this.contentType = contentType;
    }
    @Override
    public String toString(){
        return "Container{container type: " + this.getClass().getSimpleName() + 
                ", contains: "+ contentType +", capacity = " + capacity + 
                ", current amount = " + currentAmount + '}';
    }
}
