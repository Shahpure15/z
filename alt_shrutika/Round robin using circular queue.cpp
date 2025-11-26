#include <iostream>
#include <queue>
using namespace std;

struct Process {
    string pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
};

int main() {
    int n = 5;
    int tq = 2; // Time Quantum (You can change it)
    
    Process p[5] = {
        {"P1",0,5,5,0},
        {"P2",1,3,3,0},
        {"P3",2,1,1,0},
        {"P4",3,2,2,0},
        {"P5",4,3,3,0}
    };

    queue<int> cq;   // Circular queue using STL queue
    int time = 0;
    int completed = 0;

    // Add first process
    cq.push(0);

    bool inQueue[5] = {false};
    inQueue[0] = true;

    cout << "\n--- Round Robin CPU Scheduling (Time Quantum = " << tq << ") ---\n";

    while (completed != n) {

        if (!cq.empty()) {
            int idx = cq.front();
            cq.pop();

            // Process execution
            if (p[idx].remaining > tq) {
                cout << "Time " << time << " : " << p[idx].pid 
                     << " executed for " << tq << " units\n";
                time += tq;
                p[idx].remaining -= tq;
            }
            else {
                cout << "Time " << time << " : " << p[idx].pid 
                     << " executed for " << p[idx].remaining << " units (Completed)\n";
                time += p[idx].remaining;
                p[idx].remaining = 0;
                p[idx].completion = time;
                completed++;
            }

            // Add newly arrived processes
            for (int i = 0; i < n; i++) {
                if (p[i].arrival <= time && !inQueue[i] && p[i].remaining > 0) {
                    cq.push(i);
                    inQueue[i] = true;
                }
            }

            // Re-add current process if not done
            if (p[idx].remaining > 0) {
                cq.push(idx);
            }
        } 
        else {
            time++;  // If no process, just increment CPU idle time
        }
    }

    cout << "\n--- Completion Times ---\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << " completed at time " << p[i].completion << endl;
    }

    return 0;
}
