#include <iostream>
using namespace std;

struct Process {
    string id;
    int at, bt, rt, ct, tat, wt;
};

// circular queue
class CQueue {
    int q[20], front, rear;
public:
    CQueue() { front = rear = -1; }
    
    bool empty() { return front == -1; }

    void enqueue(int x) {
        if ((front == 0 && rear == 19) || ((rear + 1) % 20 == front))
            return; 
        if (front == -1) front = rear = 0;
        else rear = (rear + 1) % 20;
        q[rear] = x;
    }

    int dequeue() {
        if (empty()) return -1;
        int x = q[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 20;
        return x;
    }
};

int main() {
    const int n = 5;
    int tq = 2; 
    Process p[n] = {
        {"P1",0,5,5,0,0,0},
        {"P2",1,3,3,0,0,0},
        {"P3",2,1,1,0,0,0},
        {"P4",3,2,2,0,0,0},
        {"P5",4,3,3,0,0,0}
    };

    int time = 0, done = 0;
    bool entered[n] = {0};
    CQueue q;

    cout << "\nOrder of execution: ";

    while (done < n) {
        for (int i = 0; i < n; i++)
            if (p[i].at <= time && !entered[i]) {
                q.enqueue(i);
                entered[i] = true;
            }

        if (q.empty()) { time++; continue; }

        int i = q.dequeue();
        int run = min(p[i].rt, tq);
        p[i].rt -= run;
        time += run;

        cout << p[i].id << " ";

        for (int j = 0; j < n; j++)
            if (p[j].at <= time && !entered[j]) {
                q.enqueue(j);
                entered[j] = true;
            }

        if (p[i].rt > 0)
            q.enqueue(i);
        else {
            p[i].ct = time;
            done++;
        }
    }

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }
}
