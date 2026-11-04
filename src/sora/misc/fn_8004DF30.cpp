#include <types.h>
#include <string.h>
#pragma force_active on

struct Obj {
    char pad[0x24];
    void* data;
};

extern "C" void fn_8004DF30(Obj* self) {
    for (int i = 0; i < 2; i++) {
        memset((char*)self->data + 0x32C + i * 0x264, 0, 0x264);
    }
    memset((char*)self->data + 0x34D4, 0, 0x74);
    memset((char*)self->data + 0x3548, 0, 0x44);
    for (int i = 0; i < 0x23; i++) {
        memset((char*)self->data + 0x16D0 + i * 0xE0, 0, 0x44);
    }
}
