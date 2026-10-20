#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

class SonicEventHandler {
public:
    unsigned char reserved[0x60];
    soModuleAccesser* accesser;
};

class SonicWorkModule {
public:
    virtual bool isNull() const;
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void clearAll(u32 index);
};

struct SonicEvent {
    int kind;
    unsigned char rest[0x1C];
};

extern "C" void fn_27_1324D4(SonicEventHandler*, SonicEvent*, soModuleAccesser*, void*, int);

extern "C" void fn_123_9888(SonicEventHandler* self, SonicEvent* event,
                            soModuleAccesser* accesser, void* object, int eventType) {
    switch (event->kind) {
    case 0x455:
        self->accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x126, self->accesser);
        break;
    case 6:
        reinterpret_cast<SonicWorkModule*>(self->accesser->m_enumerationStart->m_workManageModule)
            ->clearAll(0x1200003D);
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}
