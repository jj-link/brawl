#include <types.h>
#pragma force_active on
extern "C" void fn_801A81D4(void**);
extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801ECF4C(void*, f32, f32, f32, f32, f32, f32);
extern "C" void fn_801ECDC4(void*, f32, f32, f32, f32, f32, f32);
extern "C" void fn_801ECE60(void*, f32, f32, f32, f32);
extern "C" void fn_80162C04(void*, void*);
extern "C" void fn_801A7B70(void**, f32*, f32*, f32*, f32*, f32*, f32*);
extern "C" void fn_801F4F20(f32*, f32*, f32*, f32*, f32*, f32*, f32, f32, f32);
extern const f32 lbl_805A3368;
inline bool hasCachedMatrix(const char* p) { return (*(const unsigned long*)(p + 0x70) & 0x80) != 0; }
inline void getView(void** self, f32* view) {
    char* p = (char*)*self;
    if (p) {
        if (!(*(u32*)(p + 0x70) & 8)) fn_801A81D4(self);
        fn_801EC184(p, view);
    }
}
inline void getProj(void** self, f32* proj) {
    char* p = (char*)*self;
    if (p) {
        if (!hasCachedMatrix(p)) {
            if (*(u32*)(p + 0x70) & 0x40)
                fn_801ECF4C(p + 0x30, *(f32*)(p + 0xBC), *(f32*)(p + 0xC0), *(f32*)(p + 0xC4), *(f32*)(p + 0xC8), *(f32*)(p + 0xB4), *(f32*)(p + 0xB8));
            else if (*(u32*)(p + 0x70) & 0x10)
                fn_801ECDC4(p + 0x30, *(f32*)(p + 0xBC), *(f32*)(p + 0xC0), *(f32*)(p + 0xC4), *(f32*)(p + 0xC8), *(f32*)(p + 0xB4), *(f32*)(p + 0xB8));
            else
                fn_801ECE60(p + 0x30, *(f32*)(p + 0xAC), *(f32*)(p + 0xB0), *(f32*)(p + 0xB4), *(f32*)(p + 0xB8));
            *(u32*)(p + 0x70) |= 0x80;
        }
        fn_80162C04(proj, p + 0x30);
    }
}
extern "C" void fn_801A7BE0(void** self, f32* out, f32* in) {
    f32 view[12];
    f32 proj[16];
    f32 rect[6];
    f32 params[7];
    if (out) {
    getView(self, view);
    getProj(self, proj);
        f32 f = (f32)*(s32*)((char*)*self + 0xA8);
        params[0] = f;
        params[1] = proj[0];
        params[3] = proj[5];
        params[5] = proj[10];
        params[6] = proj[11];
        if (lbl_805A3368 == f) {
            params[2] = proj[3];
            params[4] = proj[7];
        } else {
            params[2] = proj[2];
            params[4] = proj[6];
        }
        fn_801A7B70(self, &rect[0], &rect[1], &rect[2], &rect[3], &rect[4], &rect[5]);
        fn_801F4F20(view, params, rect, out, out + 1, out + 2, in[0], in[1], in[2]);
    }
}