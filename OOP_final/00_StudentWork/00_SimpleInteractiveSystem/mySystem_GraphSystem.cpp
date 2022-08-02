//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Prof. Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/06/16
//
#include <iostream>
#include "mySystem_GraphSystem.h"
#include <time.h>

using namespace std;

int Param::GRAPH_MAX_NUM_NODES = 10000;
int Param::GRAPH_MAX_NUM_EDGES = 10000;

GRAPH_SYSTEM::GRAPH_SYSTEM()
{
    mFlgAutoNodeDeletion = false;
    mMaxNumNode = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdge = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr = new GRAPH_NODE[mMaxNumNode];
    mEdgeArr = new GRAPH_EDGE[mMaxNumEdge];

    mActiveNodeArr = new int[mMaxNumNode];
    mActiveEdgeArr = new int[mMaxNumEdge];

    mFreeNodeArr = new int[mMaxNumNode];
    mFreeEdgeArr = new int[mMaxNumEdge];
    //
    for (int i = 0; i < mMaxNumNode; ++i) {
        mNodeArr[i].id = i;
    }
    for (int i = 0; i < mMaxNumEdge; ++i) {
        mEdgeArr[i].id = i;
    }
    reset();
    createDefaultGraph();
    //
    // Implement your own stuff if needed
    //
}

void GRAPH_SYSTEM::reset()
{
    stopAutoNodeDeletion();
    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
    //
    // Implement your own stuff if needed
    //

    mNumOfNode = 0;
    mNumOfEdge = 0;

    mFreeNode = mMaxNumNode;
    mFreeEdge = mMaxNumEdge;

    for (int i = 0; i < mFreeNode; ++i) {
        mFreeNodeArr[i] = i;
    }
    for (int i = 0; i < mFreeEdge; ++i) {
        mFreeEdgeArr[i] = i;
    }
}

void GRAPH_SYSTEM::createDefaultGraph()
{
    reset();
    //
    // Implement your own stuff if needed
    //
    int n_0 = addNode(0.0, 0.0, 0.0);
    cout << "n_0:" << n_0 << endl;
    int n_1 = addNode(5.0, 0.0, 0.0);
    cout << "n_1:" << n_1 << endl;
    int n_2 = addNode(0.0, 0.0, 5.0);
    cout << "n_2:" << n_2 << endl;
    int n_3 = addNode(5.0, 0.0, 5.0);
    cout << "n_3:" << n_3 << endl;
    addEdge(n_0, n_1);
    addEdge(n_0, n_2);
    addEdge(n_0, n_3);
    addEdge(n_1, n_3);
    addEdge(n_2, n_3);
}

void GRAPH_SYSTEM::createTask2()
{
    reset();
    //
    // Implement your own stuff if needed
    //
    int arr[5][5];
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            arr[x][y] = addNode(x*10, 0.0, y*10);
        }
    }

    // x
    for (int i = 0; i < 4; i++) {
        addEdge(arr[i][0], arr[i + 1][0]);
        addEdge(arr[i][4], arr[i + 1][4]);
    }
    for (int i = 0; i < 3; i++) {
        addEdge(arr[i][1], arr[i + 1][1]);
    }
    for (int i = 1; i < 3; i++) {
        addEdge(arr[i][3], arr[i + 1][3]);
    }
    addEdge(arr[1][2], arr[2][2]);

    // y
    for (int i = 0; i < 4; i++) {
        addEdge(arr[4][i], arr[4][i + 1]);
    }
    for (int i = 1; i < 4; i++) {
        addEdge(arr[0][i], arr[0][i + 1]);
    }
    for (int i = 1; i < 3; i++) {
        addEdge(arr[3][i], arr[3][i + 1]);
    }
    for (int i = 2; i < 3; i++) {
        addEdge(arr[1][i], arr[1][i + 1]);
    }
}

void GRAPH_SYSTEM::createTask3()
{
    if (counter_columns == 0) reset();
    //
    // Implement your own stuff if needed
    //
    int x = counter_columns;
    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = addNode(x*10, 0, i*10);
    }
    for (int i = 0; i < 4; i++) {
        addEdge(arr[i], arr[i + 1]);
    }
    counter_columns++;
}

void GRAPH_SYSTEM::createTask4()
{
    if (snakex == 0 && snakey == 0 && lastuse == -1) reset();
    //
    // Implement your own stuff if needed
    //
    int tmp = addNode(snakex*10, 0.0, snakey*10);
    if (lastuse >= 0) addEdge(tmp, lastuse);
    lastuse = tmp;
    if (mode == 0) {
        snakex++;
        if (snakex == 5) {
            snakex--;
            snakey++;
            mode = 1;
        }
    }
    else {
        snakex--;
        if (snakex == -1) {
            snakex++;
            snakey++;
            mode = 0;
        }
    }
}


