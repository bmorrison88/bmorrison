/*
 * Building class: Keeps a tally of how many robots are at each building
 */

package RobotMigration;

public class Building {
    private String name;
    private Building[] adjacencies;
    
    public Building() {
        name = "";
        adjacencies = new Building[0];
    }

    public Building(String name) {
        this();
        this.name = name;
    }
    
    public int howManyRobotsAreHere(Gang myGang) {
        int howMany = 0;
        for (Robot gang : myGang.getGang()) {
            if(gang.getCurrentLocation() == this) {
                howMany++;
            }
        }
        return howMany;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Building[] getAdjacencies() {
        return adjacencies;
    }

    public void setAdjacencies(Building[] adjacencies) {
        this.adjacencies = adjacencies;
    }
    
}
