#include <gf/gf_pad_system.h>
#pragma force_active on
extern "C" const float lbl_25_rodata_20;
extern "C" const float lbl_25_rodata_24;
struct Layout { float x, y, z, w; void* ptr; };
struct Object {
    char pad[0x4c];
    char flag0;
    unsigned char flag;
    char pad2[2];
    float time, duration;
    float x0, y0, z0, w0;
    float unused;
    float x1, y1, z1, w1;
    float unused2;
    float x, y, z, w;
    char pad3[8];
    float outx, outy, outz, outw;
    char pad4[4];
    int state, counter;
};
extern "C" void fn_25_10D4(Layout*, void*);
extern "C" void fn_25_14C4(Object*, float, float, float, float);
extern "C" void fn_25_F98(Object* self) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xf0, &status);
    switch (self->state) {
    case 0: break;
    case 1:
        if (self->flag) {
            float duration = self->duration;
            float t = self->time + lbl_25_rodata_20;
            float ratio = t / duration;
            self->time = t;
            self->x = self->x0 + ratio * (self->x1 - self->x0);
            self->y = self->y0 + ratio * (self->y1 - self->y0);
            self->z = self->z0 + ratio * (self->z1 - self->z0);
            self->w = self->w0 + ratio * (self->w1 - self->w0);
            if (duration <= t) {
                self->flag = 0;
                self->time = lbl_25_rodata_24;
            }
        }
        Layout result;
        fn_25_10D4(&result, &self->flag0);
        fn_25_14C4(self, self->outx = result.x, self->outy = result.y, self->outz = result.z, self->outw = result.w);
        ++self->counter;
        break;
    case 2: break;
    }
}