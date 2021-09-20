#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vec vector

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

double thresholdActivity(double activation) {
    if (activation >= 0) return 1;
    else return -1;
}

vec<double> computeActivations(vec<double> states, vec<vec<double>> weights, int I) {
    vec<double> activations(I);

    for (int i = 0; i < I; i++) {
        double sum = 0;
        for (int j = 0; j < I; j++) {
            sum += weights[i][j] * states[j];
        }
        activations[i] = sum;
    }

    return activations;
}

vec<double> computeNewStates(vec<double> oldStates, vec<vec<double>> weights, int I) {
    vec<double> newStates(I);

    vec<double> activations = computeActivations(oldStates, weights, I);

    for (int i = 0; i < I; i++) {
        newStates[i] = thresholdActivity(activations[i]);
    }

    return newStates;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int networkSize = 1;
    int memoryCount = 0; // number of memories
    int iterationCount = 0; // number of iterations
    cin >> networkSize >> memoryCount >> iterationCount;

    vec<vec<double>> weights(networkSize, vec<double>(networkSize));
    vec<double> states(networkSize);

    vec<vec<double>> memories(memoryCount, vec<double>(networkSize));
    for (int i = 0; i < memoryCount; i++) {
        for (int j = 0; j < networkSize; j++) {
            cin >> memories[i][j];
        }
    }

    for (int i = 0; i < networkSize; i++) {
        for (int j = 0; j < networkSize; j++) {
            double total = 0;
            for (int k = 0; k < memoryCount; k++) {
                total += memories[k][i] * memories[k][j];
            }

            weights[i][j] = total / memoryCount;
        }
    }

    for (int i = 0; i < networkSize; i++) {
        cin >> states[i];
    }

    for (int iteration = 0; iteration < iterationCount; iteration++) {
        vec<double> newStates = computeNewStates(states, weights, networkSize);

        for (int i = 0; i < networkSize; i++) {
            cout << newStates[i] << " ";
        }
        cout << "\n";
        states = newStates;
    }

    return 0;
}
