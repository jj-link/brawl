#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern unsigned char lbl_8040ABC0[0x18];
extern unsigned char lbl_8040AC08[0x18];
extern "C" void fn_801AAF90(nw4r::g3d::ScnMdlSimple* self, u32 arg1, Matrix* arg2);
extern "C" void GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(const nw4r::g3d::ScnMdlSimple* self, Matrix* out, u32 type, u32 arg3);

class VtblProbe {
public:
    virtual bool f0(void* a, void* b);
};

extern "C" void fn_800613B8(Matrix* arg0, nw4r::g3d::ScnMdlSimple* arg1, u32 arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5) {
    Matrix sp10(true);
    sp10.setSRT(*arg3, *arg4, *arg5);

    bool ok = false;
    if (arg1 != NULL) {
        void* spC = lbl_8040ABC0;
        if (((VtblProbe*)arg1)->f0(&spC, lbl_8040ABC0)) {
            ok = true;
        }
    }
    nw4r::g3d::ScnMdlSimple* sel = ok ? arg1 : NULL;
    if (sel != NULL) {
        GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(sel, arg0, 1, arg2);
    } else {
        bool ok2 = false;
        if (arg1 != NULL) {
            void* sp8 = lbl_8040AC08;
            if (((VtblProbe*)arg1)->f0(&sp8, lbl_8040AC08)) {
                ok2 = true;
            }
        }
        nw4r::g3d::ScnMdlSimple* sel2 = ok2 ? arg1 : NULL;
        if (sel2 != NULL) {
            GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(*(nw4r::g3d::ScnMdlSimple**)((char*)sel2 + 0xE8), arg0, 1, arg2);
        } else {
            fn_801AAF90(arg1, 1, arg0);
        }
    }
    arg0->mul(&sp10, arg0);
}
