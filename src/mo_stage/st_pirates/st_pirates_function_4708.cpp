#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

#pragma force_active on

struct Blk48 {
    u32 w[12];
};

extern "C" void fn_52_4708(void* self) {
    u8* p = (u8*)self;
    u8* base = p + 0xd0;
    if (base != 0) {
        nw4r::g3d::ScnMdlSimple* model =
            *(nw4r::g3d::ScnMdlSimple**)(*(u8**)(p + 0x44));
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(u32*)(base + 0xc) = 0;
                model->m_calcWorldCallBack =
                    (nw4r::g3d::ICalcWorldCallBack*)base;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (u16)**(u32**)(base + 4);
            }
            Blk48* src = *(Blk48**)(p + 0x164);
            if (src != 0) {
                *(Blk48*)(*(u8**)(base + 4) + 0x50) = *src;
            }
        }
    }
}
