#include <stdio.h>
#include <nw4r/math/math_types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <mu/mu_msg.h>
#include <ty/ty_fig_listmng.h>
#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on
extern "C" {
void* fn_8018D3F0(void*, const char*);
void fn_800B6E08(void*, const nw4r::math::VEC3*);
void fn_800B7224(void*, unsigned int, const char*, void*);
void fn_8019D950(void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_8045BF8C[];
extern char lbl_8045BFA4[];
extern char lbl_8059E468[6];
extern char lbl_8059E470[4];
}
extern "C" void fn_800F9D8C(void* self, unsigned int index, unsigned int id, int enabled) {
    char* p = (char*)self;
    char* entry = p + index * 0x18;
    if (enabled) {
        tyFigListData* record = (*(tyFigListDataManager**)(p + 0x39c))->getFigDataId(id);
        (*(MuMsg**)(p + 0x334))->printIndex(index, *(unsigned int*)((char*)record + 0x14), 0);
        int bilTexIdx = record->bilTexIdx;
        unsigned int texIndex = bilTexIdx / 10;
        if (texIndex < 64) {
            void* resource = *(void**)(p + 0x14c + texIndex * 4);
            if (resource) {
                char name[64];
                sprintf(name, lbl_8045BF8C, bilTexIdx);
                char* tex = (char*)fn_8018D3F0(&resource, name);
                if (tex) {
                    nw4r::math::VEC3 scaled;
                    nw4r::math::VEC3 input((float)*(unsigned short*)(tex + 0x1c), (float)*(unsigned short*)(tex + 0x1e), 10.0f);
                    LocalScale((const Vec*)&input, (Vec*)&scaled, 0.1f);
                    fn_800B6E08(*(void**)(entry + 0x27c), &scaled);
                    char* model = *(char**)(entry + 0x27c);
                    nw4r::g3d::ResMat mat = ((nw4r::g3d::ResMdl*)(model + 8))->GetResMat(lbl_8045BFA4);
                    fn_800B7224(model, mat->m_id, name, &resource);
                    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(entry + 0x288), *(void**)(*(char**)(entry + 0x27c) + 0x10), lbl_8059E468);
                    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(entry + 0x288), *(void**)(*(char**)(entry + 0x278) + 0x10), lbl_8059E468);
                }
            }
        }
    } else {
        fn_8019D950(*(void**)(*(char**)(entry + 0x27c) + 0x10));
        fn_8019D950(*(void**)(*(char**)(entry + 0x278) + 0x10));
        (*(MuMsg**)(p + 0x334))->printf(index, lbl_8059E470);
    }
}