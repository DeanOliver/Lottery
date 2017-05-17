// Lottery.cpp : Defines the entry point for the console application.
// By Dean Oliver

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){

	const int balls = 48;
	const int selected_balls = 6;	
	int winning_balls[selected_balls];
	int finish; // to stall program at the end

	int games = 0;
	int match_3 = 0; // Record three matches in a game
	int match_4 = 0; // Record four matches in a game
	int match_5 = 0; // Record five matches in a game
	int match_6 = 0; // Record six matches in a game
	int chosen_balls[6] = { 1, 2, 3, 4, 5, 6 };

	srand(time(NULL)); // Seed the time

	cout << "The chosen numbers are 1, 2, 3, 4, 5, 6 \n";
	cout << "Please wait a minute for 10,000,000 games to be played \n";
	
	// Start of a game
	while (games < 10000000) {

		int balls_matched = 0;

		// Compare numbers
		for (int k = 0; k < selected_balls; k++) {

		redo_number:

			// To get random numbers we use the clock (not ideal as its not fast)
			winning_balls[k] = rand() % 48 + 1; // Random ball between 1 - 48		

			int *dup_found = find(winning_balls, winning_balls + k, winning_balls[k]); // Find duplicates
			if (dup_found != winning_balls + k) {
				goto redo_number;
			}

			//cout << winning_balls[k] << "\n"; // Print winning numbers

			int *match_found = find(chosen_balls, chosen_balls + 6, winning_balls[k]); // Find if number matches
																					   // If the number matches
			if (match_found != chosen_balls + 6) {
				balls_matched++;
			}
		}

		// How many 3+ balls matched
		switch (balls_matched) {
		case 3: match_3++;break;
		case 4: match_4++;break;
		case 5: match_5++;break;
		case 6: match_6++;break;
		default: break;
		}

		fill_n(winning_balls, 6, 0); // set the winning numbers to 0 for next game
		games++;
} // End of a game
	
	float prize_pool = games;

	// Assuming £1 per game 
	// Percentage odds are not the way to go, but I dont know the math to
	// determine what the pay out should be based on the odds.
	float three_match_payout = prize_pool * 0.000001;
	float four_match_payout = prize_pool * 0.00002; 
	float five_match_payout = prize_pool * 0.0008; 
	float six_match_payout = prize_pool * 0.20;   

	// winnings as a percentage of the prize pool
	float three_match_percentage = ((match_3 * three_match_payout) / games) * 100;
	float four_match_percentage = ((match_4 * four_match_payout) / games) * 100;
	float five_match_percentage = ((match_5 * five_match_payout) / games) * 100;
	float six_match_percentage = ((match_6 * six_match_payout) / games) * 100;

	// Print end results to screen
	cout << fixed << setprecision(3);
	cout << "N.o of 3 Ball matches = " << match_3 << " Pay out for 3 matches: " << three_match_payout << "pounds \n";
	cout << "Total pay out for 3 matches : " << match_3 * three_match_payout << "pounds or " 
		 << three_match_percentage << " percent of money put in\n";

	cout << "N.o of 4 Ball matches = " << match_4 << " Pay out for 4 matches: " << four_match_payout << "pounds \n";
	cout << "Total pay out for 4 matches : " << match_4 * four_match_payout << "pounds or " 
		 << four_match_percentage << " percent of money put in \n";

	cout << "N.o of 5 Ball matches = " << match_5 << " Pay out for 5 matches: " << five_match_payout << "pounds \n";
	cout << "Total pay out for 5 matches : " << match_5 * five_match_payout << "pounds or " 
		 << five_match_percentage << " percent of money put in \n";

	cout << "N.o of 6 Ball matches = " << match_6 << " Pay out for 6 matches: " << six_match_payout << "pounds \n";
	cout << "Total pay out for 6 matches : " << match_6 * six_match_payout << "pounds or " 
		 << six_match_percentage << " percent of money put in \n";
	
	cout << "press a key, then enter to exit" << "\n";
	cin >> finish;
	
	return 0;
}
