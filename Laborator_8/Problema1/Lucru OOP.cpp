#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cctype>


bool separator(char c) {
    return c == '.' || c == ',' || c == ' ' || c == '?' || c == '!';
}

std::vector<std::string> WordSplitting(const std::string& phrase) {
    std::vector<std::string> words;
    std::string word;

    for (size_t i = 0;i < phrase.size();++i) {
        char c = phrase[i];
        if (separator(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += std::tolower(c);
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

struct Compare {
    bool operator()(const std::pair<std::string, int>& A, const std::pair<std::string, int>& B) {
        if (A.second != B.second) return A.second < B.second;
        return A.first > B.first;
    }
};

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cout << "Failed to open" << '\n';
        return 1;
    }

    std::string line;
    std::string phrase;
    while (std::getline(input, line)) {
        phrase += line + " ";
    }

    std::vector<std::string> words = WordSplitting(phrase);

    std::map<std::string, int> wordCount;
    for (const auto& word : words) {
        ++wordCount[word];
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> pq;

    for (const auto& entry : wordCount) pq.push(entry);

    while (!pq.empty()) {
        std::cout << pq.top().first << " => " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}