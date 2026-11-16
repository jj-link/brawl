#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_50_1F78(void* self, const char* name);
extern "C" char lbl_50_data_2E08[];

namespace Heaps {
enum HeapType {
    StageInstance = 15
};
}

void* operator new(unsigned long, Heaps::HeapType);

struct Sub {
    void* vt;
    void* p4;
    int f8;
};

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
    virtual void slot78(const char*);
};

struct Object {
    char pad0[0x3c];
    void* vtable;
    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x164 - 0xdc];
    int f164;
    int f168;
    unsigned char b16c;

    Object(const char* name) {
        fn_50_1F78(this, name);
        *(void**)((char*)this + 0x3c) = lbl_50_data_2E08;
        f164 = 0;
        f168 = 0;
        b16c = 8;
        Sub* s = (Sub*)((char*)this + 0xd0);
        if (!s)
            return;
        ((unsigned int*)s->p4)[1] |= 1;
    }
};

extern "C" Object* fn_50_AE38(int a, const char* b, const char* c) {
    Object* obj = new (Heaps::StageInstance) Object(c);
    if (obj) {
        ((Object_vptr_3c*)obj)->slot42(a);
        ((Object_vptr_3c*)obj)->slot78(b);
    }
    return obj;
}
