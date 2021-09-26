#include <bits/stdc++.h>
#include "IHopfield.cpp"
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vec vector

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

class BinaryHopfield {
    private:
        ll networkSize;
        vec<vec<double>> weights;

        double activity(double activation){
            if (activation >= 0) return 1;
            else return -1;
        }

        vec<double> computeActivations(vec<double> states) {
            vec<double> activations(networkSize);

            for (int i = 0; i < networkSize; i++) {
                double sum = 0;
                for (int j = 0; j < networkSize; j++) {
                    sum += weights[i][j] * states[j];
                }
                activations[i] = sum;
            }

            return activations;
        }


    public:
        BinaryHopfield(ll networkSize) {
            this->networkSize = networkSize;
            vec<vec<double>> weights(networkSize, vec<double>(networkSize));
            this->weights = weights;
        }


        void learn(vec<vec<double>> memories) {
            ll memoryCount = memories.size();
            for (int i = 0; i < networkSize; i++) {
                for (int j = 0; j < networkSize; j++) {
                    double total = 0;
                    for (int k = 0; k < memoryCount; k++) {
                        total += memories[k][i] * memories[k][j];
                    }

                    weights[i][j] = total / memoryCount;
                }
            }
        }

        vec<double> evaluate(vec<double> input) {
            vec<double> newStates(networkSize);

            vec<double> activations = computeActivations(input);

            for (int i = 0; i < networkSize; i++) {
                newStates[i] = this->activity(activations[i]);
            }

            return newStates;
        }
};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    return 0;
}
