module;

#include <concepts>

export module xvt.types;


namespace xvt
{

export template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;


export template <Arithmetic T>
using FT = std::conditional_t<std::is_floating_point_v<T>, T, float>;


} // xvt
