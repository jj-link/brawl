#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_FCB0[];
extern "C" const float lbl_40_rodata_6A0;

struct GrYak {
    unsigned char pad0[0x3C];
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
    virtual void invoke(int);
};

extern "C" void* fn_40_33B84(int arg, const char* name)
{
    GrYak* obj = (GrYak*)__nw__FUlQ25Heaps8HeapType(0x1C4, 15);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        *(void**)((unsigned char*)obj + 0x3C) = lbl_40_data_FCB0;
        *((unsigned char*)obj + 0x158) = 0;
        *(int*)((unsigned char*)obj + 0x160) = 0;
        *(int*)((unsigned char*)obj + 0x164) = 0;
        *(int*)((unsigned char*)obj + 0x168) = 0;
        *(float*)((unsigned char*)obj + 0x184) = lbl_40_rodata_6A0;
        *(int*)((unsigned char*)obj + 0x1B8) = 0;
        *(int*)((unsigned char*)obj + 0x1BC) = 0;
    }
    obj->invoke(arg);
    return obj;
}
