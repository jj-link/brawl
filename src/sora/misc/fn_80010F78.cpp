#include <types.h>
#pragma force_active on

extern "C" int fn_80041D64(void*, void*);

struct Class_804207E4_base { char pad[0x44]; };
class Class_804207E4 : public Class_804207E4_base {
public:
    virtual int fn_80011148(Class_804207E4*);  // offset 0x8
    virtual void fn_80011170();                // offset 0xc
    virtual void fn_80011150(Class_804207E4*); // offset 0x10
};

extern "C" void fn_80010F78(Class_804207E4* self, Class_804207E4* other) {
    int var_r29;
    int var_r28;

    if (*(u32*)((char*)self + 0x14) != *(u32*)((char*)other + 0x14)) {
        var_r29 = ((1 << *(u8*)((char*)other + 0x1D)) & *(u32*)((char*)self + 0x8)) != 0;
        var_r28 = ((1 << *(u8*)((char*)self + 0x1D)) & *(u32*)((char*)other + 0x8)) != 0;
    } else {
        var_r29 = ((1 << *(u8*)((char*)other + 0x1D)) & *(u32*)((char*)self + 0xC)) != 0;
        var_r28 = ((1 << *(u8*)((char*)self + 0x1D)) & *(u32*)((char*)other + 0xC)) != 0;
    }
    if ((var_r29 || var_r28) && fn_80041D64((char*)self + 0x2C, (char*)other + 0x2C) && self->fn_80011148(other)) {
        if (var_r29) {
            self->fn_80011150(other);
        }
        if (var_r28) {
            other->fn_80011150(self);
        }
    }
}