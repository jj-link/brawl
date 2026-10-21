#include <types.h>
#pragma force_active on

namespace nw4r {
namespace ut {
struct LinkListNode;
namespace detail {
struct LinkListImpl {
    void Erase(LinkListNode* node);
};
}
}
}

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);

extern "C" {
void fn_801B7F54(u8* self, nw4r::ut::LinkListNode* node) {
    s32 level = OSDisableInterrupts();
    ((nw4r::ut::detail::LinkListImpl*)(self + 8))->Erase(node);
    OSRestoreInterrupts(level);
}
}
