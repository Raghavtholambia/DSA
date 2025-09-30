// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<int> nums,vector<int>output,int index,vector<vector<int>>&ans)
// {
//     if (index>=nums.size())
//     {
//         ans.push_back(output);
//         return;
//     }
    
//     //exclude
//     solve(nums,output,index+1,ans);

//     //include
//     int element = nums[index];
//     output.push_back(element);
//     solve(nums,output,index+1,ans);
// }
// int main()
// {
//     int el;
//     vector<int>nums(5);
//     cout << "enter 3 element";
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(3);
    
//     vector<vector<int>> ans;
//     vector<int> output;
//     int index=0;
//     solve(nums,output,index,ans);
//     return 0;
// }



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to simulate rolling the dice
int rollDice() {
    return (rand() % 6) + 1; // Random number between 1 and 6
}

int main() {
    // Snake and Ladder positions
    int snakes[] = {32, 36, 48, 62, 88, 95, 97};
    int snakeEnd[] = {10, 6, 26, 18, 24, 56, 78};
    int ladders[] = {1, 4, 8, 21, 28, 50, 71, 80};
    int ladderEnd[] = {38, 14, 30, 42, 76, 67, 92, 99};

    int playerPosition = 0; // Starting position
    char choice;
    srand(time(0)); // Seed for random number generation

    cout << "Welcome to Snake and Ladder Game!" << endl;

    while (playerPosition < 100) {
        cout << "\nPress 'r' to roll the dice: ";
        cin >> choice;

        if (choice == 'r' || choice == 'R') {
            int dice = rollDice();
            cout << "You rolled: " << dice << endl;

            // Update player position
            playerPosition += dice;

            // Check if the player overshoots 100
            if (playerPosition > 100) {
                playerPosition -= dice; // Revert the move
                cout << "You need exactly " << 100 - playerPosition << " to win!" << endl;
            } else {
                // Check for snakes
                for (int i = 0; i < 7; i++) {
                    if (playerPosition == snakes[i]) {
                        playerPosition = snakeEnd[i];
                        cout << "Oops! A snake took you down to " << playerPosition << endl;
                    }
                }

                // Check for ladders
                for (int i = 0; i < 8; i++) {
                    if (playerPosition == ladders[i]) {
                        playerPosition = ladderEnd[i];
                        cout << "Yay! A ladder took you up to " << playerPosition << endl;
                    }
                }

                cout << "Your current position is: " << playerPosition << endl;

                // Check for win
                if (playerPosition == 100) {
                    cout << "Congratulations! You won the game!" << endl;
                    break;
                }
            }
        } else {
            cout << "Invalid input. Please press 'r' to roll the dice." << endl;
        }
    }

    return 0;
}
