#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_11F70[];
extern "C" const float lbl_40_rodata_730;

struct Base { unsigned char pad0[0x3c]; };
struct VirtualBase : Base {
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
    virtual void slot42(int);
};
struct Object : VirtualBase {
    unsigned char pad40[0x10c];
    unsigned char b14c;
    unsigned char pad14d[3];
    float f150;
    float f154;
    int i158;
};
extern "C" Object* fn_40_3776C(int arg, const char* name) {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x164, 15);
    if (obj) {
        __ct__9grGimmickFPCc(obj, name);
        *(void**)((char*)obj + 0x3c) = lbl_40_data_11F70;
        obj->b14c = 0;
        obj->f150 = lbl_40_rodata_730;
        obj->f154 = lbl_40_rodata_730;
        obj->i158 = 0;
    }
    if (obj)
        obj->slot42(arg);
    return obj;
}