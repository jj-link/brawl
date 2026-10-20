#pragma force_active on
typedef unsigned int u32;

template <class T, int N>
class soArrayVector {
public:
    unsigned char pad[8];
    u32 flags;
    void onFull();
};

class wnPikminPikmin;

template <>
void soArrayVector<wnPikminPikmin *, 10>::onFull()
{
    flags |= 0x10000;
}
