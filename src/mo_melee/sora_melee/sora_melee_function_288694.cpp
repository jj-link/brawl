#include <types.h>
#pragma force_active on

struct ftHeader8 {
    u32 unk0;
    u32 unk4;
};

class ftSubObj : public ftHeader8 {
public:
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
    virtual u32 vf25(void* a, u32 b, u32 c, u32 d, u32 e);
};

class ftOwner {
public:
    u8 pad[0x8d0];
    ftSubObj* m_8d0;
};

extern "C" {
u32 fn_27_288694(ftOwner* self, u32 a, u32 b, u32 c, u32 d) {
    return self->m_8d0->vf25(self, a, b, c, d);
}
}
