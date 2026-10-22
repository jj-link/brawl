#include <types.h>
#pragma force_active on

extern "C" void fn_8015CD80(void* a, void* b);
extern "C" int fn_801FAD94(void* a, void (*b)(void*, void*));

struct Fn8015D2A4Obj {
    u8 pad0[0x1c];
    void* m_1c;
    void* m_20;
    u8 m_24;
};

extern "C" bool fn_8015D2A4(Fn8015D2A4Obj* self, void* a, void* b) {
    self->m_1c = a;
    self->m_20 = b;
    int r = fn_801FAD94(&self->pad0[0x28], fn_8015CD80);
    if (r != 0) {
        self->m_24 = 1;
    }
    return r != 0;
}
