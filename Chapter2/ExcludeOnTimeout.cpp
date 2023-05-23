//
// Created by saad.hussain on 5/23/2023.
//

#include <set>
#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>
class PerfectFailureDetector {
public:
    PerfectFailureDetector(const std::set<int>& processes, int delay)
            : all_processes(processes), delta(delay)
    {
        std::thread([this] {
            start_timer();
        }).detach();
    }

    void deliver_heartbeat_request(int q) {
        std::thread([this, q] {
            send_heartbeat_reply(q);
        }).detach();
    }

    void deliver_heartbeat_reply(int p) {
        alive.insert(p);
    }

private:
    std::set<int> all_processes;
    std::set<int> alive;
    std::set<int> detected;
    int delta;

    void start_timer() {
        std::this_thread::sleep_for(std::chrono::seconds(delta));
        timeout();
    }

    void timeout() {
        for (int p : all_processes) {
            if (alive.find(p) == alive.end() && detected.find(p) == detected.end()) {
                detected.insert(p);
                trigger_crash(p);
                send_heartbeat_request(p);
            }
        }
        alive.clear();
        start_timer();
    }

    void trigger_crash(int p) {
        std::cout << "Process " << p << " has crashed.\n";
    }

    void send_heartbeat_request(int p) {
        std::cout << "Sending heartbeat request to process " << p << ".\n";
    }

    void send_heartbeat_reply(int q) {
        std::cout << "Sending heartbeat reply to process " << q << ".\n";
    }
};


int main() {
    std::set<int> processes = {1, 2, 3, 4, 5};
    int delay = 2; // seconds
    PerfectFailureDetector pfd(processes, delay);

    // Simulate some heartbeat messages.
    // These would normally come from separate threads or machines.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pfd.deliver_heartbeat_reply(1);
    pfd.deliver_heartbeat_reply(2);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    pfd.deliver_heartbeat_reply(3);
    pfd.deliver_heartbeat_reply(4);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    pfd.deliver_heartbeat_reply(5);

    // Let the detector run for a while.
    std::this_thread::sleep_for(std::chrono::seconds(30));

    return 0;
}




