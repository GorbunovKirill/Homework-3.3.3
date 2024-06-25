#include <iostream>
#include <vector>
#include <algorithm>

struct DivisibleBy3Counter {
    int sum = 0;
    int count = 0;

    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            count++;
        }
    }
};

int get_sum(const DivisibleBy3Counter& counter) {
    return counter.sum;
}

int get_count(const DivisibleBy3Counter& counter) {
    return counter.count;
}

int main() {
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    DivisibleBy3Counter counter;

    std::for_each(numbers.begin(), numbers.end(), std::ref(counter));

    int sum = get_sum(counter);
    std::cout << "get_sum() = " << sum << std::endl;

    int count = get_count(counter);
    std::cout << "get_count() = " << count << std::endl;

    return 0;
}
