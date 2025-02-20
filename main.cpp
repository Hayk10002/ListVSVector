#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <random>
#include <format>

// Random number from 0 to max-1 inclusive
int getRandomNum(int max)
{
    static std::mt19937 engine{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(0, max - 1);
    return dist(engine);
}

// Add number to container in sorted order
template<class Container>
void AddNum(Container& cont, int n)
{
    auto it = cont.begin();
    for (;it != cont.end() && *it < n; ++it);
    cont.insert(it, n);
}

// Remove number from container by index
template<class Container>
void RemoveInd(Container& cont, int ind)
{
    auto it = cont.begin();
    for (int i = 0; i < ind; i++) ++it;
    cont.erase(it);
}

// Benchmarks the given function by running it N times and returns the time in milliseconds
template<class F>
int time_ms(F f, int N)
{
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < N; i++) f();
    return (int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
}

int main() {
    int N;
    std::cout << "Enter number count: ";
    std::cin >> N;
    std::cout << std::endl;

    std::vector<int> v;
    std::list<int> l;

    int v_add_time = time_ms([&v](){ AddNum   (v, getRandomNum((int)1000    )); }, N);
    int v_rem_time = time_ms([&v](){ RemoveInd(v, getRandomNum((int)v.size())); }, N);
    int l_add_time = time_ms([&l](){ AddNum   (l, getRandomNum((int)1000    )); }, N);
    int l_rem_time = time_ms([&l](){ RemoveInd(l, getRandomNum((int)l.size())); }, N);
    int v_time = v_add_time + v_rem_time;
    int l_time = l_add_time + l_rem_time;
    
    std::cout << std::format(
        "         |   Add   |  Remove  |   Sum   \n"
        "---------|---------|----------|---------\n"
        "Vector   | {0:6}ms|  {1:6}ms| {4:6}ms\n"
        "---------|---------|----------|---------\n"
        "List     | {2:6}ms|  {3:6}ms| {5:6}ms\n",
        v_add_time, v_rem_time, l_add_time, l_rem_time, v_time, l_time
    );

    return 0;
}
