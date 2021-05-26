#ifndef IFINT_HPP
# define IFINT_HPP

namespace ft
{
	struct is_int {};
  	struct not_int {};

    template<typename T>
    struct is_integer {
      enum {value = 0};
	  typedef not_int type;
	};

    template<>
    struct is_integer<int> {
      enum {value = 1};
	  typedef is_int type;
	};
}

#endif