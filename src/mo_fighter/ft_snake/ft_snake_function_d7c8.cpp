#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

class SnakeModule {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3(int, soModuleAccesser*);
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15(int, int);
    virtual int m16();
    virtual void m17();
    virtual void m18();
    virtual void m19(int);
    virtual void m20(int, int);
};

struct SnakeFighter {
    unsigned char reserved[0x60];
    soModuleAccesser* m_accesser;
};

struct SnakeEvent {
    int kind;
};

extern "C" void fn_27_1324D4(void*, void*, soModuleAccesser*, void*, int);

extern "C" void fn_122_D7C8(SnakeFighter* self, SnakeEvent* event,
                            soModuleAccesser* accesser, void* object, int value) {
    switch (event->kind) {
    case 0x455: {
        int sk = ((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m16();
        switch (sk) {
        case 0x117:
            ((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m3(0x118, self->m_accesser);
            break;
        }
        ((SnakeModule*)self->m_accesser->m_enumerationStart->m_generateArticleManageModule)->m15(3, 0);
        break;
    }
    case 0x456:
        if (((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m16() == 0x11f)
            ((SnakeModule*)self->m_accesser->m_enumerationStart->m_workManageModule)->m20(1, 0x22000010);
        else if (((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m16() == 0x113)
            ((SnakeModule*)self->m_accesser->m_enumerationStart->m_workManageModule)->m20(1, 0x22000010);
        break;
    case 0x457:
        if (((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m16() == 0x11f)
            ((SnakeModule*)self->m_accesser->m_enumerationStart->m_workManageModule)->m20(1, 0x22000011);
        else if (((SnakeModule*)self->m_accesser->m_enumerationStart->m_statusModule)->m16() == 0x113)
            ((SnakeModule*)self->m_accesser->m_enumerationStart->m_workManageModule)->m20(1, 0x22000011);
        break;
    case 6:
        ((SnakeModule*)self->m_accesser->m_enumerationStart->m_workManageModule)->m19(0x1200003d);
        break;
    }
    fn_27_1324D4(self, event, accesser, object, value);
}