// return node id
int GRAPH_SYSTEM::addNode(float x, float y, float z, float r)
{
    //
    // Implement your own stuff if needed
    /*
    GRAPH_NODE* g;
    g = getFreeNode();
    if (g == 0) return -1;
    g->p = vector3(x, y, z);
    g->r = r;
    g->edgeID.clear();
    return g->id;
    */

    if (this->mFreeNode == 0) return -1;
    //load ID
    int id = mFreeNodeArr[--mFreeNode];
    GRAPH_NODE* new_node = &mNodeArr[id];
    mActiveNodeArr[mNumOfNode] = id;
    new_node->dynamicID = mNumOfNode++;
    //init new node
    new_node->p = vector3(x, y, z);
    new_node->r = r;
    new_node->edgeID.clear();
    //
    return new_node->id;
}

// return edge id
int GRAPH_SYSTEM::addEdge(int nodeID_0, int nodeID_1)
{
    //
    // Implement your own stuff if needed
    /*
    GRAPH_EDGE* e;
    e = getFreeEdge();
    if (e == 0) return -1;
    e->nodeID[0] = nodeID_0;
    e->nodeID[1] = nodeID_1;
    mNodeArr_Pool[nodeID_0].edgeID.push_back(e->id);
    mNodeArr_Pool[nodeID_1].edgeID.push_back(e->id);

    return e->id;*/

    if (mFreeEdge == 0) return -1;
    //loaf ID
    int id = mFreeEdgeArr[--mFreeEdge];
    GRAPH_EDGE* new_edge = &mEdgeArr[id];
    mActiveEdgeArr[mNumOfEdge] = id;
    new_edge->dynamicID = mNumOfEdge++;
    //init new edge
    new_edge->nodeID[0] = nodeID_0;
    new_edge->nodeID[1] = nodeID_1;
    mNodeArr[nodeID_0].edgeID.push_back(new_edge->id);
    mNodeArr[nodeID_1].edgeID.push_back(new_edge->id);
    //
    return new_edge->id;
}

/*
*/

void GRAPH_SYSTEM::askForInput()
{
    //
    // Implement your own stuff if needed
    // 
}

void GRAPH_SYSTEM::handleKeyPressedEvent(unsigned char key)
{
    // add new functions when necessary
    switch (key) {
    case '6':
        snakex = 0;
        snakey = 0;
        mode = 0;
        lastuse = -1;
        mFlgAutoNodeDeletion = false;
        counter_columns = 0;
        createDefaultGraph();
        mSelectedNode = 0;
        break;
    case '7':
        snakex = 0;
        snakey = 0;
        mode = 0;
        lastuse = -1;
        counter_columns = 0;
        mFlgAutoNodeDeletion = false;
        createTask2();
        mSelectedNode = 0;
        break;
    case '8':
        snakex = 0;
        snakey = 0;
        mode = 0;
        lastuse = -1;
        mFlgAutoNodeDeletion = false;
        createTask3();
        mSelectedNode = 0;
        break;
    case '9':
        counter_columns = 0;
        mFlgAutoNodeDeletion = false;
        createTask4();
        mSelectedNode = 0;
        break;
    default:
        snakex = 0;
        snakey = 0;
        mode = 0;
        lastuse = -1;
        counter_columns = 0;
        break;
    }
}

//
// get the number of nodes
//
int GRAPH_SYSTEM::getNumOfNodes() const
{
    //
    // Implement your own stuff if needed
    // 
    return mNumOfNode;
}

void GRAPH_SYSTEM::getNodeInfo(int nodeIndex, double& r, vector3& p) const
{
    //
    // Implement your own stuff if needed
    // 
    int id = mActiveNodeArr[nodeIndex];
    GRAPH_NODE* node = &mNodeArr[id];
    r = node->r;
    p = node->p;
}

//
// return the number of edges
//
int GRAPH_SYSTEM::getNumOfEdges() const
{
    //
    // Implement your own stuff if needed
    // 
    return mNumOfEdge;
}

//
// an edge should have two nodes: index 0 and index 1
// return the position of node with nodeIndex
//
vector3 GRAPH_SYSTEM::getNodePositionOfEdge(int edgeIndex, int nodeIndex) const
{
    vector3 p;
    //
    // Implement your own stuff
    // 
    // 
    int id = mActiveEdgeArr[edgeIndex];
    GRAPH_EDGE* edge = &mEdgeArr[id];
    p = mNodeArr[edge->nodeID[nodeIndex]].p;
    return p;

}

//
// For every frame, update( ) function is called.
// 
//
void GRAPH_SYSTEM::update()
{
    // Do not need to implement
}

void GRAPH_SYSTEM::clickAt(double x, double z) {
    // Do not need to implement
}

void GRAPH_SYSTEM::handlePassiveMouseEvent(double x, double y) {
    // Do not need to implement
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    // Do not need to implement
}

bool GRAPH_SYSTEM::isSelectedNode() const
{
    // Do not need to implement
    return false;
}
void GRAPH_SYSTEM::getInfoOfSelectedPoint(double& r, vector3& p) const
{
    // Do not need to implement
}