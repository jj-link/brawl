#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
f32 fn_5_42FC(void*, u32, s32, f32);
void fn_5_49A4(void*, s32);
void fn_800B6838(void*, f32*);
void fn_800B672C(void*, f32*, char*);
void fn_800B67E0(void*, f32*, char*, f32, f32);
extern const f32 lbl_5_rodata_0[];
extern char lbl_5_data_0[];

inline f32 multiply(f32 a, f32 b) { return a * b; }

inline s32 getCount(char* p, u32 index) {
    if (*(u8*)(p + 0x600) != 0)
        return *(s32*)(p + index * 4 + 0x1c);
    return 0;
}

void fn_5_4080(void* arg0) {
    char* d = lbl_5_data_0;
    const f32* c = lbl_5_rodata_0;
    char* self = (char*)arg0;
    s32 r28;
    char* far;
    char* hi;
    char* p5 = *(char**)(self + 0xC4758);
    s32 r0;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28 = c[3];
    f32 buf[3];
    f32 v[3];
    f32 scale[3];

    r0 = getCount(p5, *(s32*)(self + 0x7D164));
    hi = self + 0x80000;
    *(s32*)(hi - 0x2e8c) = r0;

    if (*(s32*)(hi - 0x2e9c) == 3) {
        f29 = c[6];
        f30 = c[3];
        f31 = c[7];
        char* r25 = self;
        s32 r24 = 0;
        u32 r23 = 0;
        r28 = 0;
        far = self + 0xc0000;
        do {
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                *(void**)(hi + 0x7D684 - 0x80000),
                *(void**)(*(char**)(r25 + 0x7D640) + 0xC),
                d + 0x258);
            buf[0] = f29;
            buf[1] = f28;
            buf[2] = f30;
            fn_800B6838(*(void**)(r25 + 0x7D640), buf);
            f28 -= f31;
            f28 = fn_5_42FC(self, r23, r24, f28) - f31;
            p5 = *(char**)(far + 0x4758);
            if (*(u8*)(p5 + 0x600) != 0) {
                r0 = *(s32*)(p5 + r28 + 0x1c);
            } else {
                r0 = 0;
            }
            r23 += 1;
            r24 += r0;
            r25 += 4;
            r28 += 4;
        } while (r23 < 3);
    } else {
        f28 = fn_5_42FC(self, *(s32*)(self + 0x7D164), 0, c[3]);
    }

    fn_5_49A4(self, 0);
    *(f32*)(self + 0x7D51C) = -f28;
    fn_800B672C(*(void**)(self + 0x7D5AC), v, d + 0x498);
    f32 t = *(f32*)(self + 0x7D51C) - v[1];
    *(f32*)(self + 0x7D51C) = t;

    if (t > *(f32*)(self + 0x7D518)) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)(self + 0x7D680),
            *(void**)(*(char**)(self + 0x7D64C) + 0xC),
            d + 0x258);
        f32 a = c[11] * *(f32*)(self + 0x7D518);
        f32 q = a / *(f32*)(self + 0x7D51C);
        scale[0] = c[3];
        scale[1] = -q;
        scale[2] = c[3];
        fn_800B67E0(*(void**)(self + 0x7D64C), scale, d + 0x260, q, a);
        f32 b = multiply(c[11], *(f32*)(self + 0x7D500));
        f32 q2 = b / *(f32*)(self + 0x7D51C);
        scale[0] = c[3];
        scale[1] = -q2;
        scale[2] = c[3];
        fn_800B67E0(*(void**)(self + 0x7D64C), scale, d + 0x268, q2, b);
        return;
    }
    nw4r::g3d::ScnGroup* obj = *(nw4r::g3d::ScnGroup**)(self + 0x7D680);
    nw4r::g3d::ScnObj* arg = *(nw4r::g3d::ScnObj**)(*(char**)(self + 0x7D64C) + 0xC);
    obj->Remove(arg);
}
}
