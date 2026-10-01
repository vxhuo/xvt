
module;

#include <concepts>
#include <type_traits>
#include <cstddef>

export module xvt.vec2;


import xvt.types;


namespace xvt
{

export template <Arithmetic A>
struct vec2 final
{
    A x, y;


    constexpr vec2() noexcept = default;
    constexpr vec2(const A value) noexcept;
    constexpr vec2(const A x, const A y) noexcept;


    template <typename U>
    [[nodiscard]]
    constexpr auto cast() const noexcept -> vec2<U>;

    auto data() const noexcept -> const A*;
    consteval auto size() const noexcept -> std::size_t;


    constexpr auto zero() noexcept -> void;
    constexpr auto one() noexcept -> void;
    constexpr auto set(const A value) noexcept -> void;


    [[nodiscard]]
    constexpr auto operator+(const vec2 rhs)    const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto operator+(const A value)     const noexcept -> vec2;
    constexpr auto operator+=(const vec2 rhs)         noexcept -> vec2&;
    constexpr auto operator+=(const A value)          noexcept -> vec2&;
    [[nodiscard]]
    constexpr auto operator-(const vec2 rhs)    const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto operator-(const A value)     const noexcept -> vec2;
    constexpr auto operator-=(const vec2 rhs)         noexcept -> vec2&;
    constexpr auto operator-=(const A value)          noexcept -> vec2&;
    [[nodiscard]]
    constexpr auto operator/(const vec2 rhs)    const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto operator/(const A value)     const noexcept -> vec2;
    constexpr auto operator/=(const vec2 rhs)         noexcept -> vec2&;
    constexpr auto operator/=(const A value)          noexcept -> vec2&;
    [[nodiscard]]
    constexpr auto operator*(const vec2 rhs)    const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto operator*(const A value)     const noexcept -> vec2;
    constexpr auto operator*=(const vec2 rhs)         noexcept -> vec2&;
    constexpr auto operator*=(const A value)          noexcept -> vec2&;
    [[nodiscard]]
    constexpr auto operator^(const vec2 rhs)    const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto operator^(const A value)     const noexcept -> vec2;
    constexpr auto operator^=(const vec2 rhs)         noexcept -> vec2&;
    constexpr auto operator^=(const A value)          noexcept -> vec2&;
    [[nodiscard]]
    constexpr auto operator-()                  const noexcept -> vec2;
    constexpr auto operator--()                       noexcept -> vec2&;
    constexpr auto operator++()                       noexcept -> vec2&;
    constexpr auto operator--(int)                    noexcept -> vec2;
    constexpr auto operator++(int)                    noexcept -> vec2;
    auto operator<=>(const vec2&)               const noexcept = default;

    [[nodiscard]]
    constexpr auto operator[](std::size_t index) noexcept -> A&;
    [[nodiscard]]
    constexpr auto operator[](std::size_t index) const noexcept -> const A&;

    constexpr auto xy() const noexcept -> vec2 { return {x, y}; }
    constexpr auto yx() const noexcept -> vec2 { return {y, x}; }


    [[nodiscard]]
    constexpr auto perp() const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto dot(const vec2<A> other) const noexcept -> A;
    [[nodiscard]]
    constexpr auto len_sq() const noexcept -> A;
    [[nodiscard]]
    constexpr auto len() const noexcept -> FT<A>;
    constexpr auto normalize() noexcept -> vec2&
        requires std::is_floating_point_v<A>;
    constexpr auto normalized() const noexcept -> vec2
        requires std::is_floating_point_v<A>;
    [[nodiscard]]
    constexpr auto dist(const vec2 other) const noexcept -> FT<A>;
    [[nodiscard]]
    constexpr auto dist_sq(const vec2 other) const noexcept -> A;
    constexpr auto lerp(const vec2 to, const FT<A> t) noexcept -> vec2&;
    constexpr auto lerped(const vec2 to, const FT<A> t) const noexcept -> vec2;
    constexpr auto abs() noexcept -> vec2&
        requires std::is_signed_v<A>;
    constexpr auto absed() const noexcept -> vec2
        requires std::is_signed_v<A>;
    constexpr auto clamp(const A min, const A max) noexcept -> vec2&;
    constexpr auto clamped(const A min, const A max) const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto equal(const vec2 other, const FT<A> epsilon) const noexcept -> bool
        requires std::floating_point<A>;
    [[nodiscard]]
    constexpr auto angle() const noexcept -> A
        requires std::floating_point<A>;
    constexpr auto angle(const vec2 other) const noexcept -> A
        requires std::floating_point<A>;
    [[nodiscard]]
    constexpr auto reject(const vec2 other) const noexcept -> vec2
        requires std::floating_point<A>;
    [[nodiscard]]
    constexpr auto project(const vec2 other) noexcept -> vec2&
        requires std::floating_point<A>;
    constexpr auto projected(const vec2 other) const noexcept -> vec2
        requires std::floating_point<A>;
    constexpr auto reflect() noexcept -> vec2&
        requires std::floating_point<A>;
    constexpr auto reflected() const noexcept -> vec2
        requires std::floating_point<A>;
    [[nodiscard]]
    constexpr auto cross(const vec2 other) const noexcept -> A;
    [[nodiscard]]
    constexpr auto rotate(const FT<A> angle) noexcept -> vec2&
    [[nodiscard]]
    constexpr auto rotated(const FT<A> angle) const noexcept -> vec2;
    [[nodiscard]] template <Arithmetic D>
    constexpr auto move_toward(const vec2 other, const D delta) const noexcept -> vec2;
    [[nodiscard]]
    constexpr auto area() const noexcept -> A;
    [[nodiscard]]
    constexpr auto aspect() const noexcept -> float;
    [[nodiscard]]
    constexpr auto sum() const noexcept -> A;
    [[nodiscard]]
    constexpr auto product() const noexcept -> A;
    [[nodiscard]]
    constexpr auto is_zero() const noexcept -> bool;
    [[nodiscard]]
    constexpr auto is_normalized() const noexcept -> bool;
    [[nodiscard]]
    constexpr auto min_component() const noexcept -> A;
    [[nodiscard]]
    constexpr auto max_component() const noexcept -> A;

    template <typename T>
    constexpr static auto from_angle(const T angle) noexcept -> vec2
        requires std::floating_point<T>;

    template <typename L, Arithmetic R>
    constexpr static auto from_polar(const L length, const R angle) noexcept -> vec2
        requires std::floating_point<R>;
};




export using vec2i = vec2<int>;
export using vec2s = vec2<int>;
export using vec2u = vec2<unsigned>;
export using vec2f = vec2<float>;
export using vec2d = vec2<double>;


} // xvt
