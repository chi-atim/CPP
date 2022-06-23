/**
** Program Name: Chess Knight
** Purpose: Program shows the simplest possible way to get from one square to another by outputting all squares the knight will stop on along the way.
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
class Node{
public:
    Node(int x, int y){
        posX = x;
        posY = y;
        distance = 0;
        parent = nullptr;
    }
    Node(int x, int y, int d, Node* par){
        posX = x;
        posY = y;
        distance = d;
        parent = par;
    }

    int posX, posY, distance;
    Node* parent;
} ;

// Prints the shortest paths
void printPath(Node* node) {
    if (node == nullptr){
        return;
    }
    printPath(node->parent);
    cout << "\t[" << node->posX << "," << node->posY << "]"<< endl;
}

// Returns true if the given position is inside the 8x8 chess board, false otherwise
bool isInside(Node* curr){
    if (curr->posX >= 0 && curr->posX <= 7 && curr->posY >= 0 && curr->posY <= 7)
        return true;
    return false;
}

Node* knight_moves(Node* start, Node* dest){

    // mark all cells in the 8x8 chess board as unvisited
    bool visited[8][8];
    for (int i=0; i<8; i++){
        for (int k=0; k<8; k++){
            visited[i][k] = false;
        }
    }

    queue<Node*> q; // queue for BFS

    // push the starting position of the knight
    q.push(start);

    // x and y possible direction for a Knight
    int x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y[8] = {-1, 1, 1, -1, 2, -2, 2, -2};



    // BFS for finding minimum number of steps taken by the knight
    while(!q.empty()){

        Node* curr = q.front();
        q.pop();

         // if arrived at the destination, return the node
         if (curr->posX == dest->posX && curr->posY == dest->posY){
            return curr;
        }

        // If current cell is unvisited, process it
        if (!visited[curr->posX][curr->posY]){
            // Mark current as visited
            visited[curr->posX][curr->posY] = true;

            // for all 8 possible direction for a knight
            for(int i=0; i<8; i++){
                if(isInside(curr)){
                    // push each valid movement into the queue
                    q.push(new Node(curr->posX + x[i], curr->posY + y[i], curr->distance+1, curr));
                }
            }
        }
    }
    return nullptr;
}

int main(){

    int startX, startY, destX, destY;
    cout << "=> Enter the startent Knight’s location: ";
    cin >> startX >> startY;
    cout << "=> Enter the destination location: ";
    cin >> destX >> destY;

    Node* start = new Node (startX, startY);
    Node* dest = new Node (destX, destY);

    Node* result  = knight_moves(start, dest);

    cout << "=> You made it in " << result->distance << " moves from [" << startX << "," << startY << "] to [" << destX<< "," << destY << "]!" << endl;
    cout << "Here is your path:" << endl;
    printPath(result);

    return 0;
}

