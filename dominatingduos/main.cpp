/*
 * Author: Sadie Thomas
 * Date: 1/15/2022
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main(){
	//get input
	int num_people;
	cin >> num_people;

	vector<int> people(num_people);
	for(int i=0; i<num_people; i++){
		cin >> people[i];
	}

	unsigned long long count = 0;

	//forward pass counting all left < right
	stack<int> forward_stack;
	forward_stack.push(people[0]);
	for(int i=1; i<num_people; i++){
		while(!forward_stack.empty() && forward_stack.top() < people[i]){
			forward_stack.pop();
			count++;
		}
		forward_stack.push(people[i]);
	}
	
	//backward pass counting all right < left
	stack<int> backward_stack;
	backward_stack.push(people[num_people-1]);
	for(int i=num_people-2; i>=0; i--){
		while(!backward_stack.empty() && backward_stack.top() < people[i]){
			backward_stack.pop();
			count++;
		}
		backward_stack.push(people[i]);
	}


	cout << count << endl;


	return 0;
}
