#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
};

class soModelModuleImpl {
public:
    char pad0[0xC];
    Object_vptr_0* m_C;
    char pad10[0xB3];
    unsigned char m_C3;

    void deactivate();
};

void soModelModuleImpl::deactivate() {
    if (m_C3 != 3) {
        if (m_C != 0) {
            m_C->slot6(1, 1);
            m_C->slot6(2, 1);
            m_C->slot6(3, 1);
            m_C->slot6(4, 1);
            m_C->slot6(5, 1);
            m_C->slot6(6, 1);
            m_C->slot6(7, 1);
            m_C->slot6(8, 1);
        }
    }
}
