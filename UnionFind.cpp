/*

0123##678
9#1#345#7
A#012###6
#89#12#B5

....##...
.#.#...#.
A#...###.
#B##..#..

*/
#include <iostream>
#include <stdlib.h>

using namespace std;

int id[1000], start, finish;
char inputArr[1000];

void QuickUnionFind(int N){

	for(int i = 0; i < N; i++) id[i] = i;

}

int root(int i){

	while(i != id[i]) i = id[i];
	return i;
	
}

bool connected(int p, int q){

	return root(p) == root(q);

}

void connect(int p, int q){

	int i = root(p);
	int j = root(q);
	id[i] = j;
	//cout << "Connect " << p << " to " << q << endl;
	//cout << "id[" << i << "] = " << j << endl;
	
}

void readInput(int w, int h){
	
	int k=0;
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			cin >> inputArr[k++];
	
}

void connectPossible(int w, int h){
	
	int k=0;
	for(int i = 0; i < w * h; i++){
		char c = inputArr[i];
		if(c == '.' || c == 'A' || c == 'B'){
			if(c == 'A') start = i;
			if(c == 'B') finish = i;
			char d = inputArr[i + 1];
			if((d == '.' || d == 'A' || d == 'B') && ((i + 1) % h != 0)) connect(i, i + 1);
			d = inputArr[i + h];
			if(d == '.' || d == 'A' || d == 'B') connect(i, i + h);
		}
	}

}	

int main(){
	
	int K;
	int L;
	cin >> K >> L;
	QuickUnionFind(K * L);
	readInput(K, L);
	connectPossible(K, L);
	cout << connected(start, finish) << endl;
	
	return 0;

}
