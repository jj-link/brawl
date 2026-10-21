#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8002BAB0(void*);
extern "C" void fn_8002BB1C(void*, void*, int);

class gfPadSystem {
public:
    void createRumbleSystem();
    u8 pad0[0xb68];
    void* m_b68;
};

void gfPadSystem::createRumbleSystem() {
    if (m_b68 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x100, 1);
        if (p != 0) {
            p = fn_8002BAB0(p);
        }
        m_b68 = p;
        fn_8002BB1C(p, this, 3);
    }
}
