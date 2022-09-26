#include "LeetCode.h"

using namespace Sept2022;

int main() {
    ITestable* test = new CrawlerLogFolder;
    test->run_test();
    delete test;
    return 0;
}
