#include <gf/gf_application.h>
#pragma force_active on
extern "C" double fn_804005AC(double);
struct Data { unsigned char pad[12]; unsigned char flags; };
struct Obj {
    unsigned char pad0[0x44]; Data* data;
    unsigned char pad48[0x75-0x48]; unsigned char pause;
    unsigned char pad76[0xd7-0x76]; unsigned char countExtra;
    unsigned char padD8[7]; unsigned char enabled;
    unsigned int remaining, elapsed, extra;
    float fraction;
    unsigned char padF0[4]; float rate;
};
extern "C" void fn_27_24A1F0(Obj* self) {
    if ((!self->pause || !((*(unsigned int*)((char*)g_gfApplication + 0xec) >> 27) & 4)) &&
        self->enabled && ((self->data->flags & 1) || (*(unsigned int*)((char*)g_gfApplication + 0xec) >> 27) == 0)) {
        self->fraction += self->rate;
        float whole = (float)fn_804005AC(self->fraction);
        self->fraction -= whole;
        int delta = (int)whole;
        if (delta != 0) {
            if (self->remaining > (unsigned int)delta) self->remaining -= delta;
            else self->remaining = 0;
            self->elapsed += delta;
            self->elapsed = self->elapsed < 0x14996ffU ? self->elapsed : 0x14996ffU;
            if (self->countExtra) {
                self->extra += delta;
                self->extra = self->extra < 0x14996ffU ? self->extra : 0x14996ffU;
            }
        }
    }
}