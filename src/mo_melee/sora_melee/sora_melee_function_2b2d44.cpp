#include <types.h>
#pragma force_active on

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
    void*, u32, const char*, u16, u32, u32);

extern const char lbl_27_rodata_5E88[];

struct Object {
    u32 pad[3];
    u32 id;
};

extern "C" void* fn_27_2B2D44(const Object* const self, const s32 index) {
    u32 id = self->id;
    if (id == 0xffff) {
        return 0;
    }

    char* base = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
        getManager__11soArchiveDbFUl(2), id, lbl_27_rodata_5E88, 0, 0, -1);

    if (base == 0) {
        return 0;
    }
    if (index < 0 || index >= 5) {
        return 0;
    }

    return *(void**)(base + (index << 3) + 4);
}
