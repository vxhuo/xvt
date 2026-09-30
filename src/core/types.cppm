module;

#include <concepts>

export module xvt.types;


namespace xvt
{

export template <typename T>
concept Arithmetic = std::arithmetic_v<T>;


} // xvt
