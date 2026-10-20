#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct acCmdInterpreterStackData;

template <class T, int N>
class soArrayVector {
public:
    s32 getLastIndex() const;
    u32 m_unk0;
    u32 m_unk4;
    u32 m_last;
};

template <class T, int N>
s32 soArrayVector<T, N>::getLastIndex() const {
    return (s32)((m_last << 2 | m_last >> 30) & 0xE0000000) >> 30;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
