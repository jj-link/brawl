#include <types.h>
#pragma force_active on

struct fn27Pad {
    u32 unk0;
    u32 unk4;
};

struct fn27Ob : public fn27Pad {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33(void* self, void* a, void* b);
};

struct fn27Wrap {
    u8 pad[0x8d0];
    fn27Ob* m_obj;
};

extern "C" {
void fn_27_28874C(fn27Wrap* self, void* a, void* b) {
    self->m_obj->v33(self, a, b);
}
}
