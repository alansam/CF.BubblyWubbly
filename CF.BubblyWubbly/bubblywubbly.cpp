//
//  bubblywubbly.cpp
//  CF.BubblyWubbly
//
//  Created by Alan Sampson on 4/1/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#if (__cplusplus > 201703L)
#include <span>
#endif  /* (__cplusplus > 201703L) */
#include <algorithm>
#include <compare>
#include <random>
#include <functional>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

void vector(void);
void array(void);
#if (__cplusplus > 201703L)
void span(void);
void can_sort(void);
void bubbly_sort(void);
void bubbler_sort(void);
void bubble_of_string(std::span<std::string_view> bubble_me, bool asc = true);
#endif  /* (__cplusplus > 201703L) */

static
auto const tiddles(std::string(60, '~'));

//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  MARK: lambda ps()
[[maybe_unused]]
auto ps = [](auto & str) {
  std::cout << str << '\n';
};

//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  MARK: lambda show()
auto show = [](std::span<std::string_view> strings) {
  auto cc(0ul);
  auto constexpr cc_max(5ul);

  auto ps = [&cc](auto & str) {
    std::cout << std::setw(15) << str
              << (++cc % cc_max == 0 ? "\n"sv : ""sv);
  };

  std::for_each(strings.begin(), strings.end(), ps);
  cc = 0ul;
  std::cout << '\n' << tiddles << std::endl;
};

//  MARK: - template bubbly
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: template bubbly()
 */
template <class C>
void bubbly(std::span<C> bubble_me, bool asc = true) {
  std::cout << "In: "sv << __func__ << '\n' << std::endl;

  for (size_t s_(0); s_ < bubble_me.size() - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < bubble_me.size(); ++r_) {
      auto comp = asc ? std::greater<C>{}(bubble_me[s_], bubble_me[r_])
                      : std::less<C>{}(bubble_me[s_], bubble_me[r_]);

      if (comp) {
        std::swap(bubble_me[s_], bubble_me[r_]);
      }
    } /* r_ */
  } /* s_ */

  return;
}
#endif  /* (__cplusplus > 201703L) */

//  MARK: - template bubbler
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: template bubbler()
 */
template <class C, typename Cmp = std::greater<>>
void bubbler(std::span<C> bubble_me, Cmp compare = Cmp{}) {
  std::cout << "In: "sv << __func__ << '\n' << std::endl;

  for (size_t s_(0); s_ < bubble_me.size() - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < bubble_me.size(); ++r_) {
      auto comp = compare(bubble_me[s_], bubble_me[r_]);

      if (comp) {
        std::swap(bubble_me[s_], bubble_me[r_]);
      }
    } /* r_ */
  } /* s_ */

  return;
}
#endif  /* (__cplusplus > 201703L) */

//  MARK: - main
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
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

  bubbly_sort();

  bubbler_sort();
#endif  /* (__cplusplus > 201703L) */

  return 0;
}

//  MARK: - vector
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: vector()
 */
