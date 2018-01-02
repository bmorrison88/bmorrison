/*
 * Brandon Morrison
 * Date created: Nov. 4th, 2014
 * Description: This program is a simple game I wrote for one of my classes.
 *              The program selects a word from a dictionary, scrambles it, and 
 *              have the player guess what that scrambled word is. The user gets
 *              points based on the number of letters in the word. If the user 
 *              guesses wrong, the program gives the user a hint and the number 
 *              of possible points decrease.
 */
package WordScramble;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Random;

public class WordScramble {

    public static void main(String[] args) {
        // TODO code application logic here
        String[] words = createsListOfWords();
        String choice;
        int pointTotal = 0;
        do {
        String word = chooseRandomWord(words);
        String scrambledWord = scrambleWord(word);

        System.out.println("Welcome, guess the word before you run out of points and you win!");
        int points = word.length();
        
        Scanner input = new Scanner(System.in);
        String guess;
        String hint = " ";
        for (int i = 0; i < word.length(); i++) {
            if(points != 1){
            System.out.println("Srambled word: " + scrambledWord);
            System.out.println(points + " points: What is your guess: ");
            guess = input.nextLine();
            }
            else{
                System.out.println("Srambled word: " + scrambledWord);
                System.out.println(points + " point: What is your guess: ");
                guess = input.nextLine();
            }
            if (guess.equals(word) && points != 1) {
                System.out.println("You got it!");
                System.out.println("You got " + points + " points");
                System.out.println("The word was " + word);
                break;
            }
            if (guess.equals(word) && points == 1) {
                System.out.println("You got it!");
                System.out.println("You got " + points + " point");
                System.out.println("The word was " + word);
                break;
            }
            if (points == 1) {
                System.out.println("Sorry, the word was " + word);
                points--;
                break;
            }

            points--;
            hint += "" + word.charAt(i);
            System.out.println("No, here is a hint: " + hint);
        }
        pointTotal += points;
        System.out.println("Total points earned for this session: " + pointTotal);
        System.out.println("Do you wish to play again? (Please type 'Y' or 'y' for 'yes' or anything else for 'no'): ");
        choice = input.nextLine();
        } while ("Y".equals(choice) || "y".equals(choice) );
        

    }

    private static String[] createsListOfWords() {
        String wordList = "wordlist.txt";
        Scanner read = null;
        String words[] = new String[65573];
        try {
            read = new Scanner(new File(wordList));
        } catch (FileNotFoundException e) {
            System.err.println("Error opening the file " + wordList);
            System.exit(1);
        }
        //reads string from text file to an array
        for (int i = 0; i < words.length; i++) {
            words[i] = read.nextLine();
        }
        return words;
    }

    private static String chooseRandomWord(String[] words) {
        //chooses a random word from the words array
        Random rand = new Random();
        int randomIndex = rand.nextInt(words.length);
        String word = words[randomIndex];
        return word;
    }

    private static String scrambleWord(String word) {
        //scrambles chosen word
        char[] charArray = word.toCharArray();
        for (int i = charArray.length - 1; i > 0; i--) {
            int j = (int) (Math.random() * (i + 1));
            char letter = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = letter;
        }
        String scrambledWord = new String(charArray);
        return scrambledWord;
    }
}
