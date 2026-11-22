#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_78_rodata_58;

typedef void (*Method)(void*);
extern "C" Method lbl_78_data_9E0[];
extern "C" Method lbl_78_data_5A4[];

struct Inner {
    unsigned int pad0;
    unsigned int flags;
};

class Sub {
public:
    virtual void fn_78_7040();
    virtual void fn_78_6460();
    virtual void fn_78_6470();
    virtual void fn_78_57A4();
    virtual void fn_78_5498(int, int);
    Inner* inner;
    unsigned int unk8;
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void processBegin();
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
    virtual void setupMelee();
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
    virtual void fn_78_152C(int);
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
    virtual void setTgtNode(int);
};

struct Object {
    char pad0[0x3C];
    Method* vtable;
    char pad40[0x90];
    char sub[0x0C];
    char padDC[0x74];
    unsigned char unk150;
    char pad151[3];
    float unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned char unk160;
    char pad161[3];
    float unk164;
};

inline Object* initSub(Object* self, Sub* sub) {
    if (sub == 0) return self;
    sub->unk8 = 1;
    sub->fn_78_5498(0, 15);
    sub->inner->flags |= 1;
    return self;
}

extern "C" Object* fn_78_1DA8(int a, int b, const char* name) {
    Object* self = (Object*)__nw__FUlQ25Heaps8HeapType(0x168, 15);
    if (self) {
        __ct__10grYakumonoFPCc(self, name);
        self->vtable = lbl_78_data_9E0;
        self->unk150 = 0;
        self->unk154 = lbl_78_rodata_58;
        self->unk158 = 0;
        ((Object_vptr_3c*)self)->setupMelee();
        self->vtable = lbl_78_data_5A4;
        Sub* sub = (Sub*)self->sub;
        self->unk15C = 0;
        self->unk160 = 1;
        self->unk164 = lbl_78_rodata_58;
        self = initSub(self, sub);
    }
    if (self) {
        ((Object_vptr_3c*)self)->fn_78_152C(a);
        ((Object_vptr_3c*)self)->setTgtNode(b);
    }
    return self;
}
