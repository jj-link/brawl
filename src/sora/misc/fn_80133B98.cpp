#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

namespace nw4r { namespace ut {
struct LinkListNode {
    char pad0[0x71];
    u8 unk71;
};
namespace detail {
struct LinkListImpl;
}
}}

extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, nw4r::ut::LinkListNode*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_80133CD4(nw4r::ut::LinkListNode*);
extern char lbl_8049E594[];

extern "C" nw4r::ut::LinkListNode* fn_80133B98(nw4r::ut::LinkListNode* arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)((arg0->unk71 >> 5) & 1) == 1U) {
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(lbl_8049E594, arg0);
            arg0->unk71 &= 0xFFFFFFDF;
            fn_80133CD4(arg0);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
