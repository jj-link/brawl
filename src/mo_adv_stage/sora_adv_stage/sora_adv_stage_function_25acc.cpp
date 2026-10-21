#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__21grYakumonoPunchSliderFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_7308[];

struct Base {
    unsigned char padding[0x3c];
};

struct Ground : Base {
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
};

extern "C" Ground* fn_40_25ACC(int index, const char* name) {
    Ground* ground = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1c4, 15);
    if (ground) {
        __ct__21grYakumonoPunchSliderFPCc(ground, name);
        *(void**)((char*)ground + 0x3c) = lbl_40_data_7308;
    }
    if (ground) {
        ground->setIndex(index);
    }
    return ground;
}
