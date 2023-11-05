//
// Created by Aardhyn Lavender on 2/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_CONCEPT_H
#define SDL3_TEMPLATE_PROJECT_CONCEPT_H

#include <concepts>

// TODO: Add support for other primitive types
template<typename T>
concept NumericPrimitive = std::same_as<T, int> || std::same_as<T, double> || std::same_as<T, float>;

template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

#endif //SDL3_TEMPLATE_PROJECT_CONCEPT_H
