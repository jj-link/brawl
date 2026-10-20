#pragma force_active on
typedef unsigned int u32;

class wnPikminPikmin;

struct FlagBits {
    u32 hi : 5;
    u32 idx : 5;
    u32 lo : 22;
};

template <typename T, int N>
class soArrayVector {
public:
    T* m_data;
    u32 m_count;
    FlagBits m_flags;
    void setLastIndex(long idx);
};

template <>
void soArrayVector<wnPikminPikmin*, 10>::setLastIndex(long idx)
{
    m_flags.idx = idx;
}
