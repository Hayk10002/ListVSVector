#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>
#include <random>

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

// Benchmarks the given function running it N times and returns the time in milliseconds
template<class F>
int time_ms(F f, int N)
{
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < N; i++) f();
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
}

int main() {
    int N;
    std::cout << "Enter number count: ";
    std::cin >> N;

    std::vector<int> v;
    std::list<int> l;

    std::cout << "Vec Add: " << time_ms([&v](){ AddNum(v, getRandomNum(1000)); }, N) << "ms\n";
    std::cout << "Vec Rem: " << time_ms([&v](){ RemoveInd(v,  getRandomNum(v.size())); }, N) << "ms\n";
    std::cout << "List Add: " << time_ms([&l](){ AddNum(l, getRandomNum(1000)); }, N) << "ms\n";
    std::cout << "List Rem: " << time_ms([&l](){ RemoveInd(l, getRandomNum(l.size())); }, N) << "ms\n";

    system("pause");
    return 0;
}
