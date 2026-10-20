#include <types.h>
#pragma force_active on

struct InnerObj {
    u8 m_pad[8];
    u32 m_top : 3;
    u32 m_rest : 29;
};

struct SelfObj {
    u8 m_pad[4];
    InnerObj* m_inner;
};

extern "C" void* getInstance__16CameraControllerFv();
extern "C" void fn_8009CE3C(void* camera, InnerObj* inner);
extern "C" void fn_8009EFCC(InnerObj* self);
extern "C" void fn_8009EF38(InnerObj* self);

extern "C" void fn_27_B1720(SelfObj* self) {
    InnerObj* inner = self->m_inner;
    fn_8009CE3C(getInstance__16CameraControllerFv(), inner);
    inner->m_top = 1;
    fn_8009EFCC(inner);
    fn_8009EF38(inner);
}
