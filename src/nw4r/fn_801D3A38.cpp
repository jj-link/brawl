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

struct Base {
    virtual void f0();
    virtual void f1(int v);
};

extern "C" void fn_801BD158();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C0A68(void*, void*);

extern "C" void fn_801D3A38(char* self) {
    fn_801BD158();
    char* mtx;
    char* base = *(char**)(self + 0x1b4);
    mtx = base + 0x10;
    OSLockMutex(mtx);
    if (*(s32*)(base + 4) == 0) {
        OSUnlockMutex(mtx);
        return;
    }
    ((nw4r::ut::detail::LinkListImpl*)(base + 4))->Erase((nw4r::ut::LinkListNode*)(self + 0xb8));
    ((Base*)self)->f1(-1);
    fn_801C0A68(base, self);
    OSUnlockMutex(mtx);
}
