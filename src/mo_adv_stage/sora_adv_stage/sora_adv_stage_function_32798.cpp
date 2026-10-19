#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_272668(void*, const char*);
extern "C" char lbl_40_data_F1A0[];

struct StageBase {
    char padding[0x3c];
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
    virtual void init(int);
};

struct StageObject {
    char pad0[0x3c];
    void** vtable;
    char pad40[0x114];
    void* secondaryVtable;
    int field158;
    int field15c;
    int field160;
    int field164;
    char pad168[0xc];
};

extern "C" StageObject* fn_40_32798(int arg, const char* name) {
    StageObject* obj =
        (StageObject*)__nw__FUlQ25Heaps8HeapType(0x174, 15);

    if (obj) {
        fn_27_272668(obj, name);
        obj->field158 = -1;
        obj->field15c = 0;
        obj->field160 = 0;
        obj->vtable = (void**)lbl_40_data_F1A0;
        obj->secondaryVtable = lbl_40_data_F1A0 + 0x1cc;
        obj->field164 = 0;
    }

    ((StageBase*)obj)->init(arg);
    return obj;
}
