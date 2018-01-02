/*
 * Robot class describing the attributes and actions of a robot
 */

package RobotMigration;

import java.util.Random;


public class Robot {
    private Building currentLocation, targetLocation;
    
    public Robot() {
        currentLocation = targetLocation = null;
    }

    public Robot(Building currentLocation, Building targetLocation) {
        this.currentLocation = currentLocation;
        this.targetLocation = targetLocation;
    }
    
    public void move() {
        int nextLocationIndex;
        Random rand = new Random();
        if(!(currentLocation == targetLocation)) {
            nextLocationIndex = rand.nextInt(currentLocation.getAdjacencies().length);
            currentLocation = currentLocation.getAdjacencies()[nextLocationIndex];
        }
    }
    
    public boolean amIThere() {
        return (currentLocation == targetLocation);
    }


    public Building getCurrentLocation() {
        return currentLocation;
    }

    public void setCurrentLocation(Building currentLocation) {
        this.currentLocation = currentLocation;
    }

    public Building getTargetLocation() {
        return targetLocation;
    }

    public void setTargetLocation(Building targetLocation) {
        this.targetLocation = targetLocation;
    }
    
    
    
}
