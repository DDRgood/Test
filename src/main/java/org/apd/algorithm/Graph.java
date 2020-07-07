package org.apd.algorithm;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Graph {

    private List<Edge> edgesList;
    private List<Character> vertexesList;

    public Graph() {
        edgesList = new ArrayList<>();
        vertexesList = new LinkedList<>();
    }

    public void addEdge(Character firstTopName, Character secondTopName, int weight) {
        Edge edge = new Edge(firstTopName, secondTopName, weight);
        addEdge(edge);
    }

    public boolean addEdge(Edge edge) {
        if(!checkEdge(edge)) return false;
        edgesList.add(edge);
        if (!vertexesList.contains(edge.getBegin())) vertexesList.add(edge.getBegin());
        if (!vertexesList.contains(edge.getEnd())) vertexesList.add(edge.getEnd());
        return true;
    }

    private boolean checkEdge(Edge edge) {
        for (Edge curEdge : edgesList) {
            if (curEdge.equals(edge)) {
                return false;
            }
        }
        return true;
    }

    public void clear() {
        edgesList.clear();
        vertexesList.clear();
    }

    public void removeEdge(Edge edge) {
        edgesList.remove(edge);
        boolean isContainFirstVertex = false;
        boolean isContainSecondVertex = false;
        for (Edge curEdge : edgesList) {
            if (curEdge.getBegin() == edge.getBegin() || curEdge.getEnd() == edge.getBegin())
                isContainFirstVertex = true;
            if (curEdge.getBegin() == edge.getEnd() || curEdge.getEnd() == edge.getEnd()) isContainSecondVertex = true;
        }
        if (!isContainFirstVertex) vertexesList.remove(edge.getBegin());
        if (!isContainSecondVertex) vertexesList.remove(edge.getEnd());
    }

    public void removeVertex(Character vertex) {
        vertexesList.remove(vertex);
        edgesList.removeIf(edge -> edge.getBegin() == vertex || edge.getEnd() == vertex);
    }

    public List<Edge> getEdgesList() {
        return edgesList;
    }

    public List<Character> getVertexesList() {
        return vertexesList;
    }

    @Override
    public String toString() {
        var sb = new StringBuilder();
        for (Edge edge : edgesList) {
            sb.append(edge.toString()).append("\n");
        }
        return sb.toString();
    }
}
