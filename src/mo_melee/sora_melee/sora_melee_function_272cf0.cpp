#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_27_data_58394[];

struct Obj {
    unsigned char padding[0x3c];
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

extern "C" Obj* fn_27_272CF0(int param1, const char* name) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x154, 0xf);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        *(void**)((char*)obj + 0x3c) = lbl_27_data_58394;
        *(int*)((char*)obj + 0x150) = 0;
        *(int*)((char*)obj + 0xe4) = 0xe;
    }
    if (obj) {
        obj->slot42(param1);
    }
    return obj;
}
