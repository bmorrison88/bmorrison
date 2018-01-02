/*
 * Robot gang class: Initializes a gang of robots with a starting size, starting
 * building, and target building.
 */

package RobotMigration;

public class Gang {
    private Robot[] gang;

    public Gang() {
        gang = new Robot[0];
    }
    
    public void initGang(int size, Building start, Building target) {
        gang = new Robot[Math.abs(size)];
        for(int i = 0; i < gang.length; i++) {
            gang[i] = new Robot(start, target);
        }
    }
    
    public void moveGang() {
        for (Robot gang1 : gang) {
            gang1.move();
        }
    }
    
    public boolean areAllRobotsAtTarget() {
        for (Robot gang1 : gang) {
            if(!gang1.amIThere()) {
                return false;
            }
        }
        return true;
    }
    
    public Robot[] getGang() {
        return gang;
    }

    public void setGang(Robot[] gang) {
        this.gang = gang;
    }
}
