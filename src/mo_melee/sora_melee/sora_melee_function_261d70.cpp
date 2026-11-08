#include <gr/ground.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmat.h>
#pragma force_active on
typedef unsigned char u8;
extern "C" {
u32 fn_8018F394(void*);
void fn_801915B8(void*, u32, GXColor);
void fn_80190A3C(void*, bool);
}
extern "C" void renderPre__6GroundFv(Ground* self)
{
    u8 flags = ((u8*)self)[0x6D];
    if (((flags >> 2) & 1) && ((flags >> 1) & 1) && self->m_sceneModels) {
        u32 count;
        u32 i = 0;
        u32 offset = 0;
        GXColor color;
        color.r = ((u8*)self)[0x98];
        color.g = ((u8*)self)[0x99];
        color.b = ((u8*)self)[0x9A];
        color.a = ((u8*)self)[0x9B];
        GXColor alphaColor;
        alphaColor.a = color.a;
        alphaColor.b = color.a;
        alphaColor.g = color.a;
        alphaColor.r = color.a;
        count = self->m_modelAnimNum;
        for (; i != count; ++i) {
            nw4r::g3d::ScnMdl* model = self->m_sceneModels[i];
            void* resource = model->m_resMdl.ptr();
            u32 materialCount = fn_8018F394(&resource);
            for (u32 j = 0; j < materialCount; ++j) {
                nw4r::g3d::ScnMdl::CopiedMatAccess access(model, j);
                nw4r::g3d::ResMatTevColor tev = access.GetResMatTevColor(false);
                tev.GXSetTevColor(3, color);
                fn_801915B8(&tev, 0, alphaColor);
                fn_80190A3C(&tev, false);
            }
            offset += 4;
        }
    }
}