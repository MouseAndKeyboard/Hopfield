
#include <bits/stdc++.h>
#include "hopfield.cpp"
#include "continuous_hopfield.cpp"
#define endl "\n"
#define F first;
#define S second;
#define pb push_back;
#define mp make_pair;
#define vec vector

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void RunBinaryHopfield() {
    int networkSize = 1;
    int memoryCount = 0; // number of memories
    int iterationCount = 0; // number of iterations
    cin >> networkSize >> memoryCount >> iterationCount;

    BinaryHopfield *hopfield = new BinaryHopfield(networkSize);


    vec<vec<double>> memories(memoryCount, vec<double>(networkSize));
    for (int i = 0; i < memoryCount; i++) {
        for (int j = 0; j < networkSize; j++) {
            cin >> memories[i][j];
        }
    }

    hopfield->learn(memories);

    vec<double> states(networkSize);

    for (int i = 0; i < networkSize; i++) {
        cin >> states[i];
    }

    for (int iteration = 0; iteration < iterationCount; iteration++) {
        vec<double> newStates = hopfield->evaluate(states);

        for (int i = 0; i < networkSize; i++) {
            cout << newStates[i] << " ";
        }
        cout << "\n";
        states = newStates;
    }
}

void RunContinuousHopfield() {
    int networkSize = 1;
    int memoryCount = 0; // number of memories
    int iterationCount = 0; // number of iterations
    cin >> networkSize >> memoryCount >> iterationCount;

    ContinuousHopfield *hopfield = new ContinuousHopfield(networkSize, 0.5);

    vec<vec<double>> memories(memoryCount, vec<double>(networkSize));
    for (int i = 0; i < memoryCount; i++) {
        for (int j = 0; j < networkSize; j++) {
            cin >> memories[i][j];
        }
    }

    hopfield->learn(memories);

    vec<double> states(networkSize);

    for (int i = 0; i < networkSize; i++) {
        cin >> states[i];
    }

    for (int iteration = 0; iteration < iterationCount; iteration++) {
        vec<double> newStates = hopfield->evaluate(states);

        for (int i = 0; i < networkSize; i++) {
            cout << newStates[i] << " ";
        }
        cout << "\n";
        states = newStates;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc != 2) {
        cout << "please provide argument [binary/continuous]";
        return 1;
    }

    if (strcmp(argv[1], "binary") == 0) {
        RunBinaryHopfield();
    } else if (strcmp(argv[1], "continuous")) {
        RunContinuousHopfield();
    }

    return 0;
}
