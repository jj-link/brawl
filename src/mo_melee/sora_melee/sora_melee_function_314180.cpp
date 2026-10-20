#include <types.h>
#pragma force_active on

class soModelModuleImpl {
public:
    ~soModelModuleImpl();
};

class soModelVirtualNode {
public:
    virtual ~soModelVirtualNode();
};

class soModelFoo {
public:
    u8 m_pad0[0x11C];
    soModelVirtualNode m_nodes[1];
    u8 m_pad130[0x130 - 0x11C - sizeof(soModelVirtualNode)];
    soModelModuleImpl m_module;
};

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soModelVirtualNodeFv(void*, int);

soModelFoo* fn_27_314180(soModelFoo* self, s32 flag) {
    if (self) {
        self->m_module.~soModelModuleImpl();
        if ((u32)self + 0x110 && (u32)self + 0x110) {
            __destroy_arr(self->m_nodes, __dt__18soModelVirtualNodeFv, 0x14, 1);
        }
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
