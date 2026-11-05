#include <types.h>
#pragma force_active on

extern "C" void fn_80163DC8(void* a, void* b);
extern "C" void fn_80164DB8(void* self);
extern "C" void fn_80164FD8(void* self);
extern "C" u16 fn_8016F198(void* a, void* b, u16 c);

struct Obj {
    char pad0[0xC];
    s32 unkC;
    char pad1[0x20 - 0x10];
    u32 unk20;
    char pad2[0xBC - 0x24];
    void* unkBC;
    char pad3[0xF0 - 0xC0];
    s32 unkF0;
    Obj* unkF4;
};

extern "C" void fn_80164E48(Obj* self) {
    Obj* buf[1024];
    u16 count;
    u16 i;
    Obj* node;
    Obj* cur;

    if (self->unkF0 != 0) {
        self->unkF0 = 0;
    }
    if (self->unk20 & 1) {
        fn_80164DB8(self);
    }
    fn_80164FD8(self);
    if (self->unk20 & 1) {
        char* bc = (char*)self->unkBC;
        count = fn_8016F198(bc + 0x24, buf, *(u16*)(bc + 0x2C));
        for (i = 0; i < count; i++) {
            node = buf[i];
            cur = node->unkF4;
            while (cur != 0) {
                if (cur == self) {
                    fn_80164DB8(node);
                    if (node->unkC == 1) {
                        fn_80163DC8(self->unkBC, node);
                    }
                    break;
                }
                cur = cur->unkF4;
            }
        }
    }
}
