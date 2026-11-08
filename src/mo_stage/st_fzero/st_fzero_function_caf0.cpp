#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_61_2320(void*, const char*);
extern char lbl_61_data_3920[];
extern const float lbl_61_rodata_168;
}

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
    virtual void slot42(void*);
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
    virtual void slot78(void*);
    char pad2[0x158 - 0x40];
    int field158;
    int field15C;
    int field160;
    int field164;
    unsigned char field168;
    float field16C;
};

extern "C" void* fn_61_CAF0(void* a, void* b, const char* c) {
    Object_vptr_3c* obj = (Object_vptr_3c*)__nw__FUlQ25Heaps8HeapType(0x170, 15);
    if (obj) {
        fn_61_2320(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_61_data_3920;
        obj->field158 = 0;
        obj->field15C = 0;
        obj->field160 = 0;
        obj->field164 = 0;
        obj->field168 = 1;
        obj->field16C = lbl_61_rodata_168;
    }
    if (obj) {
        obj->slot42(a);
        obj->slot78(b);
    }
    return obj;
}