void vector(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::vector<std::string_view> strings {
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
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

//  MARK: - array
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: array()
 */
void array(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::string_view strings[] = {
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
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

//  MARK: - span
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: span()
 */
void span(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  std::string_view strings[] = {
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
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

//  MARK: - can_sort
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: can_sort()
 */
void can_sort(void) {
  std::cout << "In: "s << __func__ << '\n' << std::endl;

  auto cc(0UL);
  auto constexpr ccstr_max(5UL);
  auto psstr = [&cc](auto const & el) {
    std::cout << std::setw(15) << el
              << (++cc % ccstr_max == 0 ? "\n"sv : ""sv);
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
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
  };

  std::cout << "sort std::vector<std::string_view>\n"s;
  bubble_this(ve_strings);

  std::array<std::string_view, 15> ar_strings {
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
  };

  std::cout << "sort std::array<std::string_view, 15>\n"s;
  bubble_this(ar_strings);

  std::string_view sa_strings[] {
    "05 five"sv,   "04 four"sv,  "03 three"sv, "02 two"sv,    "01 one"sv,
    "06 six"sv,    "08 eight"sv, "10 ten"sv,   "00 zero"sv,   "20 twenty"sv,
    "11 eleven"sv, "07 seven"sv, "10 nine"sv,  "20 twelve"sv, "21 twentyone"sv,
  };

  std::cout << "sort array of std::string_view\n"s;
  bubble_this(sa_strings);

  return;
}
#endif  /* (__cplusplus > 201703L) */

//  MARK: - bubbly_sort
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: bubbly_sort()
 */
void bubbly_sort(void) {
  std::cout << "In: "sv << __func__ << '\n' << std::endl;
  auto rd = std::random_device();
  auto rng = std::mt19937(rd());
  auto nshow = [](auto & container) {
    auto cc(0ul);
    auto constexpr cc_max(10ul);
    for (auto nr : container) {
      std::cout << std::setw(5) << nr
                << (++cc % cc_max == 0 ? "\n"sv : ""sv);
    }
    std::cout << '\n';
  };
  auto fshow = [](auto & container) {
    auto cc(0ul);
    auto constexpr cc_max(10ul);
    for (auto nr : container) {
      std::cout << std::setw(10) << std::fixed << std::setprecision(3) << nr
                << (++cc % cc_max == 0 ? "\n"sv : ""sv);
    }
    std::cout << '\n';
  };

  std::cout << "\nstd::vector<int>:\n"s;
  std::vector<int> va_ints {
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  };
  std::shuffle(va_ints.begin(), va_ints.end(), rng);
  nshow(va_ints);
  bubbly<int>(va_ints);
  nshow(va_ints);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_ints.begin(), va_ints.end(), rng);
  nshow(va_ints);
  bubbly<int>(va_ints, false);
  nshow(va_ints);

  std::cout << "\narray of char:\n"s;
  char aa_chars[] {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  };
  std::shuffle(std::begin(aa_chars), std::end(aa_chars), rng);
  nshow(aa_chars);
  bubbly<char>(aa_chars);
  nshow(aa_chars);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(std::begin(aa_chars), std::end(aa_chars), rng);
  nshow(aa_chars);
  bubbly<char>(aa_chars, false);
  nshow(aa_chars);

  std::cout << "\nstd::array<std::string_view, 26>:\n"s;
  std::array<std::string_view, 26> ar_strvw {
    "a"sv, "b"sv, "c"sv, "d"sv, "e"sv, "f"sv, "g"sv, "h"sv, "i"sv, "j"sv,
    "k"sv, "l"sv, "m"sv, "n"sv, "o"sv, "p"sv, "q"sv, "r"sv, "s"sv, "t"sv,
    "u"sv, "v"sv, "w"sv, "x"sv, "y"sv, "z"sv,
  };
  std::shuffle(ar_strvw.begin(), ar_strvw.end(), rng);
  nshow(ar_strvw);
  bubbly<std::string_view>(ar_strvw);
  nshow(ar_strvw);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(ar_strvw.begin(), ar_strvw.end(), rng);
  nshow(ar_strvw);
  bubbly<std::string_view>(ar_strvw, false);
  nshow(ar_strvw);

  std::cout << "\nstd::vector<double>:\n"s;
  std::vector<double> va_dubs {
     100.0,   101.01,  202.02,  303.03,  404.04,
     505.05,  606.06,  707.07,  808.08,  909.09,
    1000.0,  1101.01, 1202.02, 1303.03, 1404.04,
    1505.05, 1606.06, 1707.07, 1808.08, 1909.09,
  };
  std::shuffle(va_dubs.begin(), va_dubs.end(), rng);
  fshow(va_dubs);
  bubbly<double>(va_dubs);
  fshow(va_dubs);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_dubs.begin(), va_dubs.end(), rng);
  fshow(va_dubs);
  bubbly<double>(va_dubs, false);
  fshow(va_dubs);

  std::cout << "\nstd::string:\n"s;
  std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
  std::shuffle(alpha.begin(), alpha.end(), rng);
  nshow(alpha);
  bubbly<char>(alpha);
  nshow(alpha);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(alpha.begin(), alpha.end(), rng);
  nshow(alpha);
  bubbly<char>(alpha, false);
  nshow(alpha);

  return;
}
#endif  /* (__cplusplus > 201703L) */

//  MARK: - bubbler_sort
#if (__cplusplus > 201703L)
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: Structure student
 */
struct student {
public:
  int id;
  std::string name;
  double mark;
  bool pass;

  //  MARK: comparison operators plus default sort ordering (student.id)
  //  Equivalent to providing operator ==, !=, >, >=, <, <= ...
  std::strong_ordering operator<=>(student const & other) const {
    auto cmp = id <=> other.id;
    return cmp;
  }

  //  MARK: Other sort ordering method (student.id)
  struct id_less : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.id < rhs.id;
    }
  };

  struct id_greater : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.id > rhs.id;
    }
  };

  //  MARK: Other sort ordering method (student.mark)
  struct mark_less : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.mark < rhs.mark;
    }
  };

  struct mark_greater : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.mark > rhs.mark;
    }
  };

  //  MARK: Other sort ordering method (student.name)
  struct name_less : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.name < rhs.name;
    }
  };

  struct name_greater : std::binary_function<student, student, bool> {
    bool operator()(student const & lhs, student const & rhs) const {
      return lhs.name > rhs.name;
    }
  };

  //  MARK: Stringified version of structure
  std::string to_string() const {
    std::ostringstream os;
    os << std::setw(4) << id << ' '
       << std::setw(20) << name
       << std::fixed
       << std::setw(10) << std::setprecision(3) << mark << ' '
       << std::boolalpha << pass << std::noboolalpha;

    return os.str();
  }
};

//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: bubbler_sort()
 */
