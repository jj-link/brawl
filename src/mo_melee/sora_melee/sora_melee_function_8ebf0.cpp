#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_13CF0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" s16 fn_27_90238(void* sys, void* obj);

struct soEventManageModuleImplLayout {
    char* m_vt0;
    u8 m_04;
    char* m_vt8;
    void* m_0c;
    s16 m_10;
};

class soEventManageModuleImpl {
public:
    soEventManageModuleImpl(void* p);
};

soEventManageModuleImpl::soEventManageModuleImpl(void* p) {
    soEventManageModuleImplLayout* self = (soEventManageModuleImplLayout*)this;
    char* vtbl = lbl_27_data_13CF0;
    self->m_04 = 0;
    self->m_vt0 = vtbl;
    self->m_vt8 = vtbl + 0xC;
    self->m_0c = p;
    self->m_10 = -1;
    self->m_10 = fn_27_90238(getInstance__13soEventSystemFv(), &self->m_vt8);
}
