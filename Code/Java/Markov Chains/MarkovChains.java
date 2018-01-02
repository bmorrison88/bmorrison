/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package markovchains;

import java.util.*;
import java.io.*;

/**
 *
 * @author Brandon
 */
public class MarkovChains {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String fileName = "Walk8.csv";
        try {
            FileWriter fw = new FileWriter(fileName);
            char g = 'G';
            char y = 'Y';
            char o = 'O';
            char r = 'R';
            String s1,s2,s3,s4,s5;
            s1 = s2 = s3 = s4 = s5 = "";
            int greenTally, yellowTally, orangeTally, redTally;
            greenTally = yellowTally = orangeTally = redTally = 0;

            char initialState = g;
            double randomNumber, cdf, greenProp, yellowProp, orangeProp, redProp;
            greenProp = yellowProp = orangeProp = redProp = randomNumber = cdf = 0;
            Random random = new Random();

            for (int i = 0; i < 1000; i++) {
                randomNumber = random.nextDouble();
                switch (initialState) {
                    case 'G':
                        cdf = 0.8;
                        if (randomNumber <= cdf) {
                            initialState = g;
                            greenTally++;
                        } else {
                            initialState = y;
                            yellowTally++;
                        }
                        break;
                    case 'Y':
                        cdf = 0.1;
                        if (randomNumber <= cdf) {
                            initialState = g;
                            greenTally++;
                        } else if (randomNumber > cdf && randomNumber <= 0.9) {
                            initialState = y;
                            yellowTally++;
                        } else {
                            initialState = o;
                            orangeTally++;
                        }
                        break;
                    case 'O':
                        cdf = 0.1;
                        if (randomNumber <= cdf) {
                            initialState = g;
                            greenTally++;
                        } else if (randomNumber > cdf && randomNumber <= 0.8) {
                            initialState = o;
                            orangeTally++;
                        } else {
                            initialState = r;
                            redTally++;
                        }
                        break;
                    case 'R':
                        cdf = 0.1;
                        if (randomNumber <= cdf) {
                            initialState = g;
                            greenTally++;
                        } else {
                            initialState = r;
                            redTally++;
                        }
                        break;
                }
                //System.out.println("Step " + (i + 1) + ": " + initialState);
                greenProp = Math.round(((double) greenTally / (i + 1))*100.0)/100.0;
                yellowProp = Math.round(((double) yellowTally / (i + 1))*100.0)/100.0;
                orangeProp = Math.round(((double) orangeTally / (i + 1))*100.0)/100.0;
                redProp = Math.round(((double) redTally / (i + 1))*100.0)/100.0;

                s1 = Double.toString(greenProp);
                s2 = Double.toString(yellowProp);
                s3 = Double.toString(orangeProp);
                s4 = Double.toString(redProp);
                s5 = initialState + "";
 
                
                fw.write(s5 + ',' + s1 + ',' + s2 + ',' + s3 + ',' + s4);
                fw.append("\n");
                
            }
                fw.flush();
                fw.close();
        } catch (Exception E) {
            System.out.println("ERROR OPENING FILE");
        }
    }

}
