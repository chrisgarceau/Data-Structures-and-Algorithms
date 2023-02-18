#include <iostream>
#include <string>
#include <queue>
#include <list>


std::string mirrorString(std::string);

double myseries( unsigned long n  );

unsigned long count7( unsigned long n );

bool split13_3(const long nums[], const size_t count);
//split13_3_helper function prototype
bool split13_3_helper(const long nums[], const size_t count, int start, int left_sum, int right_sum);

std::string repeat(std::string s, unsigned int i);

long mult(long j, long k);

void string_permutations(std::string str, size_t n, std::list<std::string>& list_of_permutations, size_t i = 0);

/*
Write a recursive method that receives a queue of type T.  The function pops and OUTPUTS to cout the reversed queue.
*/
template <typename T>
void outRevQueue(std::queue<T> &q) {
    if (q.empty()) {
        return;
    }
   T num = q.front();
   q.pop();
   outRevQueue(q);
   std::cout << num;
}