#include <iostream>
#include <thread>

using std::lock_guard;
using std::mutex;
using std::cout;
using std::thread;
using std::this_thread::get_id;

mutex m;

void count(int from, int to) {
    for (int i = from; i < to; ++i) {
        lock_guard l(m);
        cout << "Thread " << get_id() << ": " << "my number is " << i << ".\n";
    }
}

int main() {
    thread t1(count, 1000, 2000);
    thread t2(count, 3000, 4000);
    thread t3(count, 4000, 5000);
    t1.join();
    t2.join();
    t3.join();
}