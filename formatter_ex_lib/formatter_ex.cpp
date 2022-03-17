#include "../formatter_lib/formatter.h"

#include "formatter_ex.h"

std::ostream& formatter(std::ostream& out, const std::string& message)
{
    return out << formatter(message);
}
