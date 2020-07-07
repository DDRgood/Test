package org.apd.algorithm;

import java.util.Objects;

public class Edge {

    private Character begin, end;
    private int weight;

    public Edge(Character start, Character stop, int weight) {
        this.begin = start;
        this.end = stop;
        this.weight = weight;
    }

    public Character getBegin() {
        return begin;
    }

    public Character getEnd() {
        return end;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public String toString() {
        return begin + " " + end + " " + weight;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Edge)) return false;
        Edge edge = (Edge) o;
        return ((edge.getBegin() == this.getBegin()) && (edge.getEnd() == this.getEnd())) ||
                ((edge.getEnd() == this.getBegin()) && (edge.getBegin() == this.getEnd()));
    }

    @Override
    public int hashCode() {
        return Objects.hash(getBegin(), getEnd(), getWeight());
    }
}
