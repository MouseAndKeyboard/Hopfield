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

    int I = 1;
    cin >> I;
    vec<vec<double>> weights(I, vec<double>(I));
    vec<double> states(I);


    int N = 0; // number of memories
    cin >> N;
    vec<vec<double>> memories(N, vec<double>(I));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < I; j++) {
            cin >> memories[i][j];
        }
    }

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < I; j++) {
            double total = 0;
            for (int k = 0; k < N; k++) {
                total += memories[k][i] * memories[k][j];
            }

            weights[i][j] = total / N;
        }
    }

    for (int i = 0; i < I; i++) {
        cin >> states[i];
    }

    int iterations;
    cin >> iterations;
    for (int iteration = 0; iteration < iterations; iteration++) {
        vec<double> newStates = computeNewStates(states, weights, I);

        for (int i = 0; i < I; i++) {
            cout << newStates[i] << "\n";
        }
        states = newStates;
    }

    return 0;
}
