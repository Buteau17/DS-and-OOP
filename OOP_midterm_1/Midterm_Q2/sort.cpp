#include "sort.h"

void sort::process(const char* fileName) {
	// read file 
	ifstream FileInput;
	FileInput.open(fileName);

	if (!FileInput) {
		cout << "File open fail!!" << endl;
	}
	char c;
	string line;
	while ((c = FileInput.get()) != EOF) {
		FileInput.get();
		if (c == '0') {  //Do the insertion sort
			getline(FileInput, line, ' ');
			bool isBinary = (stoi(line) == 0) ? false : true;
			getline(FileInput, line, ' ');
			int length_ins = stoi(line);
			getline(FileInput, line);
			int target = stoi(line);

			for (int i = 0; i < length_ins; i++) {
				if (i == length_ins - 1)
					getline(FileInput, line);
				else
					getline(FileInput, line, ' ');
				insertion.push_back(stoi(line)); //Insert the number to the insertion vector
			}
			InsertionSort(); //Run the insertion sort
			if (isBinary) BinarySearch(0, target); //Whether do the binary search
			else cout << endl;
			insertion.clear();
		}
		else if (c == '1') { //Do the bucket sort
			getline(FileInput, line, ' ');
			bool isBinary = (stoi(line) == 0) ? false : true;
			getline(FileInput, line, ' ');
			int length_buc = stoi(line);
			getline(FileInput, line);
			int target = stoi(line);

			//cout << length_buc << endl;

			for (int i = 0; i < length_buc; i++) {
				if (i == length_buc - 1)
					getline(FileInput, line);
				else
					getline(FileInput, line, ' ');
				bucket.push_back(stoi(line)); //Insert the number to the bucket vector
			}
			//cout << bucket.size() << endl;
			BucketSort();  //Run the bucket sort
			if (isBinary) BinarySearch(1, target);  //Whether do the binary search
			else cout << endl;
			bucket.clear();
		}
	}
	FileInput.close();
}

void sort::InsertionSort() {
	//TODO:
	//Use the insert vector to perform insertion sort.

	for (int i = 1; i < insertion.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (insertion[j+1] < insertion[j]) {
				int tmp = insertion[j+1];
				insertion[j+1] = insertion[j];
				insertion[j] = tmp;
			}
			else break;
		}
	}

	output(0, 0); //print the result after the insertion sort
}
vector<int> InsertionSort2(vector<int> v) {
	//TODO:
	//Use the insert vector to perform insertion sort.

	for (int i = 1; i < v.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[j+1] < v[j]) {
				int tmp = v[j+1];
				v[j+1] = v[j];
				v[j] = tmp;
			}
			else break;
		}
	}
	return v;
}

void sort::BucketSort() {
	//TODO:
	//Use the bucket vector to perform bucket sort.
	//Note: Don't forget to print the result at each round end.
	int maxx = -1000000;
	for (int i = 0; i < bucket.size(); i++) {
		maxx = max(maxx, bucket[i]);
	}
	int cnt = 0;
	while (maxx) {
		maxx /= 10;
		cnt++;
	}
	vector<vector<int>> buc(10);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < bucket.size(); j++) {
			int tmp = bucket[j];
			for (int k = 0; k < i; k++) tmp /= 10;
			tmp %= 10;
			buc[tmp].push_back(bucket[j]);
		}
		
		bucket.clear();
		for (int j = 0; j < 10; j++) {
			buc[j] = InsertionSort2(buc[j]);
			for (int k = 0; k < buc[j].size(); k++) {
				bucket.push_back(buc[j][k]);
			}
		}
		for (int j = 0; j < 10; j++) {
			buc[j].clear();
		}

		output(1, i + 1);
	}
}

int bin(vector<int> vec, int l, int r, int tar) {
	if (r >= l) {
		int mid = (l + r) / 2;
		if (vec[mid] == tar) {
			cout << tar << " Found\n\n";
			return mid;
		}
		cout << vec[mid] << ' ';
		if (vec[mid] > tar) return bin(vec, l, mid - 1, tar);
		return bin(vec, mid + 1, r, tar);
	}
	cout << "Not found\n\n";
}

void sort::BinarySearch(int number, int target) {
	//TODO:
	//number = 0 means that use the insertion vector to find the target
	//number = 1 means that use the bucket vector to find the target
	//target means that we want to find the number.
	vector<int> vec;
	if (number == 0) vec = insertion;
	else vec = bucket;

	cout << "Searching : ";

	bin(vec, 0, vec.size() - 1, target);
	/*
	int id = 0;
	for (int i = 25; i >=0; i--) {
		if (id + (1 << i) < vec.size() && vec[id + (1 << i)] == target) {
			cout << target << " Found\n\n";
			return;
		}
		if (id + (1 << i) < vec.size() && vec[id + (1 << i)] < target) {
			id += 1 << i;
			cout << vec[id] << ' ';
		}
		else if (id + (1 << i) < vec.size()) {
			cout << vec[id + (1 << i)] << ' ';
		}
	}
	cout << "Not found\n\n";
	*/
}

void sort::output(int number, int round) {
	if (number == 0) {
		cout << "Insertion Sort : ";
		//TODO:  output the insertion sort result
		for (int i = 0; i < insertion.size(); i++) {
			cout << insertion[i] << ' ';
		}
		cout << endl;
	}
	else {
		if (round == 1) cout << "Bucket Sort" << endl;
		cout << round << " : ";
		//TODO: output the bucket sort result each round
		for (int i = 0; i < bucket.size(); i++) {
			cout << bucket[i] << ' ' << flush;
		}
		cout << endl;
	}
}
