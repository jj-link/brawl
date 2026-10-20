#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class Object {
public:
    unsigned char padding[0x3C];

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
    virtual u32 getIndex();
};

struct Module {
    unsigned char padding[8];
    Object* object;
};

struct Context {
    unsigned char padding[8];
    Module* module;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
u32 fn_27_1456B4(s32, u32);

u32 fn_27_14D9E8(Context context) {
    Module* module = context.module;
    u32 index = module->object->getIndex();
    return fn_27_1456B4((s32)&g_ftCommonDataAccesser, index);
}
}
