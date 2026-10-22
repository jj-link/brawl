#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void* list, void* node);
extern "C" void fn_8016DFCC(void* self);
extern "C" void fn_8016E0C0(void* self);

struct Pad {
    char pad[0x1C];
};

struct NodeObj : public Pad {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void* arg);
};

extern "C" void fn_801638D0(void* unused, char* self, void* arg) {
    char* list = self + 0x90;
    NodeObj* node = 0;
    while ((node = (NodeObj*)fn_8015C1B0(list, node)) != 0) {
        fn_8016DFCC(node);
        node->f5(arg);
        fn_8016E0C0(node);
    }
}
