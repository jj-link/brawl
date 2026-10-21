#include <types.h>
#pragma force_active on

namespace nw4r {
    namespace g3d {
        class ScnMdlSimple;
    }
}

struct unk_struct {
    u32 _0x00;
    u32 _0x04;
    u32 _0x08;
    u32 _0x0C;
    u32 _0x10;
};

extern "C" void nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(const nw4r::g3d::ScnMdlSimple*, u32);

extern "C" void fn_800B6C30(const nw4r::g3d::ScnMdlSimple* arg0, unk_struct* arg1) {
    nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(arg0, arg1->_0x10);
}
