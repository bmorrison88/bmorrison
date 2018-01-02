/*
 * Name: Brandon Morrison
 * Revised: 7/17/2015
 * Desc: This program uses the Timeline animation to create a simple stopwatch.
 */
package Stopwatch;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.util.Duration;

/**
 *
 * @author Brandon
 */
public class Stopwatch extends Application {

    private int seconds = 0;
    private int minutes = 0;
    private int hours = 0;

    @Override
    public void start(Stage primaryStage) {
        //Set of possible buttons
        Button start = new Button("Start");
        Button pause = new Button("Pause");
        Button clear = new Button("Clear");
        Button resume = new Button("Resume");
        
        //Display of stopwatch time
        TextField time = new TextField(hours + " : " + minutes + " : " + seconds);
        time.setAlignment(Pos.CENTER);

        Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), e -> {

            if (seconds <= 59) {
                seconds++;
                if (seconds > 59) {
                    seconds = 0;
                    minutes++;
                    if (minutes > 59) {
                        minutes = 0;
                        hours++;
                        if (hours > 23) {
                            hours = 0;
                        }
                    }
                }
                time.setText(hours + " : " + minutes + " : " + seconds);
            }

        }));
        animation.setCycleCount(Timeline.INDEFINITE);

        BorderPane bp = new BorderPane();
        HBox hb = new HBox();
        hb.setAlignment(Pos.CENTER);
        hb.getChildren().add(start);
        hb.getChildren().add(clear);

        //Start button clicked
        start.setOnMouseClicked(e -> {
            hb.getChildren().clear();
            hb.getChildren().add(pause);
            hb.getChildren().add(clear);
            animation.play();
        });
        
        //Pause button clicked
        pause.setOnMouseClicked(e -> {
            hb.getChildren().clear();
            hb.getChildren().add(resume);
            hb.getChildren().add(clear);
            animation.pause();
        });
        
        //Clear button clicked
        clear.setOnMouseClicked(e -> {
            hb.getChildren().clear();
            hb.getChildren().add(start);
            hb.getChildren().add(clear);
            hours = 0;
            minutes = 0;
            seconds = 0;
            time.setText(hours + " : " + minutes + " : " + seconds);
            animation.pause();
        });

        //Resume button clicked
        resume.setOnMouseClicked(e -> {
            hb.getChildren().clear();
            hb.getChildren().add(pause);
            hb.getChildren().add(clear);
            animation.play();
        });

        bp.setBottom(hb);
        bp.setCenter(time);
        Scene scene = new Scene(bp, 300, 250);

        primaryStage.setTitle("Stopwatch");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
