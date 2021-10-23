#include <bits/stdc++.h>

template<typename T>
void read_int(T& n) {
  char c;
  while (!(std::isdigit(c = getchar()) || c == '-'));

  bool neg = (c == '-');
  n = neg ? 0 : (c - '0');
  while (std::isdigit(c = getchar()))
    n = (n << 3) + (n << 1) + (c - '0');
  if (neg) n = ~n + 1;
}

int main(const int argc, const char** argv) {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);

  return EXIT_SUCCESS;
}
