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

int get_sum(const std::vector<int>& numbers, DivisibleBy3Counter& counter) {
    for (int num : numbers) {
        counter(num);
    }
    return counter.sum;
}

int get_count(const std::vector<int>& numbers, DivisibleBy3Counter& counter) {
    for (int num : numbers) {
        counter(num);
    }
    return counter.count;
}

int main() {
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    DivisibleBy3Counter counter;

    int sum = get_sum(numbers, counter);
    std::cout << "get_sum() = " << sum << std::endl;

    
    counter = DivisibleBy3Counter();
    int count = get_count(numbers, counter);
    std::cout << "get_count() = " << count << std::endl;

    return 0;
}
