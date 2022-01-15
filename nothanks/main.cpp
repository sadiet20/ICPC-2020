/*
 * Author: Sadie Thomas
 * Date: 1/15/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int num_cards;
	cin >> num_cards;


	vector<int> cards(num_cards);

	for(int i=0; i<num_cards; i++){
		cin >> cards[i];
	}

	sort(cards.begin(), cards.end());

	int score = cards[0];

	for(int i=1; i<num_cards; i++){
		if(cards[i] != cards[i-1] + 1){
			score += cards[i];
		}
	}

	cout << score << endl;

	return 0;
}
