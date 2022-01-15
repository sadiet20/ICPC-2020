/*
 * Author: Sadie Thomas
 * Date: 1/8/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int main(){
	//read input
	int num_sides;
	cin >> num_sides;

	vector<int> sides(num_sides);
	for(int i = 0; i < num_sides; i++){
		cin >> sides[i];
	}

	//no triangles if less than three sides
	if(num_sides < 3){
		cout << "0" << endl;
		return 0;
	}

	//sort side lengths
	sort(sides.begin(), sides.end());

	//count all subsets of size at least 3 that make valid triangles
	int count = 0;
	for(int l = 0; l < num_sides-2; l++){
		for(int c = l+1; c < num_sides-1; c++){
			int r = c+1;
			//two smallest sides must be greater than largest side
			while(r < num_sides && (sides[l] + sides[c] > sides[r])){
				r++;
			}
			//accounts for subsets greater than size 3
			count += pow(2, (r-c-1)) - 1;
		}
	}

	cout << count << endl;


	return 0;
}
