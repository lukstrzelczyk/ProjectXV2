#include "Wepon.h"

std::ostream& operator<<(std::ostream& out, const Wepon& S)
{
    S.printoperator(out);
    return out;
}
