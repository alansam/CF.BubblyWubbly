//
//  bubblywubbly.cpp
//  CF.BubblyWubbly
//
//  Created by Alan Sampson on 4/1/21.
//

#include <iostream>
#include <iomanip>
#include <vector>
#if (__cplusplus > 201703L)
#include <span>
#endif  /* (__cplusplus > 201703L) */
#include <algorithm>
#include <compare>
#include <random>

using namespace std::literals::string_literals;

void vector(void);
void array(void);
#if (__cplusplus > 201703L)
void span(void);
void can_sort(void);
void bubble_of_string(std::span<std::string_view> bubble_me, bool asc = true);
#endif  /* (__cplusplus > 201703L) */

static
auto const tiddles(std::string(60, '~'));

//  MARK: lambda ps()
[[maybe_unused]]
auto ps = [](auto & str) {
  std::cout << str << '\n';
};

//  MARK: lambda show()
auto show = [](std::span<std::string_view> strings) {
  auto cc(0ul);
  auto constexpr cc_max(5ul);

  auto ps = [&cc](auto & str) {
    std::cout << std::setw(15) << str
              << (++cc % cc_max == 0 ? "\n"s : ""s);
  };

  std::for_each(strings.begin(), strings.end(), ps);
  cc = 0ul;
  std::cout << '\n' << tiddles << std::endl;
};

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.BubblyWubbly\n"s;
  std::cout << "C++ Version: "s << __cplusplus << std::endl;

  std::cout << '\n' << tiddles << std::endl;
  vector();

  std::cout << '\n' << tiddles << std::endl;
  array();

#if (__cplusplus > 201703L)
  std::cout << '\n' << tiddles << std::endl;
  span();

  can_sort();
#endif  /* (__cplusplus > 201703L) */

  return 0;
}

/*
 *  MARK: vector()
 */
void vector(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::vector<std::string_view> strings {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };

  show(strings);

  for (size_t s_(0); s_ < strings.size() - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < strings.size(); ++r_) {
      if (strings[s_] > strings[r_]) {
        std::swap(strings[s_], strings[r_]);
      }
    }
  }

  show(strings);

  return;
}

/*
 *  MARK: array()
 */
void array(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::string_view strings[] = {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };
  auto strings_el = sizeof(strings) / sizeof(*strings);

  show(strings);

  for (size_t s_(0); s_ < strings_el - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < strings_el; ++r_) {
      if (strings[s_] > strings[r_]) {
        std::swap(strings[s_], strings[r_]);
      }
    }
  }

  show(strings);

  return;
}

#if (__cplusplus > 201703L)
/*
 *  MARK: span()
 */
void span(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::string_view strings[] = {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };

  auto strspan = std::span { strings };

  show(strings);

  for (size_t s_(0); s_ < strspan.size() - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < strspan.size(); ++r_) {
      if (strspan[s_] > strspan[r_]) {
        std::swap(strspan[s_], strspan[r_]);
      }
    }
  }

  show(strings);

  return;
}
#endif  /* (__cplusplus > 201703L) */

#if (__cplusplus > 201703L)
/*
 *  MARK: can_sort()
 */
void can_sort(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  auto cc(0UL);
  auto constexpr ccstr_max(5UL);
  auto psstr = [&cc](auto const & el) {
    std::cout << std::setw(15) << el
              << (++cc % ccstr_max == 0 ? "\n" : "");
  };

  auto display = [&](std::span<std::string_view> strings) {
    std::cout << tiddles << std::endl;
    cc = 0UL;
    std::for_each(strings.cbegin(), strings.cend(), psstr);
    putchar('\n');
  };

  auto bubble_this = [&](std::span<std::string_view> spanner) {
    auto rd0 = std::random_device();
    auto rng0 = std::mt19937(rd0());

    std::cout << "ascending\n"s;
    display(spanner);
    bubble_of_string(spanner);
    display(spanner);

    std::cout << "descending\n"s;
    std::shuffle(spanner.begin(), spanner.end(), rng0);
    display(spanner);
    bubble_of_string(spanner, false);
    display(spanner);
  };

  std::vector<std::string_view> ve_strings {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };

  std::cout << "sort std::vector<std::string_view>\n"s;
  bubble_this(ve_strings);

  std::array<std::string_view, 15> ar_strings {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };

  std::cout << "sort std::array<std::string_view, 15>\n"s;
  bubble_this(ar_strings);

  std::string_view sa_strings[] {
    "05 five",   "04 four",  "03 three", "02 two",    "01 one",
    "06 six",    "08 eight", "10 ten",   "00 zero",   "20 twenty",
    "11 eleven", "07 seven", "10 nine",  "20 twelve", "21 twentyone",
  };

  std::cout << "sort array of std::string_view\n"s;
  bubble_this(sa_strings);

  return;
}
#endif  /* (__cplusplus > 201703L) */

#if (__cplusplus > 201703L)
/*
 *  MARK: bubble_of_string()
 */
void bubble_of_string(std::span<std::string_view> bubble_me, bool asc) {
  std::cout << "In: " << __func__ << '\n' << std::endl;

  for (size_t s_(0); s_ < bubble_me.size() - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < bubble_me.size(); ++r_) {
      bool comp;
      if (asc) {
        comp = bubble_me[s_] > bubble_me[r_];
      }
      else {
        comp = bubble_me[s_] < bubble_me[r_];
      }

      if (comp) {
        std::swap(bubble_me[s_], bubble_me[r_]);
      }
    } /* r_ */
  } /* s_ */

  return;
}
#endif  /* (__cplusplus > 201703L) */
