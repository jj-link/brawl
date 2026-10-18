#include <types.h>
#pragma force_active on

extern "C" void fn_41_2360(void* self, s32 v);
extern "C" char lbl_41_data_7F8[];

extern "C" void* fn_41_2410(void* self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    u32* p = (u32*)self;
    fn_41_2360(self, 0);
    char* data = lbl_41_data_7F8;
    p[2] = (u32)data;
    p[0] = (u32)(data + 8);
    p[3] = a;
    p[4] = b;
    p[5] = c;
    p[6] = d;
    p[7] = e;
    p[8] = f;
    return self;
}
