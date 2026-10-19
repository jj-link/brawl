#include <types.h>
#pragma force_active on

extern "C" {
void fn_80135890(void* p);

struct fn27Sub {
    u32 unk0;
    void* unk4;
};

class fn27Inner {
public:
    virtual void f0();
    virtual fn27Sub* f1();
};

struct fn27Host {
    u8 pad[0x28];
    fn27Inner* m_inner;
};

void fn_27_273C0(fn27Host* self) {
    fn27Sub* sub = self->m_inner->f1();
    fn_80135890(sub->unk4);
}
}
