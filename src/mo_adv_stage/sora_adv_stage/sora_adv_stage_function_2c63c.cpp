#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_B070[];
extern "C" const float lbl_40_rodata_4F0;
extern "C" const float lbl_40_rodata_4F4;

struct YakumonoBase {
    unsigned char padding[0x3C];
};

struct Yakumono : YakumonoBase {
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
    virtual void setIndex(int);

    unsigned char pad40[0xA4];
    int unkE4;
    unsigned char padE8[0x68];
    int unk150;
    int unk154;
    unsigned char unk158;
    unsigned char pad159[3];
    float unk15C;
    unsigned char pad160[0xC];
    float unk16C;
    unsigned char unk170;
    unsigned char pad171[0x43];
    int unk1B4;
    int unk1B8;
    unsigned char pad1BC[4];
    unsigned char unk1C0;
};

extern "C" Yakumono* fn_40_2C63C(int index, const char* name) {
    Yakumono* obj = (Yakumono*)__nw__FUlQ25Heaps8HeapType(0x1C4, 15);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        *(void**)((char*)obj + 0x3C) = lbl_40_data_B070;
        obj->unk150 = 0;
        obj->unk154 = 0;
        obj->unk158 = 0;
        obj->unk15C = lbl_40_rodata_4F0;
        obj->unk16C = lbl_40_rodata_4F4;
        obj->unk170 = 1;
        obj->unk1B4 = 0;
        obj->unk1B8 = 0;
        obj->unk1C0 = 0;
        obj->unkE4 = 0;
    }
    if (obj) {
        obj->setIndex(index);
    }
    return obj;
}
