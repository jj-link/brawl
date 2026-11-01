#include <nw4r/math/math_types.h>
#include <types.h>

#pragma force_active on

struct Block48 {
    u32 w[12];
};

struct FTElement {
    u32 pad[13];
    nw4r::math::VEC3 pos;
    nw4r::math::VEC3 normal;
    u32 pad2[36];
    Block48 data;
};

extern "C" void fn_801EC868(void* pIn, void* pOut, f32 x, f32 y, f32 z);

extern "C" void fn_800831AC(s32 unused, s32 i, s32 j, FTElement*** pArr) {
    s32 oj = j << 2;
    s32 oi = i << 2;
    nw4r::math::VEC3 posI, posJ;
    Block48 buf;

    s32 off;
    s32 k = 1;

    posI.x = (*pArr)[i]->pos.x;
    posI.y = (*pArr)[i]->pos.y;
    posI.z = (*pArr)[i]->pos.z;
    posJ.x = (*pArr)[j]->pos.x;
    posJ.y = (*pArr)[j]->pos.y;
    posJ.z = (*pArr)[j]->pos.z;

    nw4r::math::VEC3 diff;
    diff = posJ - posI;

    off = 4;
    do {
        FTElement* src = *reinterpret_cast<FTElement**>(
            reinterpret_cast<u8*>(*pArr) + oi + off);
        fn_801EC868(&src->data, &buf, diff.x, diff.y, diff.z);

        FTElement* dst = *reinterpret_cast<FTElement**>(
            reinterpret_cast<u8*>(*pArr) + oj + off);
        dst->data = buf;

        (*reinterpret_cast<FTElement**>(
            reinterpret_cast<u8*>(oj + reinterpret_cast<u32>(*pArr)) + off))->pos =
            (*reinterpret_cast<FTElement**>(
                reinterpret_cast<u8*>(*pArr) + oi + off))->pos + diff;
        (*reinterpret_cast<FTElement**>(
            reinterpret_cast<u8*>(oj + reinterpret_cast<u32>(*pArr)) + off))->normal =
            (*reinterpret_cast<FTElement**>(
                reinterpret_cast<u8*>(*pArr) + oi + off))->normal + diff;
        ++k;
        off += 4;
    } while (k < 3);
}
