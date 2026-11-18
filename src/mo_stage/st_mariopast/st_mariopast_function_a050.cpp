#include <types.h>
#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXHardware.h>

#pragma force_active on

extern "C" float lbl_48_rodata_48[];

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Elem {
    Vec3 pos;
    u8 pad0[0x1c - sizeof(Vec3)];
    u8 state;
    u8 subflag;
    u8 pad1[0x30 - 0x1e];
    float dx;
    float dy;
    u8 pad2[0x40 - 0x38];
};

extern "C" void fn_48_A050(s32 count, Elem* base, u16* idx, s32 flag) {
    float* k = lbl_48_rodata_48;
    float pz;
    float py;
    float px;
    const float h = k[23];
    u16* p = idx;
    s32 i;
    for (i = 0; i < count; i++) {
        Elem* e = base + *p;
        Vec3 pv = e->pos;
        if ((u8)(e->state + 0xFE) <= 2) {
            pv.x += e->dx;
            pv.y += e->dy;
        }
        s32 sel = 0;
        if (flag != 0) {
            s32 sf = e->subflag;
            switch (e->state) {
            case 2:
            case 3:
            case 4:
            case 5:
                if (sf == 0) {
                    sel = 1;
                    break;
                }
            default:
                sel = 0;
                break;
            }
        }
        px = pv.x;
        py = pv.y;
        pz = pv.z;
        float f27;
        float f26;
        if (sel) {
            f27 = k[0];
        } else {
            f27 = k[12];
        }
        if (sel) {
            f26 = k[12];
        } else {
            f26 = k[13];
        }

        {
            float t1;
            float t2;
            float t3;
            float t4;
            float t5;
            GXBegin((GXPrimitive)0x98, (GXVtxFmt)1, 4);
            t5 = px - h;
            t4 = py + h;
            t3 = pz - h;
            WGPIPE.f = t5;
            t2 = px + h;
            t1 = pz + h;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = k[0];
            WGPIPE.f = t2;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = k[0];
            WGPIPE.f = t5;
            WGPIPE.f = t4;
            WGPIPE.f = t1;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = k[12];
            WGPIPE.f = t2;
            WGPIPE.f = t4;
            WGPIPE.f = t1;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = k[12];
        }

        {
            float t1;
            float t2;
            float t3;
            float t4;
            float t5;
            GXBegin((GXPrimitive)0x98, (GXVtxFmt)1, 4);
            t5 = px - h;
            t4 = py - h;
            t3 = pz + h;
            WGPIPE.f = t5;
            t2 = px + h;
            t1 = pz - h;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = k[0];
            WGPIPE.f = t2;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = k[0];
            WGPIPE.f = t5;
            WGPIPE.f = t4;
            WGPIPE.f = t1;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = k[12];
            WGPIPE.f = t2;
            WGPIPE.f = t4;
            WGPIPE.f = t1;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = k[12];
        }

        {
            float t1;
            float t2;
            float t3;
            float t4;
            float t5;
            GXBegin((GXPrimitive)0x98, (GXVtxFmt)1, 4);
            t5 = px - h;
            t4 = py + h;
            t3 = pz + h;
            WGPIPE.f = t5;
            t2 = px + h;
            t1 = py - h;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f27;
            WGPIPE.f = t2;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f27;
            WGPIPE.f = t5;
            WGPIPE.f = t1;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f26;
            WGPIPE.f = t2;
            WGPIPE.f = t1;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f26;
        }

        {
            float t1;
            float t2;
            float t3;
            float t4;
            float t5;
            GXBegin((GXPrimitive)0x98, (GXVtxFmt)1, 4);
            t5 = px - h;
            t4 = py - h;
            t3 = pz + h;
            WGPIPE.f = t5;
            t2 = pz - h;
            t1 = py + h;
            WGPIPE.f = t4;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f26;
            WGPIPE.f = t5;
            WGPIPE.f = t4;
            WGPIPE.f = t2;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f26;
            WGPIPE.f = t5;
            WGPIPE.f = t1;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f27;
            WGPIPE.f = t5;
            WGPIPE.f = t1;
            WGPIPE.f = t2;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f27;
        }

        {
            float t1;
            float t2;
            float t3;
            float t4;
            float t5;
            GXBegin((GXPrimitive)0x98, (GXVtxFmt)1, 4);
            t5 = px + h;
            t4 = py + h;
            t3 = pz + h;
            WGPIPE.f = t5;
            t2 = pz - h;
            WGPIPE.f = t4;
            t1 = py - h;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f27;
            WGPIPE.f = t5;
            WGPIPE.f = t4;
            WGPIPE.f = t2;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f27;
            WGPIPE.f = t5;
            WGPIPE.f = t1;
            WGPIPE.f = t3;
            WGPIPE.i = -1;
            WGPIPE.f = k[0];
            WGPIPE.f = f26;
            WGPIPE.f = t5;
            WGPIPE.f = t1;
            WGPIPE.f = t2;
            WGPIPE.i = -1;
            WGPIPE.f = k[13];
            WGPIPE.f = f26;
        }

        p++;
    }
}
