#pragma force_active on
#include <so/so_module_accesser.h>

struct DiddyResourceModule {
    unsigned int pad0;
    unsigned int pad1;
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void* getResourceIdAccesser(); // vtable+0x18
};
struct DiddyIdAccesser {
    virtual void i00();
    virtual void i01();
    virtual void i02();
    virtual void i03();
    virtual void i04();
    virtual void i05();
    virtual void i06();
    virtual void i07();
    virtual void i08();
    virtual void i09();
    virtual void i0A();
    virtual void i0B();
    virtual void i0C();
    virtual void i0D();
    virtual void i0E();
    virtual unsigned int getArchiveId(); // vtable+0x44
};

extern "C" {
extern signed char lbl_115_bss_23C;
extern char lbl_115_bss_240[];
extern char lbl_115_bss_228[];
void fn_27_364100(void* p);
void* fn_27_364110(void* p, int count);
void* __register_global_object(void* object, void* destructor, void* chain);
void fn_27_364340(void* a, void* b, void* c, unsigned int d);
}

extern "C" void fn_115_8B10(void* weapon, soModuleAccesser* accesser) {
    if (lbl_115_bss_23C == 0) {
        fn_27_364100(&lbl_115_bss_240);
        __register_global_object(&lbl_115_bss_240, (void*)fn_27_364110, &lbl_115_bss_228);
        lbl_115_bss_23C = 1;
    }
    DiddyResourceModule* resource =
        reinterpret_cast<DiddyResourceModule*>(accesser->m_enumerationStart->m_resourceModule);
    DiddyIdAccesser* ids = static_cast<DiddyIdAccesser*>(resource->getResourceIdAccesser());
    fn_27_364340(&lbl_115_bss_240, weapon, accesser, ids->getArchiveId());
}
