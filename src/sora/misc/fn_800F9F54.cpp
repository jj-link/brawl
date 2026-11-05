#include <string.h>
#include <nw4r/math/math_types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <mu/mu_msg.h>
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
void* fn_800AE578(void*, unsigned int);
void* fn_8018D3F0(void*, const char*);
void fn_800B6E08(void*, const nw4r::math::VEC3*);
void fn_800B7224(void*, unsigned int, const char*, void*);
void fn_8019D950(void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_8045BFB8[];
extern char lbl_8059E468[6];
extern char lbl_8059E470[4];
}

extern "C" void fn_800F9F54(void* self, unsigned int index, unsigned int id, int enabled) {
    char* p = (char*)self;
    char* entry = p + index * 0x18;
    if (enabled) {
        void* db = *(void**)(p + 0x3a0);
        if (id <= *(unsigned int*)((char*)db + 0x2ef4)) {
            char* record = (char*)fn_800AE578(db, id);
            if (record) {
                char name[64];
                strcpy(name, *(char**)(record + 8));
                name[strlen(name) - 6] = 0;
                char* tex = (char*)fn_8018D3F0(p + 0x148, name);
                if (tex) {
                    nw4r::math::VEC3 scaled;
                    nw4r::math::VEC3 input((float)*(unsigned short*)(tex + 0x1c), (float)*(unsigned short*)(tex + 0x1e), 10.0f);
                    LocalScale((const Vec*)&input, (Vec*)&scaled, 0.1f);
                    fn_800B6E08(*(void**)(entry + 0x280), &scaled);
                    char* model = *(char**)(entry + 0x280);
                    nw4r::g3d::ResMat mat = ((nw4r::g3d::ResMdl*)(model + 8))->GetResMat(lbl_8045BFB8);
                    fn_800B7224(model, mat->m_id, name, p + 0x148);
                    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(entry + 0x288), *(void**)(*(char**)(entry + 0x280) + 0x10), lbl_8059E468);
                    (*(MuMsg**)(p + 0x338))->printIndex(index, *(unsigned int*)(record + 0xc), 0);
                }
            }
        }
    } else {
        fn_8019D950(*(void**)(*(char**)(entry + 0x280) + 0x10));
        (*(MuMsg**)(p + 0x338))->printf(index, lbl_8059E470);
    }
}