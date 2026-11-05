#include <snd/snd_system.h>
#pragma force_active on

struct Obj {
    char pad[0x178];
    int id;
};
extern "C" int fn_8007923C(Obj*, int, int, int);
extern "C" int fn_80074018(sndSystem*, int, int);

extern "C" int fn_80079104(Obj* self, int arg1, int arg2, int arg3) {
    if ((unsigned int)(arg2 + 0x10000) != 0xffff) {
        if (arg3 == 0) {
            int result = fn_8007923C(self, arg1, arg2, 0);
            if (result == -1)
                return -1;
            self->id = result;
        } else {
            self->id = arg3;
            fn_8007923C(self, arg1, arg2, arg3);
        }
    } else if (arg1 == 0x16) {
        if ((unsigned int)self->id >= 0x27a9 && (unsigned int)self->id <= 0x27b2)
            self->id = 0x27a1;
    }
    if (self->id == 0)
        return -1;
    if (fn_80074018(g_sndSystem, self->id, 1))
        return self->id;
    return -1;
}