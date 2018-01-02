/*
 * Runs a simulation of a gang of robots moving towards the target building.
 * All robots move at the same time, but are only allowed to move to one of 
 * their adjacent building.
 */
package RobotMigration;


public class RobotSimulator {

    public static void main(String[] args) {
        Map myMap = new Map(); //Contains 15 buildings with indicies from 0 to 14
        Gang myGang = new Gang();
        int numberOfMoves = 0;
        int startBuilding = 2;
        int targetBuilding = 14;
        int gangSize = 10;
        
        myMap.loadMap("siuemap.txt");
        myGang.initGang(gangSize, myMap.getMap()[startBuilding], myMap.getMap()[targetBuilding]);
        myMap.displayMap(myGang);
        while (!myGang.areAllRobotsAtTarget()) {
            System.out.println("\nMove #" + numberOfMoves);
            myGang.moveGang();
            myMap.displayMap(myGang);
            numberOfMoves++;
        }
        System.out.println("Moves: " + numberOfMoves);
    }
}
