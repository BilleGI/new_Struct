#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

void initialization(std::vector<int>& arr)
{
    while(true)
    {
        char answer;
        int num;
        std::cout << "Enter a number: ";
        while(!(std::cin >> num))
        {
            std::cout << "Enter the correct number:";
            std::cin.clear();
            std::cin.ignore();
        }
        arr.push_back(num);
        std::cout << "Add number?(y/n) ";
        std::cin >> answer;
        if(answer == 'n') break;
    }
}

auto unique_mean = [](std::vector<int>& arr)
{
    std::unordered_set<int> uniq(arr.begin(), arr.end());
    for(auto&& it:uniq)
    {
        int count = 0;
        for(auto&& vec_it:arr)
        {
            if (vec_it == it) count ++;
        }
        std::cout << "Element - " << it << " quantity - " << count << std::endl;
    }
    std::unique_ptr<std::vector<int>> smart{std::make_unique<std::vector<int>>(uniq.begin(), uniq.end())};
    return smart;
};

int main()
{
    std::vector<int> array;
    initialization(array);
    std::unique_ptr<std::vector<int>> ptr_uniq = unique_mean(array);
    for(auto&& it:(*ptr_uniq))
    {
        std::cout << it << std::endl;
    }
    return 0;
}
