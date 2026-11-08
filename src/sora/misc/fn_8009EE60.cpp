#pragma force_active on
typedef unsigned int u32;
typedef int s32;

namespace nw4r { namespace ut {
struct LinkListNode {
    char pad0[8];
    u32 unk8;
};
namespace detail {
struct LinkListImpl;
}
}}

extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, nw4r::ut::LinkListNode*);
extern "C" void __dl__FPv(void*);
extern char lbl_8049DEDC[];

extern "C" nw4r::ut::LinkListNode* fn_8009EE60(nw4r::ut::LinkListNode* arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((u32)((arg0->unk8 >> 13) & 1) == 1U) {
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(lbl_8049DEDC, arg0);
            arg0->unk8 &= 0xFFFFDFFF;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
