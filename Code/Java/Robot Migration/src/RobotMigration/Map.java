/*
 * Map class for the robot migration.
 */
package RobotMigration;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Map {

    private Building[] map;

    public Map() {
        map = new Building[0];
    }

    //Takes a file as a parameter and loads the map for the gang of robots
    public void loadMap(String fileName) {
        Scanner infile;
        int numberOfBuildings;
        Building[] currentAdjacencies;
        try {
            infile = new Scanner(new File(fileName));
            numberOfBuildings = infile.nextInt();
            map = new Building[numberOfBuildings];
            String buildingName; // for loading buildings at first
            Building currentBuilding; // for finding the adjacent buildings
            int counter; // for finding adjacent buildings.
            for (int i = 0; i < map.length; i++) {
                map[i] = new Building(infile.next());
            }
            for (Building map1 : map) {
                currentAdjacencies = new Building[infile.nextInt()];
                for (int i = 0; i < currentAdjacencies.length; i++) {
                    buildingName = infile.next();
                    currentBuilding = map[0];
                    counter = 0;
                    while((!currentBuilding.getName().equals(buildingName)) 
                            && (counter < map.length)) {
                        counter++;
                        currentBuilding = map[counter];
                    }
                    currentAdjacencies[i] = currentBuilding;
                }
                map1.setAdjacencies(currentAdjacencies);
            }
        } catch (FileNotFoundException e) {
            System.err.println(e);
            System.exit(1);
        }// end try
    }
    // Displays where the robots are located after each move
    public void displayMap(Gang g) {
        for (Building map1 : map) {
            System.out.printf("%5s:", map1.getName());
            for (int i = 0; i < map1.howManyRobotsAreHere(g); i++) {
                System.out.print("O");
            }
            System.out.println("");
        }
    }
    
    public Building[] getMap() {
        return map;
    }

    public void setMap(Building[] map) {
        this.map = map;
    }

}
