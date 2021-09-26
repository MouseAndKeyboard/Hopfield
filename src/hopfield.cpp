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
