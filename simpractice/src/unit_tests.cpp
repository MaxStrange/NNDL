#include <iostream>
#include <string>
#include <vector>

#include "unit_tests.h"


UnitTestResult::UnitTestResult()
{
}

UnitTestResult::UnitTestResult(const std::vector<std::string> &test_names,
        const std::vector<bool> &test_results,
        const std::vector<std::string> &reasons)
{
    this->test_names = test_names;
    this->test_results = test_results;
    this->reasons = reasons;
}

UnitTestResult::~UnitTestResult()
{
}

bool UnitTestResult::assert(bool predicate, const std::string &class_name,
        const std::string &test_name, const std::string &fail_reason)
{
    this->test_names.push_back(std::string(class_name + "_" + test_name));
    if (predicate == false)
    {
        this->test_results.push_back(false);
        this->reasons.push_back(std::string(fail_reason));
    }
    else
    {
        this->test_results.push_back(true);
        this->reasons.push_back("");
    }

    return predicate;
}

void UnitTestResult::print() const
{
    std::cout << "==========TEST RESULTS=========" << std::endl;
    for (unsigned int i = 0; i < this->test_names.size(); i++)
    {
        std::string test_name = this->test_names.at(i);
        bool test_result = this->test_results.at(i);
        std::string result_string = test_result ? "pass" : "FAIL";
        std::string reason = this->reasons.at(i);

        std::cout << "Test: " << test_name << ": " <<
                result_string << ": " << reason << std::endl;
    }
    std::cout << "==========END TEST RESULTS=========" << std::endl;
}







