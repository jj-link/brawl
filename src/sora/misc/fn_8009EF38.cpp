#pragma force_active on
typedef unsigned int u32;

namespace nw4r {
namespace ut {
struct LinkListNode {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};
namespace detail {
struct LinkListImpl {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};
}
}
}

extern "C" {
extern nw4r::ut::detail::LinkListImpl lbl_8049DEDC;
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(nw4r::ut::detail::LinkListImpl*, nw4r::ut::LinkListNode*);

void fn_8009EF38(nw4r::ut::LinkListNode* arg0) {
    if (((arg0->m_8 >> 13) & 1) == 1) {
        Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(&lbl_8049DEDC, arg0);
        arg0->m_8 &= ~0x2000u;
    }
}
}
