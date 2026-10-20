#include <types.h>
#pragma force_active on

class soStopTarget {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v26(void* p);
};

class soStopModuleImpl {
public:
    virtual void dummy();
    u8 m_pad[0x14 - 4];
    s32 m_14;
    s32 m_18;
    u8 m_1c;
    void* m_20;
    void setOtherStop(u32 p);
};

void soStopModuleImpl::setOtherStop(u32 p) {
    if ((s32)p <= 0) {
        return;
    }
    if ((s32)p <= m_18) {
        return;
    }
    m_1c |= 0x10;
    m_18 = p;
    if (m_14 > (s32)p) {
        m_18 = m_14;
    }
    m_14 = 0;
    if ((m_1c >> 7) & 1) {
        return;
    }
    m_1c |= 0x80;
    u8* obj = (u8*)m_20;
    u8* a = *(u8**)(obj + 0xd8);
    soStopTarget* b = *(soStopTarget**)(a + 0x54);
    b->v26(obj);
}
