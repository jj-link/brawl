#include <types.h>
#pragma force_active on

namespace nw4r {
    namespace g3d {
        class ScnMdlSimple;
    }
}

struct Node {
    u32 _0x00;
    u32 _0x04;
    u32 _0x08;
    u32 _0x0C;
};

struct Obj {
    char pad[0xe8];
    void* res; // 0xe8
};

struct Outer {
    char pad[0x10];
    Obj* obj; // 0x10
};

extern "C" Node* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* res, const char* name);
extern "C" void nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(const nw4r::g3d::ScnMdlSimple* scnMdl, u32 a, u32 nodeId);

extern "C" void fn_800B6C38(const nw4r::g3d::ScnMdlSimple* arg0, Outer* arg1, const char* name) {
    void* res = arg1->obj->res;
    Node* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&res, name);
    u32 id = (node != 0) ? node->_0x0C : 0;
    nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(arg0, (u32)arg1->obj, id);
}
