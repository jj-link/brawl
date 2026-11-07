#include <types.h>
#pragma force_active on
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_27_248088();
    virtual void slot40();
    virtual int slot41();
};
struct Context {
    char pad[0x110];
    int active;
    gfTask* target;
};
extern "C" int fn_27_13FE70(Context* self) {
    if (self->active == 0 || self->target == 0) {
        return 0;
    }
    return self->target->slot41();
}
