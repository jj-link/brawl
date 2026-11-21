#include <types.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_9C0;
extern "C" const float lbl_27_rodata_9C4;

struct Inner {
    s32 kind;
    s32 field4;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Inner* slot2();

    u8 padding[12];
    soModuleAccesser* accesser;
    u8 flag;
};

extern "C" float fn_27_736B8(Object_vptr_0* self) {
    union {
        u8 workspace[24];
        s32 words[6];
    };
    Inner* data = self->slot2();

    *(Inner**)workspace = data;
    workspace[4] = 0;
    u32 copiedFlag = *(u32*)(workspace + 4);
    *(Inner**)(workspace + 8) = data;
    *(u32*)(workspace + 12) = copiedFlag;
    *(Inner**)(workspace + 16) = data;
    workspace[20] = workspace[12];

    if ((workspace[12] == 1 ? -1 : (*(Inner**)(workspace + 16))->kind) == 1) {
        if (workspace[20] == 1) {
            return lbl_27_rodata_9C0;
        }
        return (float)(*(Inner**)(workspace + 16))->field4 / lbl_27_rodata_9C4;
    }
    u8 nf = workspace[20];
    if ((nf == 1 ? -1 : (*(Inner**)(workspace + 16))->kind) == 5) {
        Inner* arg;
        if (nf == 1) {
            arg = 0;
        } else {
            arg = (Inner*)(*(Inner**)(workspace + 16))->field4;
        }
        return soValueAccesser::getValueFloat(self->accesser, (u32)arg, 0);
    }
    self->flag = 1;
    return lbl_27_rodata_9C0;
}