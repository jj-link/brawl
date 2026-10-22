#include <types.h>
#pragma force_active on

namespace nw4r {
namespace ut {
struct LinkListNode;
namespace detail {
class LinkListImpl {
public:
    void Erase(LinkListNode* node);
};
}
}
}

extern "C" u32 fn_800130A8(void* a, void* b);

extern "C" void fn_80012504(char* arg0, char* arg1) {
    char* key = arg1 + 0x2C;
    char* p = arg0 + 0x40;
    for (;;) {
        if (((((unsigned char*)p)[0x11] >> 7) & 1) != 0) {
            break;
        }
        u32 idx = fn_800130A8(p, key);
        if (idx == 0xFF) {
            break;
        }
        char* next = *(char**)(p + idx * 4 + 0x18);
        if (next == 0) {
            break;
        }
        p = next;
    }
    ((nw4r::ut::detail::LinkListImpl*)(p + 0x28))->Erase((nw4r::ut::LinkListNode*)arg1);
}
