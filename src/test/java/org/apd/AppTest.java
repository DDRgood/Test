package org.apd;

import org.apd.algorithm.AlgorithmAPD;
import org.apd.algorithm.Edge;
import org.apd.algorithm.Graph;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.*;

class AppTest extends Assertions{

    @Test
    public void is10() {
        Assertions.assertEquals(10, App.is10());
    }

    @Test
    public void checkAlgorithmEdgeInput(){
        AlgorithmAPD algorithmAPD = new AlgorithmAPD(new Graph());
        String[] testInput = {
                "a b 5",
                "a e 2",
                "a c 1",
                "b c 3",
                "e d 11",
                "c d 4"};
        for (int i = 0; i < 6; i++) {
            String[] curLine = testInput[i].split(" ");
            Edge edge = new Edge(curLine[0].charAt(0), curLine[1].charAt(0), Integer.parseInt(curLine[2]));
            try {
                algorithmAPD.addEdge(edge);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

        }
        try {
            assertEquals(algorithmAPD.result().toString(), "[a c 1, a e 2, b c 3, c d 4]");
        } catch (Exception ignored){

        }
    }

    @Test
    public void testForJava(){
        List<Edge> characters = new ArrayList<>();
        characters.add(new Edge('a', 'b', 12));
        characters.add(new Edge('c', 't', 12));
        characters.add(new Edge('r', 'p', 12));
        System.out.println(characters.indexOf(new Edge('b', 'a', 11)));
    }
}