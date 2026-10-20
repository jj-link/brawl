#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual void f0();
    virtual void* f1();
};

struct fn27Holder {
    u8 pad[0x30];
    fn27Iface* m30;
    fn27Iface* m34;
};

extern "C" {
u32 fn_27_3A994(fn27Holder* self, u32 unused, u32 sel) {
    if (sel == 1) {
        void* p = self->m34->f1();
        return *(u32*)((u8*)p + 0x18);
    }
    void* p = self->m30->f1();
    return *(u32*)((u8*)p + 0x1C);
}
}
