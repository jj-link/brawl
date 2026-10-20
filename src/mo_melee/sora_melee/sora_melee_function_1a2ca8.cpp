#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <class T, int N>
class soArrayVector
{
public:
    void offFull();
};

template <>
void soArrayVector<wnPikminPikmin *, 10>::offFull()
{
    *reinterpret_cast<u32 *>(reinterpret_cast<char *>(this) + 8) &= 0xFFFEFFFF;
}
