/*
 * This is the UnitTesting module, which provides methods for running each
 * class's unit tests and displaying the results to the console.
 */
#ifndef __UNIT_TESTS_H__
#define __UNIT_TESTS_H__

class UnitTestResult
{
public:
    UnitTestResult();
    UnitTestResult(const std::vector<std::string> &test_names,
            const std::vector<bool> &test_results,
            const std::vector<std::string> &reasons);
    ~UnitTestResult();

    bool assert(bool predicate, const std::string &class_name,
            const std::string &test_name, const std::string &fail_reason);

    void print() const;

private:
    std::vector<std::string> test_names;
    std::vector<bool> test_results;
    std::vector<std::string> reasons;
};



#endif //header guard




