#include <ft/fighter.h>
#pragma force_active on

class JostleModule : public soNull, public soNullable {
public:
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void setData(void*);
    virtual void setEnabled(bool);
};

class ResourceIds : public soNullable {
public:
    virtual ~ResourceIds();
    virtual void setResIdPacked(u32);
    virtual void setAnmResId(u32);
    virtual void setMdlResId(u32);
    virtual void setTexResId(u32);
    virtual void setMdlResIndex(u32);
};

extern void* g_ftManager;
extern "C" {
unsigned char fn_27_10AA8C(void*, int, int);
int fn_27_10AAC4(void*, int);
void fn_105_A7F0(void*, int, int, void*, int);
unsigned char fn_27_1119B8(ftOwner*);
unsigned int fn_105_AB48(int);
void fn_27_12646C(void*);
}

class IceClimber : public Fighter {
    char padding[0x1FE48 - sizeof(Fighter)];
public:
    char* data;
    unsigned char flag;
};

#define DATA (self->data)
#define MODULES (self->m_moduleAccesser->m_enumerationStart)

extern "C" void fn_105_A5A4(IceClimber* self) {
    if (fn_27_10AA8C(g_ftManager, self->m_entryId, *(int*)((char*)self + 0x28)) == 0) {
        self->flag = 0;
    } else {
        *(unsigned char*)((char*)self + 0x1FE4C) = 1;
    }
    unsigned int enabled = 0;
    if (fn_27_10AA8C(g_ftManager, self->m_entryId, *(int*)((char*)self + 0x28)) == 1 ||
        fn_27_10AAC4(g_ftManager, self->m_entryId) == 0x12) {
        fn_105_A7F0(self, 1, 0, *(void**)(DATA + 0x7C), 0x1F2);
        fn_105_A7F0(self, 2, 0, *(void**)(DATA + 0x80), 0x1F2);
        fn_105_A7F0(self, 4, 0, *(void**)(DATA + 0x88), 0x1F2);
        if (fn_105_AB48(fn_27_1119B8(self->getOwner())) == 0) {
            enabled = 1;
        }
        ((JostleModule*)MODULES->m_jostleModule)->setData(*(void**)(DATA + 0xC0));
        ((JostleModule*)MODULES->m_jostleModule)->setEnabled(true);
    } else {
        if (fn_105_AB48(fn_27_1119B8(self->getOwner())) == 1) {
            enabled = 1;
        }
    }
    if (enabled == 1) {
        fn_105_A7F0(self, 3, 0, *(void**)(DATA + 0x84), 0x1F2);
        MODULES->m_soundModule->setSoundIdData((soSoundModule::SoundIdData*)(DATA + 0xA4));
    }
    ((ResourceIds*)MODULES->m_resourceModule->getResourceIdAccesser())->setMdlResIndex(enabled);
    MODULES->m_groundModule->setIgnoreFriction(true);
    fn_27_12646C(self);
}
