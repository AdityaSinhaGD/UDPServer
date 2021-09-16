#pragma once
#include <iostream>
#include <vector>
#include <sstream>

void PrintVector(const std::vector<int>& nums) {
    for (auto& num : nums) {
        std::cout << num << " ";
    }
}

void Print2dVector(const std::vector<std::vector<int>>& vector2D) {

    for (auto& nums : vector2D) {
        for (auto& num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

}

void StringToNumVector(const std::string& sample, const char& delimiter, std::vector<int>& result) {
    std::stringstream s_stream(sample); //create string stream from the string
    while (s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, delimiter); //get first string delimited by comma
        result.push_back(std::stoi(substr));
    }
}
