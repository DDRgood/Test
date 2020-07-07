package org.apd.algorithm;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class AlgorithmAPD {
    private Graph graph;

    private List<Edge> mst = new ArrayList<>();
    private List<Edge> notUsedEdges = new ArrayList<>();
    private List<Character> usedVertexes = new ArrayList<>();
    private List<Character> notUsedVertexes = new ArrayList<>();
    private List<Edge> minimumSpanningTree = new ArrayList<>();

    private boolean isInitializedNotUsedLists = false;
    private boolean isConnectivityChecked = false;

    private void initialize(){
        if (!isInitializedNotUsedLists){
            notUsedEdges = new ArrayList<>(graph.getEdgesList());
            notUsedVertexes = new ArrayList<>(graph.getVertexesList());
            usedVertexes.add(notUsedVertexes.remove(0));
            isInitializedNotUsedLists = true;
        }

    }

    private boolean graphConnectivityCheck() {
        if(isConnectivityChecked) return true;
        var checkedVertexesList = new boolean[graph.getVertexesList().size()];
        List<Edge> edgesList = graph.getEdgesList();
        List<Character> vertexesList = graph.getVertexesList();
        Stack<Character> stackForDFS = new Stack<>();
        stackForDFS.push(vertexesList.get(0));
        while (!stackForDFS.empty()){
            Character curVertex = stackForDFS.pop();
            checkedVertexesList[vertexesList.indexOf(curVertex)] = true;
            for (Edge edge : edgesList) {
                if ((edge.getBegin() == curVertex) && (!checkedVertexesList[vertexesList.indexOf(edge.getEnd())])) {
                    stackForDFS.push(edge.getEnd());
                }
                if ((edge.getEnd() == curVertex) && (!checkedVertexesList[vertexesList.indexOf(edge.getBegin())])) {
                    stackForDFS.push(edge.getBegin());
                }
            }
        }
        for(Boolean bool : checkedVertexesList){
            if(!bool) return false;
        }
        isConnectivityChecked = true;
        return true;
    }

    public void clear(){
        graph.clear();
    }

    public AlgorithmAPD(Graph graph) {
        this.graph = graph;
    }

    public void removeEdge(Edge edge) {
        graph.removeEdge(edge);
    }

    public void removeVertex(Character vertex) {
        graph.removeVertex(vertex);
    }

    public void addEdge(Edge edge) throws Exception {
        if(!graph.addEdge(edge)) throw new Exception("edge already exist");
    }

    public void readGraphFromFile(File file) throws Exception {
        var scanner = new Scanner(file).useDelimiter(System.getProperty("line.separator"));
        while (scanner.hasNext()){
            String[] curLine = scanner.nextLine().split(" ");
            Edge edge = new Edge(curLine[0].charAt(0), curLine[1].charAt(0), Integer.parseInt(curLine[2]));
            addEdge(edge);
        }
    }

    public List<Edge> result() throws Exception {
        initialize();
        if(!graphConnectivityCheck()) throw new Exception("graph isn't connected");
        while (notUsedVertexes.size() > 0) {
            nextEdgeAtMst();
        }
        return minimumSpanningTree;
    }

    public Edge nextEdgeAtMst() throws Exception {
        initialize();
        if(!graphConnectivityCheck()) throw new Exception("graph isn't connected");
        var result = new Edge('a', 'a', -1);
        if(notUsedVertexes.size() > 0) {
            int minE = -1;
            for (int i = 0; i < notUsedEdges.size(); i++) {
                if (((usedVertexes.indexOf(notUsedEdges.get(i).getBegin()) != -1) &&
                        (notUsedVertexes.indexOf(notUsedEdges.get(i).getEnd()) != -1)) ||
                        ((usedVertexes.indexOf(notUsedEdges.get(i).getEnd()) != -1) &&
                                (notUsedVertexes.indexOf(notUsedEdges.get(i).getBegin()) != -1))) {
                    if (minE != -1) {
                        if (notUsedEdges.get(i).getWeight() < notUsedEdges.get(minE).getWeight())
                            minE = i;
                    } else
                        minE = i;
                }

            }

            if (usedVertexes.indexOf(notUsedEdges.get(minE).getBegin()) != -1) {
                usedVertexes.add(notUsedEdges.get(minE).getEnd());
                notUsedVertexes.remove(notUsedEdges.get(minE).getEnd());
            } else {
                usedVertexes.add(notUsedEdges.get(minE).getBegin());
                notUsedVertexes.remove(notUsedEdges.get(minE).getBegin());
            }
            minimumSpanningTree.add(notUsedEdges.get(minE));
            result = notUsedEdges.get(minE);
            notUsedEdges.remove(minE);
        }
        return result;
    }
}
