#pragma force_active on
typedef int s32;

struct Object {
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
    virtual s32 getKind();
};

struct Array {
    s32* data;
    s32 count;
};

struct CommonData {
    unsigned char padding[0x48];
    Array* array;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
CommonData* fn_27_145534(void*, s32);

s32 fn_27_14D6F4(Object* object, s32 index) {
    CommonData* common =
        fn_27_145534(&g_ftCommonDataAccesser, object->getKind());
    return common->array->data[index];
}
}
