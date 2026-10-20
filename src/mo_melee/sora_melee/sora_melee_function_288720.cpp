#include <types.h>
#pragma force_active on

class soSubObjBase {
public:
    u32 unk0;
    u32 unk4;
};

class soSubObj : public soSubObjBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual u32 vf36(void* self, u32 a, u32 b);
};

class soOwner {
public:
    u8 m_pad[0x8d0];
    soSubObj* m_obj;
};

extern "C" {
u32 fn_27_288720(soOwner* self, u32 a, u32 b) {
    return self->m_obj->vf36(self, a, b);
}
}
