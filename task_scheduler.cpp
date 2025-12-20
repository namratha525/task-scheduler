#include <bits/stdc++.h>
using namespace std;

struct Task {
    string id;
    int priority;
    int arrival;
    int execution;
    int start_time = 0;
    int completion_time = 0;
};

struct Compare {
    bool operator()(Task* a, Task* b) {
        if (a->priority == b->priority)
            return a->arrival > b->arrival;   // earlier arrival first
        return a->priority < b->priority;     // higher priority first
    }
};

vector<Task*> scheduleTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.arrival < b.arrival;
    });

    priority_queue<Task*, vector<Task*>, Compare> pq;
    vector<Task*> completed;

    int time = 0, i = 0, n = tasks.size();

    while (i < n || !pq.empty()) {
        while (i < n && tasks[i].arrival <= time) {
            pq.push(&tasks[i]);
            i++;
        }

        if (!pq.empty()) {
            Task* curr = pq.top();
            pq.pop();

            curr->start_time = time;
            time += curr->execution;
            curr->completion_time = time;

            completed.push_back(curr);
        } else {
            time = tasks[i].arrival; // CPU idle
        }
    }

    return completed;
}

void printResults(const vector<Task*>& tasks) {
    double total_wait = 0, total_turn = 0;

    cout << "\nTask | Start | End | Waiting | Turnaround\n";
    cout << "-----------------------------------------\n";

    for (auto t : tasks) {
        int waiting = t->start_time - t->arrival;
        int turnaround = t->completion_time - t->arrival;

        total_wait += waiting;
        total_turn += turnaround;

        cout << t->id << "    | "
             << t->start_time << "     | "
             << t->completion_time << "   | "
             << waiting << "       | "
             << turnaround << "\n";
    }

    cout << "-----------------------------------------\n";
    cout << "Average Waiting Time: " << total_wait / tasks.size() << "\n";
    cout << "Average Turnaround Time: " << total_turn / tasks.size() << "\n";
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);

    cout << "Enter: TaskID Priority ArrivalTime ExecutionTime\n";
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].id
            >> tasks[i].priority
            >> tasks[i].arrival
            >> tasks[i].execution;
    }

    vector<Task*> completed = scheduleTasks(tasks);
    printResults(completed);

    return 0;
}
