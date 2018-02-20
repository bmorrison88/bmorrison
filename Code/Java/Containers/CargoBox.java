/*
Brandon Morrison

Contains a CargoBox subclass that extends super class Container. CargoBox 
subclass overrides both the add() and remove() methods of the super class Container.
CargoBox subclass also overrides the setCapacity() and setCurrentAmount() of the 
super class to prevent bad data from being entered.
 */
package container;


public class CargoBox extends Container {

    public CargoBox() {
        
    }

    public CargoBox(int capacity, int currentAmount) {
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
        if (amount <= 0) {
            return 0;
        } else {

            if (amount + currentAmount > capacity) {
                currentAmount += 0;
                return 0;
            }
            currentAmount += amount;
            return 1;
        }
    }

    @Override
    public int remove(int amount) {
        if (amount <= 0) {
            return 0;
        } else {

            if (currentAmount - amount < 0) {
                currentAmount += 0;
                return 0;
            }
            currentAmount -= amount;
            return 1;
        }
    }

}
