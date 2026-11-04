#include <it/it_manager.h>
#pragma force_active on

extern "C" unsigned int fn_27_23AC10(void*);
extern "C" void fn_27_23AC24(void*);

struct ObjectBase { char pad[0x3c]; };
class Object : public ObjectBase {
public:
    virtual void processDefault();
    virtual void fn_27_23EC18();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_27_23EBC0();
    virtual void fn_27_23ECE8();
    virtual void fn_27_23EEF4();
    virtual bool fn_27_23EB4C();
    virtual void fn_27_23E814();
    virtual void fn_27_23EFD0();
    virtual void fn_27_23C5D4();
    virtual void fn_27_23ED98(unsigned char);
    char pad2[0x20];
    BaseItem* item;
    unsigned char param;
    char pad3[3];
    itKind kind;
};

extern "C" void fn_27_23ECE8(Object* self) {
    if (fn_27_23AC10(self) != 1) {
        if (self->fn_27_23EB4C()) {
            itManager* manager = itManager::getInstance();
            if (manager) {
                self->item = manager->createItem(self->kind, 0, -1, 0, 0, 0xffff, 0, 0xffff);
                if (self->item) {
                    self->fn_27_23ED98(self->param);
                    fn_27_23AC24(self);
                }
            }
        }
    }
}