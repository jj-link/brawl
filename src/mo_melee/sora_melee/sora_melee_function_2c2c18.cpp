#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static void* getManager(u32 index);
};

extern "C" int fn_80045DC0(void* mgr, void* arg, u32 flag);

struct fn_27_2C2C18_Obj {
    u32 unk0;
    void* unk4;
};

extern "C" {
bool fn_27_2C2C18(fn_27_2C2C18_Obj* self) {
    void* mgr = soArchiveDb::getManager(2);
    return fn_80045DC0(mgr, self->unk4, 0) != 0;
}
}
