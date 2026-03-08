#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);    // running this to make cout print UTF-8 (the Unicode characters) correctly
    ifstream inFS;
    int x, y, max_X, max_Y, i, j;
    string middle;
    string coordinatePlane[7][90];

    // Step 1 - Gather max x and y coordinates
    inFS.open("input_data_processed.txt");

    inFS >> x >> middle >> y;
    max_X = x;
    max_Y = y;

    while(!inFS.eof()) {
        if (x > max_X) {
            max_X = x;
        }
        if (y > max_Y) {
            max_Y = y;
        }

        inFS >> x >> middle >> y;
    }

    inFS.close();

    // Steps 2 & 3 - Initialize the array with spaces
    for (i = 0; i <= max_Y; ++i) {
        for (j = 0; j <= max_X; ++j) {
            coordinatePlane[i][j] = " ";
        }
    }

    // Step 4 - Read block characters from file input into each coordinate
    inFS.open("input_data_processed.txt");

    while(!inFS.eof()) {
        inFS >> x >> middle >> y;
        coordinatePlane[y][x] = middle;
    }

    cout << "Read: x=" << x << " middle = " << middle << " y=" << y << endl;
    cout<< "Value read into array at these coordinates: " << coordinatePlane[0][27] << endl;

    /*// Step 5 - Print the array
    cout << endl << endl;   // adding some space to improve my screenshot
    for (i = max_Y; i >= 0; --i) {
        for (j = 0; j <= max_X; ++j) {
            cout << coordinatePlane[i][j];
        }

        cout << endl;
    }

    cout << endl;*/

    inFS.close();

    return 0;
}


/*
Thoughts on how to approach this program...
1. Run while loops to capture all x values as int and loop for the max value; then repeat for y. Could make this a function prototype at the top
2. Once max values are determined, use them to create the string array (remember its [rows][columns] which is [y][x] - so it'll be [maxY+1][maxX+1])
    - Edit: I had to go back and use these max values + 1 to declare the array at the top of main() because C++ won't let you use a variable in an array declaration
3. Once the array has been created, initialize it with spaces using a nested for loop that runs across each column for each row
4. Now, run through the file again with a while loop, reading each x and y coordinate and using it to read the block character into the corresponding coordinate location
5. Finally, use a nested for loop to print the array
*/