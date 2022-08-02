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
#include "mySystem_2048.h"
#include <iostream>
#include <algorithm>

#define UP		0
#define DOWN	1
#define LEFT	2
#define RIGHT	3

using namespace std;

static unsigned char specialKeys[] = {
    GLUT_KEY_UP,
    GLUT_KEY_DOWN,
    GLUT_KEY_LEFT,
    GLUT_KEY_RIGHT
};

int numSpecialKeys = sizeof(specialKeys)/sizeof(unsigned char);

MY_2048::MY_2048( )
{
    mNX = 4;
    mNZ = 4;
    reset( );

    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
    //
    flg_AutoPlay = false;
}

MY_2048::MY_2048( int nx, int nz )
{
    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
    //
    // Implement your own stuff
    //
    mNX = nx;
    mNZ = nz;
    reset();
}

void MY_2048::setDimension(int nx, int nz)
{
    mFlgFocus = true;
    mNX = nx;
    mNZ = nz;
    reset();
    //
    // Implement your own stuff
    //
}


void MY_2048::setFocus( bool flg )
{
    mFlgFocus = flg;
}

void MY_2048::setPosition( int x, int z )
{
    mPositionX = x;
    mPositionZ = z;
}

//
// Copy the m's previous board 
// to the object's mBoard.
//
void MY_2048::copyPrevious( const BASE_SYSTEM *m )
{
    for ( int j = 0; j < mNZ; ++j ) {
        for ( int i = 0; i < mNX; ++i ) {
            mBoard [j][i]= ((MY_2048*)m)->mPreviousBoard[ j ][ i ];
        }
    }
}

//
//reset the game board
//
void MY_2048::reset( )
{
    mEvent = 0;
    ///////////////////////////////////////
    //
    // Implement your own stuff
    //
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            mBoard[j][i] = 0;
        }
    }
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            mPreviousBoard[j][i] = mBoard[j][i];
        }
    }
}

//
// show messages and ask for input (if any)
//
void MY_2048::askForInput( )
{
    //
    // Implement your own stuff if needed
    //
    cout << "MY_2048" << endl;
    cout << "Key usage:" << endl;
    cout << "1: generate randomly the numbers 2 and 4 for all the cells" << endl;
    cout << "2: generate randomly the numbers 2, 4 and 8 for all the cells" << endl;
    cout << "3: generate randomly the numbers for all the cells" << endl;
    cout << "r: clear all the cells" << endl;
    cout << " " << endl;
    cout << "UP, DOWN, LEFT, RIGHT: move the numbers to the respective side" << endl;
}

//
// randomly generate a new number
//
void MY_2048::generateNumber( )
{
    //
    // Implement your own stuff if needed
    //
    int r = rand() % 11;
    int v = 2;
    v = v << r;
    //if (r == 1) v = 4;
    //load free cells
    vector<vector<pair<int, int>>> freeArr(mNZ);
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            int z = mNZ - j - 1;
            if (mBoard[z][i] == 0) {
                freeArr[j].push_back(pair<int, int>(z, i));
            }
        }
    }
    //
    if (freeArr.size() == 0) return;
    //rand to selet cell
    for (int j = 0; j < mNZ; ++j) {
        if (freeArr[j].size() == 0) continue;
        int index = rand() % freeArr[j].size();
        int z = freeArr[j][index].first;
        int x = freeArr[j][index].second;
        mBoard[z][x] = v;
        break;
    }
}
void MY_2048::generateNumberOn(int i, int j)
{
    //
    // Implement your own stuff if needed
    //
    int r = rand() % 11;
    int v = 2;
    v = v << r;
    mBoard[i][j] = v;
    
}

void MY_2048::moveDown( )
{
    //
    // Implement your own stuff if needed
    //   
    for (int i = 0; i < mNX; ++i) {
        moveOneLine(i, DOWN);
    }
    //generateNumber();

}

void MY_2048::moveUp( )
{
    //
    // Implement your own stuff if needed
    //
    for (int i = 0; i < mNX; ++i) {
        moveOneLine(i, UP);
    }
    //generateNumber();
}

void MY_2048::moveLeft( )
{
    // 
    // Implement your own stuff if needed
    //
    for (int i = 0; i < mNZ; ++i) {
        moveOneLine(i, LEFT);
    }
    //generateNumber();
    
    
}

