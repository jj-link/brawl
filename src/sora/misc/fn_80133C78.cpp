#include <types.h>
#pragma force_active on

namespace nw4r {
namespace ut {
struct LinkListNode {
    u8 pad0[0x71];
    u8 m_flags;
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
extern nw4r::ut::detail::LinkListImpl lbl_8049E594;
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(nw4r::ut::detail::LinkListImpl*, nw4r::ut::LinkListNode*);
void fn_80133CD4(nw4r::ut::LinkListNode*);

void fn_80133C78(nw4r::ut::LinkListNode* self) {
    if (((self->m_flags >> 5) & 1u) == 1u) {
        Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(&lbl_8049E594, self);
        self->m_flags &= ~0x20u;
        fn_80133CD4(self);
    }
}
}
