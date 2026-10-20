#include <so/so_module_accesser.h>
#pragma force_active on

// Slot-exact views of the resource interfaces used here; the real headers
// leave the surrounding virtuals unused by this process.
struct ArticleResourceHeader {
    int pad0;
    int pad1;
};
class ArticleResourceModule : public ArticleResourceHeader {
public:
    virtual void reserved00() = 0;
    virtual void reserved01() = 0;
    virtual void reserved02() = 0;
    virtual void reserved03() = 0;
    virtual void* getResourceIdAccesser() = 0; // vtable+0x18
};
class ArticleResourceIdAccesser {
public:
    virtual void reserved00() = 0;
    virtual void reserved01() = 0;
    virtual void reserved02() = 0;
    virtual void reserved03() = 0;
    virtual void reserved04() = 0;
    virtual void reserved05() = 0;
    virtual void reserved06() = 0;
    virtual void reserved07() = 0;
    virtual void reserved08() = 0;
    virtual void reserved09() = 0;
    virtual void reserved0A() = 0;
    virtual void reserved0B() = 0;
    virtual void reserved0C() = 0;
    virtual void reserved0D() = 0;
    virtual void reserved0E() = 0;
    virtual unsigned int getArchiveId() = 0; // vtable+0x44
};
class ArticleGenerateManager {
public:
    virtual void reserved00() = 0;
    virtual void reserved01() = 0;
    virtual void reserved02() = 0;
    virtual void reserved03() = 0;
    virtual void reserved04() = 0;
    virtual void reserved05() = 0;
    virtual void reserved06() = 0;
    virtual void reserved07() = 0;
    virtual void reserved08() = 0;
    virtual void reserved09() = 0;
    virtual void reserved0A() = 0;
    virtual void reserved0B() = 0;
    virtual void reserved0C() = 0;
    virtual void reserved0D() = 0;
    virtual void reserved0E() = 0;
    virtual void reserved0F() = 0;
    virtual void reserved10() = 0;
    virtual void reserved11() = 0;
    virtual void generate(int, soModuleAccesser*, unsigned int, int) = 0; // vtable+0x50
};

extern "C" {
extern char lbl_91_bss_1D0;
extern void* lbl_91_bss_1D4;
extern char lbl_91_bss_1BC[12];
void fn_27_2D90B0(void* self);
void fn_27_2D90C0(void* p, int n);
void __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_91_9D28(int param1, soModuleAccesser* accesser) {
    if ((signed char)lbl_91_bss_1D0 == 0) {
        fn_27_2D90B0(&lbl_91_bss_1D4);
        __register_global_object(&lbl_91_bss_1D4, (void*)fn_27_2D90C0, &lbl_91_bss_1BC);
        lbl_91_bss_1D0 = 1;
    }
    ArticleResourceModule* resource =
        reinterpret_cast<ArticleResourceModule*>(accesser->m_enumerationStart->m_resourceModule);
    ArticleResourceIdAccesser* ids =
        static_cast<ArticleResourceIdAccesser*>(resource->getResourceIdAccesser());
    ArticleGenerateManager* manager =
        reinterpret_cast<ArticleGenerateManager*>(&lbl_91_bss_1D4);
    manager->generate(param1, accesser, ids->getArchiveId(), 0x1b);
}