void MY_2048::moveRight( )
{
    //
    // Implement your own stuff if needed
    //
    for (int i = 0; i < mNZ; ++i) {
        moveOneLine(i, RIGHT);
    }
   // generateNumber();
}
/*
void MY_2048::generateNumbers_All_2to4( )
{
    //
    // Implement your own stuff if needed
    //
    generateNumbers(2);
}

void MY_2048::generateNumbers_All_2to8( )
{
    //
    // Implement your own stuff if needed
    //
    generateNumbers(3);

}

void MY_2048::generateNumbers_All( )
{
    //
    // Implement your own stuff if needed
    //
    generateNumbers(11);
}
*/

void MY_2048::task1()
{
    reset();
    for (int i = 0; i < 32; ) {
        int x = rand() % 8;
        int y = rand() % 8;
        if (mBoard[x][y] >= 2) continue;
        i++;
        generateNumberOn(x, y);
    }
}


void MY_2048::task2()
{
    reset();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i - j <= 0) {
                generateNumberOn(i, j);
            }
        }
    }
}


void MY_2048::task4()
{
    int tmp[8][8];
    int arr[8][8];
    int len[8];
    for (int i = 0; i < 8; i++) len[i] = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tmp[i][j] = mBoard[i][j];
            if (tmp[i][j]) {
                arr[j][len[j]] = tmp[i][j];
                len[j]++;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        sort(arr[i], arr[i] + len[i]);
    }
    for (int i = 0; i < 8; i++) len[i] = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //tmp[i][j] = mBoard[i][j];
            if (tmp[i][j]) {
                mBoard[i][j] = arr[j][len[j]];
                len[j]++;
            }
        }
    }
}


void MY_2048::task5()
{

    int tmp[8][8];
    int arr[8][8];
    int len[8];
    for (int i = 0; i < 8; i++) len[i] = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tmp[i][j] = mBoard[i][j];
            if (tmp[i][j]) {
                arr[i][len[i]] = tmp[i][j];
                len[i]++;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        sort(arr[i], arr[i] + len[i]);
    }
    for (int i = 0; i < 8; i++) len[i] = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //tmp[i][j] = mBoard[i][j];
            if (tmp[i][j]) {
                mBoard[i][j] = arr[i][len[i]];
                len[i]++;
            }
        }
    }
}


void MY_2048::handleKeyPressedEvent( unsigned char key )
{
    switch( key ) {
    case 'r':
    case 'R':
        reset();
        break;
    case '6':
        task1();
        break;
    case '7':
        task2();
        break;

    case 'm':
    case 'M':
        task4();
        break;
    case 'n':
    case 'N':
        task5();
        break;
    //case ' ':
        // toggle to auto-play
        //flg_AutoPlay = !flg_AutoPlay;
        //break;
    }
}

bool MY_2048::performAction( unsigned char key ) {
bool flgDone = false;

    switch( key ) {
    case GLUT_KEY_UP:
        flgDone = true;
        moveUp( );
        mEvent = GLUT_KEY_UP;
        break;
    case GLUT_KEY_DOWN:
        flgDone = true;
        moveDown( );
        mEvent = GLUT_KEY_DOWN;

        break;
    case GLUT_KEY_LEFT:
        flgDone = true;
        moveLeft( );
        mEvent = GLUT_KEY_LEFT;

        break;
    case GLUT_KEY_RIGHT:
        flgDone = true;
        moveRight( );
        mEvent = GLUT_KEY_RIGHT;

        break;

    }

    if ( flgDone ) {
        generateNumber( );
    }
    return flgDone;
}

void MY_2048::handleSpecialKeyPressedEvent( unsigned char key )
{
    //
    // It takes a long time to show a message!
    //
    cout << "MY_2048::handleSpecialKeyPressedEvent:" << key << endl;
    int initBoard[MAX_2048_NZ][MAX_2048_NX];
    copyT(mBoard, initBoard);
   if  (performAction( key ))
    copyT(initBoard, mPreviousBoard);
}

bool MY_2048::isAutoPlay() const
{
    return flg_AutoPlay;
}

