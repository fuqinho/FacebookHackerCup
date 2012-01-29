#include <iostream>
#include <vector>
using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;

vector<int> merge(const vector<int>& arr1, const vector<int>& arr2, string& ds, int& dsi) {
    vector<int> result;
    int i1 = 0, i2 = 0;
    while (i1 < arr1.size() && i2 < arr2.size()) {
        if (ds[dsi] == '1') {
            result.push_back(arr1[i1]);
            i1++;
        } else {
            result.push_back(arr2[i2]);
            i2++;
        }
        dsi++;
    }
    if (i1 < arr1.size()) for (int i = i1; i < arr1.size(); i++) result.push_back(arr1[i]);
    if (i2 < arr2.size()) for (int i = i2; i < arr2.size(); i++) result.push_back(arr2[i]);
    return result;
}

vector<int> merge_sort(const vector<int>& arr, string& ds, int& dsi) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;
   
    vector<int> first_array(arr.begin(), arr.begin() + mid);
    vector<int> second_array(arr.begin() + mid, arr.end());

    vector<int> first_half = merge_sort(first_array, ds, dsi);
    vector<int> second_half = merge_sort(second_array, ds, dsi);
    return merge(first_half, second_half, ds, dsi);
}

int checksum(vector<int>& arr) {
    int result = 1;
    for (int i = 0; i < arr.size(); i++) {
        result = (31 * result + arr[i]) % 1000003;
    }
    return result;
}

vector<int> recover(int N, string ds) {
    vector<int> orig(N);
    for (int i = 0; i < N; i++) orig[i] = i;

    int dsi = 0;
    vector<int> v = merge_sort(orig, ds, dsi);

    vector<int> recovered(N);
    for (int i = 0; i < v.size(); i++) recovered[v[i]] = i + 1;

    return recovered;
}

int solve(int N, string ds) {
    vector<int> recovered = recover(N, ds);
    return checksum(recovered);
}

int main() {
    //test_all(100);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; string DS;
        cin >> N >> DS;
        int answer = solve(N, DS);
        cout << "Case #" << i+1 << ": " << answer << endl;
    }
}

//// code for testing /////
/*
vector<int> merge(const vector<int>& arr1, const vector<int>& arr2, string& ds) {
    vector<int> result;
    int i1 = 0, i2 = 0;
    while (i1 < arr1.size() && i2 < arr2.size()) {
        if (arr1[i1] < arr2[i2]) {
            ds.push_back('1');
            result.push_back(arr1[i1]);
            i1++;
        } else {
            ds.push_back('2');
            result.push_back(arr2[i2]);
            i2++;
        }
    }
    if (i1 < arr1.size()) for (int i = i1; i < arr1.size(); i++) result.push_back(arr1[i]);
    if (i2 < arr2.size()) for (int i = i2; i < arr2.size(); i++) result.push_back(arr2[i]);
    return result;
}
vector<int> merge_sort(const vector<int>& arr, string& ds) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;
   
    vector<int> first_array(arr.begin(), arr.begin() + mid);
    vector<int> second_array(arr.begin() + mid, arr.end());

    vector<int> first_half = merge_sort(first_array, ds);
    vector<int> second_half = merge_sort(second_array, ds);
    return merge(first_half, second_half, ds);
}

bool test() {
    int n = rand() % 10000;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++) v[i] = i + 1;
    random_shuffle(v.begin(), v.end());

    //dump(n);
    //for (int i = 0; i < 10 && i < v.size(); i++) cerr << v[i] << " "; cerr << endl;

    string ds = "";
    vector<int> v2 = merge_sort(v, ds);
    //for (int i = 0; i < 10 && i < v2.size(); i++) cerr << v2[i] << " "; cerr << endl;
    //for (int i = 0; i < 10 && i < ds.size(); i++) cerr << ds[i] << " "; cerr << "..." << endl;

    vector<int> v3 = recover(n, ds);
    //for (int i = 0; i < 10 && i < v3.size(); i++) cerr << v3[i] << " "; cerr << endl;
    
    return v == v3;
}

void test_all(int n) {
    for (int i = 0; i < n; i++) {
        bool result = test();
        cerr << "[" << i+1 << "] " << (result ? "OK" : "NG") << endl;
    }
}

*/
////// END code for testing /////

