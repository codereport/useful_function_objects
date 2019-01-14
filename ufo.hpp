#include <algorithm>

// UFO = Useful Function Objects

// ufo::min{}
// ufo::max{}
// ufo::abs_diff{}

namespace ufo {

   // STRUCT TEMPLATE min
  template<class _Ty = void> struct min {
    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
      return (std::min(_Left, _Right));
    }
  };

  // STRUCT TEMPLATE SPECIALIZATION min
  template<>
  struct min<void> { 
    // transparent functor for operator*
      typedef int is_transparent;
      template<class _Ty1, class _Ty2>
      constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const 
        -> decltype(std::min(static_cast<_Ty1&&>(_Left), static_cast<_Ty2&&>(_Right))) {
          return (std::min(static_cast<_Ty1&&>(_Left), static_cast<_Ty2&&>(_Right)));
      }
  };

  // STRUCT TEMPLATE max
  template<class _Ty = void> struct max {
    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
      return (std::max(_Left, _Right));
    }
  };

  // STRUCT TEMPLATE SPECIALIZATION max
  template<>
  struct max<void> { 
    // transparent functor for operator*
      typedef int is_transparent;
      template<class _Ty1, class _Ty2>
      constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const 
        -> decltype(std::max(static_cast<_Ty1&&>(_Left), static_cast<_Ty2&&>(_Right))) {
          return (std::max(static_cast<_Ty1&&>(_Left), static_cast<_Ty2&&>(_Right)));
      }
  };

   // STRUCT TEMPLATE abs_diff
  template<class _Ty = void> struct abs_diff {
    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
      return (std::abs(_Left - _Right));
    }
  };

  // STRUCT TEMPLATE SPECIALIZATION abs_diff
  template<>
  struct abs_diff<void> { 
    // transparent functor for operator*
      typedef int is_transparent;
      template<class _Ty1, class _Ty2>
      constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const 
        -> decltype(std::abs(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right))) {
          return (std::abs(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right)));
      }
  };
}