//
// The update( ) function is called every frame.
//
// Design an algorithm to automatically perform
// one step.
//
void MY_2048::update( )
{
    //
    // It takes a long time to show a message!
    //
    cout << "MY_2048::update( )" << endl;
    cout << "MY_2048::flg_AutoPlay:\t" << flg_AutoPlay << endl;

    if (!flg_AutoPlay) return;

    //
    // Implement your own stuff if needed
    //
    copyT(mBoard, mPreviousBoard);
    //check next 7 keys
    vector<double> score(numSpecialKeys, 0);
    for (int i = 0; i < numSpecialKeys; ++i) {
        int initBoard[MAX_2048_NZ][MAX_2048_NX];
        copyT(mBoard, initBoard);
        //double fScore = EventDFS(7, specialKeys[i], initBoard);
        copyT(initBoard, mBoard);
        //score[i] = fScore;
    }
    //take and the best next ket 
    //cout << score[0] << '\n';
    double best_score = score[0];
    int action_index = 0;
    for (int i = 1; i < numSpecialKeys; ++i) {
        //cout << score[i] << '\n';
        if (score[i] > best_score) {
            best_score = score[i];
            action_index = i;
        }
    }
    handleSpecialKeyPressedEvent(specialKeys[action_index]);
}


void MY_2048::moveOneLine(int i, int direction)
{
    int base, start;
    switch (direction) {
    case UP:
        base = mNZ - 1;
        start = mNZ - 1;
        while (1) {
            int xz0 = findItem(start, i, direction);
            if (xz0 < 0) break;
            moveItem(xz0, base, i, direction);
            int xz1 = findItem(xz0 - 1, i, direction);
            if (xz1 < 0) break;
            //merge
            if (mBoard[xz1][i] == mBoard[base][i]) {
                mBoard[base][i] *= 2;
                mBoard[xz1][i] = 0;
                start = xz1 - 1;
            }
            else {
                start = xz1;
            }
            --base;
        }
        break;
    case DOWN:
        base = 0;
        start = 0;
        while (1) {
            int xz0 = findItem(start, i, direction);
            if (xz0 >= mNZ) break; // no item found
            moveItem(xz0, base, i, direction);
            int xz1 = findItem(xz0 + 1, i, direction);
            if (xz1 >= mNZ) break;
            //merge
            if (mBoard[xz1][i] == mBoard[base][i]) {
                mBoard[base][i] *= 2;
                mBoard[xz1][i] = 0;
                start = xz1 + 1;
            }
            else {
                start = xz1;
            }
            ++base;
        }
        break;
    case RIGHT:
        base = mNX - 1;
        start = mNX - 1;
        while (1) {
            int xz0 = findItem(start, i, direction);
            if (xz0 < 0) break;
            moveItem(xz0, base, i, direction);
            int xz1 = findItem(xz0 - 1, i, direction);
            if (xz1 < 0) break;
            //merge
            if (mBoard[i][xz1] == mBoard[i][base]) {
                mBoard[i][base] *= 2;
                mBoard[i][xz1] = 0;
                start = xz1 - 1;
            }
            else {
                start = xz1;
            }
            --base;
        }
        break;
    case LEFT:
        base = 0;
        start = 0;
        while (1) {
            int xz0 = findItem(start, i, direction);
            if (xz0 >= mNX) break; // no item found
            moveItem(xz0, base, i, direction);
            int xz1 = findItem(xz0 + 1, i, direction);
            if (xz1 >= mNX) break;
            //merge
            if (mBoard[i][xz1] == mBoard[i][base]) {
                mBoard[i][base] *= 2;
                mBoard[i][xz1] = 0;
                start = xz1 + 1;
            }
            else {
                start = xz1;
            }
            ++base;
        }
        break;
    }
}

void MY_2048::moveItem(int now, int move, int i, int direction)
{
    if (move == now) return;
    switch (direction) {
    case UP:
    case DOWN:
        mBoard[move][i] = mBoard[now][i];
        mBoard[now][i] = 0;
        break;
    case LEFT:
    case RIGHT:
        mBoard[i][move] = mBoard[i][now];
        mBoard[i][now] = 0;
        break;
    }
}


int MY_2048::findItem(int start, int i, int direction) const
{
    int xz = start;
    switch (direction) {
    case UP:
        while (xz >= 0) {
            if (mBoard[xz][i] != 0) {
                break;
            }
            --xz;
        }
        break;
    case DOWN:
        while (xz < mNZ) {
            if (mBoard[xz][i] != 0) {
                break;
            }
            ++xz;
        }
        break;
    case RIGHT:
        while (xz >= 0) {
            if (mBoard[i][xz] != 0) {
                break;
            }
            --xz;
        }
        break;
    case LEFT:
        while (xz < mNX) {
            if (mBoard[i][xz] != 0) {
                break;
            }
            ++xz;
        }
        break;
    }
    return xz;
}


void MY_2048::copyT(int src[][MAX_2048_NX], int tgt[][MAX_2048_NX])
{
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            tgt[j][i] = src[j][i];
        }
    }
}