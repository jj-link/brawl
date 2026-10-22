#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_40_27800(void*, const char*);
extern "C" unsigned char lbl_40_data_12D58[];
extern "C" const float lbl_40_rodata_758;
extern "C" const float lbl_40_rodata_75C;

struct Base {
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
    virtual void slot40();
    virtual void slot41();
    virtual void slot42(int);
    virtual void slot43();
    virtual void slot44(int);
    unsigned char pad40[0xA4];
    int unkE4;
    unsigned char padE8[0x10];
    float unkF8;
    unsigned char padFC[0x6C];
    unsigned char unk168;
    unsigned char pad169[3];
    float unk16C;
    float unk170;
    unsigned char pad174[0xC];
    int unk180;
    unsigned char pad184[0x2C];
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
};

extern "C" Base* fn_40_38488(int arg0, const char* name) {
    Base* obj = (Base*)__nw__FUlQ25Heaps8HeapType(0x1C4, 15);
    if (obj) {
        fn_40_27800(obj, name);
        *(void**)((char*)obj + 0x3C) = lbl_40_data_12D58;
        obj->unk168 = 0;
        obj->unk16C = lbl_40_rodata_758;
        obj->unk170 = lbl_40_rodata_758;
        obj->unk180 = 0;
        obj->unk1B0 = 0;
        obj->unk1B4 = 0;
        obj->unk1B8 = 0;
        obj->unk1BC = 0;
        obj->unk1C0 = 0;
        obj->unkE4 = 0x1F;
        obj->unkF8 = lbl_40_rodata_75C;
    }
    if (obj) {
        obj->slot42(arg0);
    }
    return obj;
}
