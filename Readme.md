# Hopfield Network

Algorithm is based on the Hopfield network as described by MacKay.

>  MacKay, D. J. C. (2005). Information theory, inference, and learning algorithms  (Reprinted with corrections.). Cambridge University Press.

# Compilation
```
cd ./src && g++ hopfield.cpp -o hopfield
```

# Tool usage
```
./hopfield
```

First line: `I (0 < I)`, `N (0 <= N)`, `T (0 < T)`.
`I` integer number of vertices/neurons in the Hopfield network
`N` integer number of memories for the Hopfield network to learn
`T` Number of iterations of the network to run

The next `N` lines:
Each line will have `I` states (each state `-1` or `1`) which correspond to a particular memory.

The next line will have `I` states (each state `-1` or `1`) which represent the initial states of the network.

The program will then output `T` lines.
The first line will be the result of running one iteration of the network on initial state. The `i`th line will be result of running `i` iterations of the network on initial state. 


# Example
## Input
```
16 2 1
-1 -1 1 -1 -1 -1 1 -1 1 1 1 1 -1 -1 1 -1
1 1 -1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 1 1 -1 1 1 1 -1 1 1 1 1 -1 -1 1 -1
```

## Output
```
-1 -1 1 -1 -1 -1 1 -1 1 1 1 1 -1 -1 1 -1 
-1 -1 1 -1 -1 -1 1 -1 1 1 1 1 -1 -1 1 -1 
-1 -1 1 -1 -1 -1 1 -1 1 1 1 1 -1 -1 1 -1 
-1 -1 1 -1 -1 -1 1 -1 1 1 1 1 -1 -1 1 -1
```
