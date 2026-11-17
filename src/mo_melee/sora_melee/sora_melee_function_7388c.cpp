#include <types.h>
#pragma force_active on

struct Inner {
    s32 kind;
    s32 field4;
};

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Inner* slot2();

    u8 padding[0x10];
    u8 flag;
};

extern "C" s32 fn_27_7388C(Obj* self) {
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

    if ((workspace[12] == 1 ? -1 : (*(Inner**)(workspace + 16))->kind) == 5) {
        if (workspace[20] == 1) {
            return 0;
        }
        return (*(Inner**)(workspace + 16))->field4;
    }
    self->flag = 1;
    return 0;
}
