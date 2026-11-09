#pragma force_active on
#include <gr/gr_yakumono.h>
#include <sr/sr_common.h>
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_76_rodata_8;
extern "C" char lbl_76_data_650[], lbl_76_data_430[];
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
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
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42(int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78(int);
};
struct Object {
    char pad[0x3c];
    char* vtable;
    char pad40[0x110];
    unsigned char flag;
    char pad151[3];
    float value;
    int a, b, c;
    float d, e;
};
extern "C" Object* fn_76_C9C(int a, int b, const char* name) {
    Object* self = (Object*)operator new(0x16c, (Heaps::HeapType)15);
    if (self) {
        __ct__10grYakumonoFPCc(self, name);
        self->vtable = lbl_76_data_650;
        self->flag = 0;
        self->value = lbl_76_rodata_8;
        ((Object_vptr_3c*)self)->slot26();
        self->vtable = lbl_76_data_430;
        self->a = 0;
        self->b = 0;
        self->c = 0;
        self->d = lbl_76_rodata_8;
        self->e = lbl_76_rodata_8;
    }
    if (self) {
        ((Object_vptr_3c*)self)->slot42(a);
        ((Object_vptr_3c*)self)->slot78(b);
    }
    return self;
}