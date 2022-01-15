/*
 * Author: Sadie Thomas
 * Date: 1/8/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int main(){
	//read in input
	int num_kang;
	cin >> num_kang;

	vector<int> locations(num_kang);
	for(int i = 0; i < num_kang; i++){
		cin >> locations[i];
	}


	//keep track of best distance found so far
	int best_dist = INT_MAX;
	int dist;

	//brute force - check all house combinations
	for(int house1 = 0; house1 < num_kang; house1++){
		for(int house2 = house1+1; house2 < num_kang; house2++){
			dist = 0;
			//sum squared distance to closest house
			for(int i = 0; i < num_kang; i++){
				dist += pow(min(abs(locations[i] - locations[house1]), abs(locations[i] - locations[house2])), 2);
			}
			//update if new best distance
			if(dist < best_dist){
				best_dist = dist;
			}
		}
	}

	
	cout << best_dist << endl;



	return 0;
}
