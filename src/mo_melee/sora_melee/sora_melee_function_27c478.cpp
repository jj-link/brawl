#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_27_data_5AAE4[];
extern "C" const float lbl_27_rodata_45B0;

struct Base {
    unsigned char pad0[0x3c];
};

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
    virtual void slot42(short);
};

struct Object : VirtualBase {
    unsigned char pad40[0x114];
    int i154;
    unsigned char b158;
    unsigned char pad159[3];
    float f15c;
    unsigned char pad160[0x30];
    int i190;
    int i194;
};

extern "C" Object* fn_27_27C478(short arg, const char* name)
{
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x19c, 0xf);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        *(void***)((char*)obj + 0x3c) = (void**)lbl_27_data_5AAE4;
        obj->i154 = 0;
        obj->b158 = 0;
        obj->f15c = lbl_27_rodata_45B0;
        obj->i190 = 0;
        obj->i194 = 0;
    }
    if (obj)
        obj->slot42(arg);
    return obj;
}
