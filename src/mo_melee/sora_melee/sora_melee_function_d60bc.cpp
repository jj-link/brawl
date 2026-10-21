#include <types.h>
#pragma force_active on

extern "C" void fn_27_84518(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int),
                              unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void* self, long id);
extern char lbl_27_data_26078[];

class soDamageEventObserver;

class soFakeEventManager {
public:
    virtual void slot0();
    virtual void slot1(s16 id);
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    void* m_vt;
    s16 m_id0;
    s16 m_id1;
    u8 m_pad[0x28 - 0x8];

    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if ((u8*)this + 0xc != 0) {
        if ((u8*)this + 0x1c != 0) {
            __destroy_arr((u8*)this + 0x28, fn_27_84518, 0xc, 4);
        }
    }

    if (this != 0) {
        if (this != 0) {
            s16 id = m_id0;
            m_vt = lbl_27_data_26078;
            if (id != -1) {
                soFakeEventManager* mgr =
                    (soFakeEventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), m_id0);
                mgr->slot1(m_id1);
            }
        }
    }
}

template class soEventUnitWithWorkArea<soDamageEventObserver, 4>;
