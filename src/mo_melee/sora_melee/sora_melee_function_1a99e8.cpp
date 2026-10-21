#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int),
                              unsigned long, unsigned long);
extern "C" char lbl_27_data_26050[];
extern "C" void* getInstance__13soEventSystemFv();

struct EventManager {
    virtual void unused();
    virtual void remove(s32);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, s32);

class soStatusEventObserver;

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    void* m_vptr;
    s16 m_id;
    s16 m_arg;
    u8 m_pad[0x28 - 8];
    u8 m_work[12 * N];

    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if ((u8*)this + 0xC != 0 && (u8*)this + 0x1C != 0) {
        __destroy_arr((u8*)this + 0x28, fn_27_84398, 0xC, N);
    }

    if (this != 0 && this != 0) {
        s16 id = m_id;
        m_vptr = lbl_27_data_26050;
        if (id != -1) {
            getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), m_id
            )->remove(m_arg);
        }
    }
}

template class soEventUnitWithWorkArea<soStatusEventObserver, 32>;
