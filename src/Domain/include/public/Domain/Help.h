#pragma once

#include <string>
#include <vector>

namespace Domain
{
template <typename T> using vector_ptr = std::shared_ptr<std::vector<T>>;
}