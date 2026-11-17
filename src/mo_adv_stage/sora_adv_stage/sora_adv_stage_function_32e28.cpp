#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
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
    virtual void slot42();
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
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual bool slot90();
};

struct Ptr2C { char pad[0x1c]; unsigned short v; };
struct Ptr0C { char pad[0x2c]; Ptr2C* p2c; };
struct Anim { char pad[0xc]; Ptr0C* p0c; };

extern "C" void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
extern "C" void setFrame__16gfModelAnimationFd(void*, double);
extern const float lbl_40_rodata_630;

struct Self {
    char pad0[0x44];
    void** p44;
    Anim** p48;
    char pad4c[0x80];
    Object_vptr_3c* obj;
    char pad0d0[0x94];
    int state;
    float rate;
    unsigned char flag;
    char pad171[3];
    float frame;
};

extern "C" void fn_40_32E28(Self* self, float dt) {
    if (self->obj->slot90()) {
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*self->p48, *self->p44);
        self->state = 5;
    }
    if (self->flag != 0) {
        float f = self->frame - dt * self->rate;
        self->frame = f;
        if (f <= lbl_40_rodata_630) {
            self->frame = (float)(*self->p48)->p0c->p2c->v;
        }
        setFrame__16gfModelAnimationFd(*self->p48, self->frame);
    }
}
