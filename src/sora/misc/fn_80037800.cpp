#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
extern "C" {
char* strcat(char*, const char*);
extern int lbl_80406910[];
extern char lbl_804231E0[];
}
struct Path { char s[65]; };
extern Path lbl_804953D0;
struct Obj {
    char pad0[0x20]; int f20; char pad24[8]; int state;
    char pad30[12]; int f3C; char pad40[12]; MEMAllocator* f4C;
    char pad50[0x48]; void* f98; char pad9C[0x10]; gfFileIOHandle io;
};
static inline char* validate(int& state) {
    unsigned int i;
    char* base = lbl_804231E0;
    char* suffix;
    int* table = lbl_80406910;
    int list[3] = { *table++, *table++, *table };
    for (i = 0; i < 3; ++i) {
        if (state == list[i]) break;
    }
    if (i >= 3) state = list[0];
    suffix = NULL;
    switch (state) {
    case 0: suffix = base + 0x30; break;
    case 1: suffix = base + 0x40; break;
    case 2: suffix = base + 0x50; break;
    case 3: suffix = base + 0x60; break;
    case 4: suffix = base + 0x70; break;
    case 5: suffix = base + 0x80; break;
    case 6: suffix = base + 0x90; break;
    }
    return suffix;
}
extern "C" void fn_80037800(Obj* self) {
    Path b;
    Path a;
    char* suffix = validate(self->state);
    a = lbl_804953D0;
    strcat(a.s, suffix);
    b = a;
    self->io.readRequestNoSync(b.s, (Heaps::HeapType)6, 0, 0);
    self->f20 = 0;
    self->f3C = 0;
    self->f4C = gfHeapManager::getMEMAllocator((Heaps::HeapType)6);
    if (self->f98 == NULL) {
        self->f98 = gfHeapManager::alloc((Heaps::HeapType)6, 0x1D000);
    }
}