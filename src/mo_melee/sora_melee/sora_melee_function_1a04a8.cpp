#pragma force_active on
#define soArrayVector soArrayVectorHeader
#include <ac/ac_cmd_interpreter.h>
#undef soArrayVector

template <class T, int C>
class soArrayVector {
    void* m_vt0;
    void* m_vt1;
    s32 m_topIndex : 2;
    s32 m_lastIndex : 2;
    s32 m_size : 2;
    u32 m_isFull : 1;
    T m_elements[C];
    static unsigned char __vt[];

public:
    soArrayVector();
};

template <>
soArrayVector<acCmdInterpreterStackData, 1>::soArrayVector()
    : m_vt0(__vt), m_vt1(__vt + 0x48), m_topIndex(0), m_lastIndex(0), m_size(0), m_isFull(false) {
}
