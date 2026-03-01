#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFS;
    int x;
    string skip;
    int y;

    inFS.open("input_data_processed.txt");

    if (!inFS.is_open()) {
        cout << "Could not open file input_data_processed.txt." << endl;
        return 1;
    }

    


}


/*
Thoughts on how to approach this program...
1. Run while loops to capture all x values as int and loop for the max value; then repeat for y. Could make this a function prototype at the top
2. Once max values are determined, use them to create the string array (remember its [rows][columns] which is [y][x] - so it'll be [maxY+1][maxX+1])
3. Once the array has been created, initialize it with spaces using a nested for loop that runs across each column for each row
4. Now, run through the file again with a while loop, reading each x and y coordinate and using it to read the block character into the corresponding coordinate location
5. Finally, use a nested for loop to print the array
*/