void bubbler_sort(void) {
  std::cout << "In: "sv << __func__ << '\n' << std::endl;

  auto rd = std::random_device();
  auto rng = std::mt19937(rd());

  //  MARK: show contents of digit container
  auto nshow = [](auto & container) {
    auto cc(0ul);
    auto constexpr cc_max(10ul);
    for (auto nr : container) {
      std::cout << std::setw(5) << nr
                << (++cc % cc_max == 0 ? "\n"sv : ""sv);
    }
    std::cout << '\n';
  };

  //  MARK: show contents of floating point container
  auto fshow = [](auto & container) {
    auto cc(0ul);
    auto constexpr cc_max(10ul);
    for (auto nr : container) {
      std::cout << std::setw(10) << std::fixed << std::setprecision(3) << nr
                << (++cc % cc_max == 0 ? "\n"sv : ""sv);
    }
    std::cout << '\n';
  };

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << "\nstd::vector<int>:\n"s;
  std::vector<int> va_ints {
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  };

  std::shuffle(va_ints.begin(), va_ints.end(), rng);
  nshow(va_ints);
  bubbler<int>(va_ints);
  nshow(va_ints);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_ints.begin(), va_ints.end(), rng);
  nshow(va_ints);
  bubbler<int, std::less<>>(va_ints);
  nshow(va_ints);

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << "\narray of char:\n"s;
  char aa_chars[] {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  };

  std::shuffle(std::begin(aa_chars), std::end(aa_chars), rng);
  nshow(aa_chars);
  bubbler<char>(aa_chars);
  nshow(aa_chars);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(std::begin(aa_chars), std::end(aa_chars), rng);
  nshow(aa_chars);
  bubbler<char, std::less<>>(aa_chars);
  nshow(aa_chars);

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << "\nstd::array<std::string_view, 26>:\n"s;
  std::array<std::string_view, 26> ar_strvw {
    "a"sv, "b"sv, "c"sv, "d"sv, "e"sv, "f"sv, "g"sv, "h"sv, "i"sv, "j"sv,
    "k"sv, "l"sv, "m"sv, "n"sv, "o"sv, "p"sv, "q"sv, "r"sv, "s"sv, "t"sv,
    "u"sv, "v"sv, "w"sv, "x"sv, "y"sv, "z"sv,
  };

  std::shuffle(ar_strvw.begin(), ar_strvw.end(), rng);
  nshow(ar_strvw);
  bubbler<std::string_view>(ar_strvw);
  nshow(ar_strvw);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(ar_strvw.begin(), ar_strvw.end(), rng);
  nshow(ar_strvw);
  bubbler<std::string_view, std::less<>>(ar_strvw);
  nshow(ar_strvw);

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << "\nstd::vector<double>:\n"s;
  std::vector<double> va_dubs {
     100.0,   101.01,  202.02,  303.03,  404.04,
     505.05,  606.06,  707.07,  808.08,  909.09,
    1000.0,  1101.01, 1202.02, 1303.03, 1404.04,
    1505.05, 1606.06, 1707.07, 1808.08, 1909.09,
  };

  std::shuffle(va_dubs.begin(), va_dubs.end(), rng);
  fshow(va_dubs);
  bubbler<double>(va_dubs);
  fshow(va_dubs);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_dubs.begin(), va_dubs.end(), rng);
  fshow(va_dubs);
  bubbler<double, std::less<>>(va_dubs);
  fshow(va_dubs);

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << "\nstd::string:\n"s;
  std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
  std::shuffle(alpha.begin(), alpha.end(), rng);
  nshow(alpha);
  bubbler<char>(alpha);
  nshow(alpha);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(alpha.begin(), alpha.end(), rng);
  nshow(alpha);
  bubbler<char, std::less<>>(alpha);
  nshow(alpha);

  //  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
  //  MARK: show contents of student structure container
  auto sshow = [](auto & collection) {
    for (auto student : collection) {
      std::cout << student.to_string() << '\n';
    }
    std::cout << '\n';
  };

  std::vector<student> va_stud {
    { 105, "Ann Onymouse"s, 90.5, true,  },
    { 102, "Ann Other"s,    98.7, true,  },
    {  13, "Jusin Ames"s,   70.3, false, },
    {  42, "Irma Alias"s,   89.7, true,  },
  };

  std::cout << std::string(60, '`') <<'\n';
  std::cout << "default\n"sv;
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, std::less<>>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '`') <<'\n';
  std::cout << "mark\n"sv;
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::mark_greater>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::mark_less>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '`') <<'\n';
  std::cout << "name\n"sv;
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::name_greater>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::name_less>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '`') <<'\n';
  std::cout << "id\n"sv;
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::id_greater>(va_stud);
  sshow(va_stud);
  std::cout << std::string(60, '~') << '\n';
  std::shuffle(va_stud.begin(), va_stud.end(), rng);
  sshow(va_stud);
  bubbler<student, student::id_less>(va_stud);
  sshow(va_stud);

  return;
}
#endif  /* (__cplusplus > 201703L) */

#if (__cplusplus > 201703L)
//  MARK: - bubble_of_string
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: bubble_of_string()
 */
void bubble_of_string(std::span<std::string_view> bubble_me, bool asc) {
  std::cout << "In: "sv << __func__ << '\n' << std::endl;

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
