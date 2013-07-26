#include <iostream>

using namespace std;

class Robot {
	private:
		int row;
		int col;
		char orientation;
		char **grid;
		int N;
		int M;
		int counter;


	public:
		Robot(int N, int M, char **grid, int row, int col, char orientation) {
			counter = 0;
			this->N = N;
			this->M = M;
			this->grid = grid;
			this->row = row;
			this->col = col;
			this->orientation = orientation;
			// cerr<<"Started at "<<row<<", "<<col<<" headed "<<orientation<<endl;
		}
		int getCounter() {
			return counter;
		}
		void transitState(char c) {
			switch(c) {
				// Move forward one step
				case 'F':
					// Do nothing if this happens
					if(orientation == 'N' && (row == 0 || grid[row-1][col] == '#')) {
						// cerr<<"I'm at "<<row<<", "<<col<<" headed north which is either end of grid or there is a stone at "<<row-1<<", "<<col<<endl;
					}
					else if(orientation == 'S' && (row == N-1 || grid[row+1][col] == '#')) {
						// cerr<<"I'm at "<<row<<", "<<col<<" headed south which is either end of grid or there is a stone at "<<row+1<<", "<<col<<endl;
					}
					else if(orientation == 'L' && (col == M-1 || grid[row][col+1] == '#')) {
						// cerr<<"I'm at "<<row<<", "<<col<<" headed east which is either end of grid or there is a stone at "<<row<<", "<<col+1<<endl;
					}
					else if(orientation == 'O' && (col == 0 || grid[row][col-1] == '#')) {
						// cerr<<"I'm at "<<row<<", "<<col<<" headed west which is either end of grid or there is a stone at "<<row<<", "<<col-1<<endl;
					}
					// move north
					else if(orientation == 'N') {
						row--;
						// cerr<<"Moved north to "<<row<<", "<<col<<endl;
					}
					// move south
					else if(orientation == 'S') {
						row++;
						// cerr<<"Moved south to "<<row<<", "<<col<<endl;
					}
					// move east
					else if(orientation == 'L') {
						col++;
						// cerr<<"Moved east to "<<row<<", "<<col<<endl;
					}
					// move west
					else if(orientation == 'O') {
						col--;
						// cerr<<"Moved west to "<<row<<", "<<col<<endl;
					}
					// grab a sticker
					if(grid[row][col] == '*') {
						counter++;
						// cerr<<"Grabbed a sticker. I have now "<<counter<<" stickers"<<endl;
						grid[row][col] = '.';
					}
					break;
				// Turn left
				case 'E':
					if(orientation == 'N') {
						orientation = 'O';
						// cerr<<"I'm now headed west"<<endl;
					}
					else if(orientation == 'S') {
						orientation = 'L';
						// cerr<<"I'm now headed east"<<endl;
					}
					else if(orientation == 'L') {
						orientation = 'N';
						// cerr<<"I'm now headed north"<<endl;
					}
					else if(orientation == 'O') {
						orientation = 'S';
						// cerr<<"I'm now headed south"<<endl;
					}
					break;
				// Turn right
				case 'D':
					if(orientation == 'N') {
						orientation = 'L';
						// cerr<<"I'm now headed east"<<endl;
					}
					else if(orientation == 'S') {
						orientation = 'O';
						// cerr<<"I'm now headed west"<<endl;
					}
					else if(orientation == 'L') {
						orientation = 'S';
						// cerr<<"I'm now headed south"<<endl;
					}
					else if(orientation == 'O') {
						orientation = 'N';
						// cerr<<"I'm now headed north"<<endl;
					}
					break;
			}

		}
};

int main() {
	int n, m, s;
	while(true) {
		cin>>n>>m>>s;
		if(!n && !m && !s)
			break;
		char **arr = new char*[n];
		for(int i=0; i<n; i++)
			arr[i] = new char[m];
		int row;
		int col;
		char orientation;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				char c;
				cin>>c;
				if(c=='N' || c=='L' || c=='S' || c=='O') {
					row = i;
					col = j;
					orientation = c;
				}
				arr[i][j] = c;
			}
		}
		Robot r(n, m, arr, row, col, orientation);
		for(int i=0; i<s; i++) {
			char c;
			cin>>c;
			r.transitState(c);
		}
		cout<<r.getCounter()<<endl;
	}
	return 0;
}

