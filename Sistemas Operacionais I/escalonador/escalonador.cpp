#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Processo {
    private:
        int pid;
        int arrival_time = 0;
        int burst_time = 0;

    public:
        Processo(int pid, int arrival_time, int burst_time) {
            this->pid = pid;
            this->arrival_time = arrival_time;
            this->burst_time = burst_time;
        }

        int getPID() { return this->pid; }
        int getArrivalTime() { return this->arrival_time; }
        int getBurstTime() { return this->burst_time; }
        void getInfos() {
            cout << "--- Infos do Processo ---" << endl;
            cout << "PID: " << this->pid << endl;
            cout << "Arrival Time: " << this->arrival_time << endl;
            cout << "Burst Time: " << this->burst_time << endl;
        }
        void setBurstTime(int burst_time) { this->burst_time += burst_time; }
};

void round_robin(int quantum, vector<Processo> &p) {
    int n = p.size();

    vector<int> burstTimesTemp, waitingTimes, turnAroundTimes;
    for(int i = 0; i < n; i++){
        int bt = p[i].getBurstTime();
        burstTimesTemp.push_back(bt);
    }

    int t = 0;
    while (true) { 
        bool done = true; 
        for (int i = 0; i < burstTimesTemp.size(); i++) { 
            if (burstTimesTemp[i] > 0) { 
                done = false;
                if (burstTimesTemp[i] > quantum) { 
                    t += quantum; 
                    burstTimesTemp[i] -= quantum; 
                } else { 
                    t += burstTimesTemp[i]; 
                    waitingTimes.push_back(t - burstTimesTemp[i]); 
                    burstTimesTemp[i] = 0; 
                } 
            } 
        }
        if (done) break; 
    } 

    for(int i = 0; i < n; i++) turnAroundTimes.push_back(p[i].getBurstTime() + waitingTimes[i]);

    int totalTurnAroundTimes = 0, totalWaitingTime = 0;
    for(int i = 0; i < n; i++){
        p[i].getInfos();
        cout << "Turn Around Time: " << turnAroundTimes[i] << endl;
        cout << "Waiting Time: " << waitingTimes[i] << endl;
        totalTurnAroundTimes += turnAroundTimes[i];
        totalWaitingTime += waitingTimes[i];
    }

    cout << endl << "-- Averages Times --" << endl;
    cout << "Average Turn Around Time = " << (float) totalTurnAroundTimes / (float) n << endl;
    cout << "Average Waiting Time = " << (float) totalWaitingTime / (float) n << endl;
    cout << endl;
}

vector<Processo> input() {
    freopen("input", "r", stdin);

    string line_input, activity, type;
    int time, pid = 0, burstTime, arrivalTime = -1, cpu, io;
    vector<Processo> processos;

    while (getline(cin, line_input)) {
        burstTime = 0, cpu = 0, io = 0, pid++, arrivalTime++;
        stringstream ss(line_input);
        while (getline(ss, activity, ',')) {
            stringstream ss2(activity);
            ss2 >> time >> type;
            burstTime += time;
        }
        Processo a(pid, arrivalTime, burstTime);
        processos.push_back(a);
    }
    return processos;
}

int main(void) {
    vector<Processo> processos = input();

    round_robin(30, processos); // Politica de Escalonamento com Round-Robin e quantum de 30

    return 0;
}