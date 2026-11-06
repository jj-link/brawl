#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" const float lbl_54_rodata_8C;

struct Entry { float x, y, z; };
inline void copyEntry(Entry* dst, const Entry* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

extern "C" void fn_54_3EB4(void* self) {
    u8* p = (u8*)self;
    u8* base = p + 0xd0;
    if (base != 0) {
        nw4r::g3d::ScnMdlSimple* model = *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(p + 0x44));
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(u32*)(base + 0xc) = 0;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)base;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (u16)**(u32**)(base + 4);
            }
            Entry* entries = *(Entry**)(p + 0x15c);
            if (entries != 0) {
                copyEntry((Entry*)(*(u8**)(base + 4) + 8), &entries[**(u8**)(p + 0x160)]);
            }
            float y = *(float*)(p + 0x16c);
            Entry* scale = (Entry*)(*(u8**)(base + 4) + 0x20);
            scale->x = lbl_54_rodata_8C;
            scale->y = y;
            scale->z = lbl_54_rodata_8C;
        }
    }
}
