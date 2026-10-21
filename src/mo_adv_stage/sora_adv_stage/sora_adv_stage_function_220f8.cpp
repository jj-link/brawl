#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__9grGimmickFPCc(void*, const char*);

struct DataBlock {
    unsigned char data[0x170];
};

extern DataBlock lbl_40_data_5CEC;

struct Base {
    unsigned char pad[0x3C];
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
    virtual void init(void*);
};

extern "C" void* fn_40_220F8(void* stage, const char* name) {
    unsigned char* obj =
        (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x168, 0x0F);

    if (obj) {
        __ct__9grGimmickFPCc(obj, name);
        obj[0x150] = 0;
        obj[0x151] = 0;
        *(DataBlock**)(obj + 0x3C) = &lbl_40_data_5CEC;
        *(void**)(obj + 0x14C) =
            (unsigned char*)&lbl_40_data_5CEC + 0x170;
        *(unsigned int*)(obj + 0x154) = 0;
        *(unsigned int*)(obj + 0x158) = 0;
        *(unsigned int*)(obj + 0x15C) = 0;
        *(unsigned int*)(obj + 0x160) = 0;
    }

    ((Ground*)obj)->init(stage);
    return obj;
}
