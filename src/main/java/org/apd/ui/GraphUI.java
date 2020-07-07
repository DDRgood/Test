package org.apd.ui;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;

import java.util.ArrayList;

public class GraphUI {
    private static class GraphV extends Circle{
        GraphV(double centerX, double centerY){
            super(centerX, centerY,6.0);
            //setStyle("-fx-stroke: #fff; -fx-stroke-width: 2px; -fx-fill: " + AppUI.colorOrange);
        }
        public void setColor(String color){
            setFill(Color.web(color));
        }
    }

    private static class GraphE extends Line {
        GraphE(double x0, double y0, double x1, double y1){
            super(x0, y0, x1, y1);
            setStyle("-fx-fill: #fff");
        }
        public void setColor(String color){
            setFill(Color.web(color));
        }
    }

    private static ArrayList<GraphV> vs = new ArrayList<>();

    public static void drawGraph(Pane p, int vNum){
        double centerX = p.getWidth()/2.0;
        double centerY = p.getHeight()/2.0;
        double r = centerX < centerY ? centerX - 12 : centerY - 12;
        for (int i = 0; i < vNum; i++){
            double x = centerX + r*Math.cos(2 * Math.PI * i / vNum);
            double y = centerY + r*Math.sin(2 * Math.PI * i / vNum);
            var v = new GraphV(x, y);
            vs.add(v);
            p.getChildren().add(v);
        }
    }

    public static void moveGraphX(double x){
        for (int i = 0; i < vs.size(); i++){
            vs.get(i).setCenterX(vs.get(i).getCenterX() + (x/2.0) * (1 + Math.cos(2 * Math.PI * i / vs.size())));
        }
    }

    public static void moveGraphY(double y){
        for (int i = 0; i < vs.size(); i++){
            vs.get(i).setCenterY(vs.get(i).getCenterY() + (y/2.0) * (1 + Math.sin(2 * Math.PI * i / vs.size())));
        }
    }
}
