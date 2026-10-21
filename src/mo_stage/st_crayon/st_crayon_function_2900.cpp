#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_56_F90(void*, const char*);
extern "C" unsigned char lbl_56_data_D00[];

struct Padding {
    unsigned char padding[0x3c];
};

class grCrayonKumo : public Padding {
public:
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

    static grCrayonKumo* create(int, const char*);
};

grCrayonKumo* grCrayonKumo::create(int id, const char* name) {
    grCrayonKumo* obj =
        (grCrayonKumo*)__nw__FUlQ25Heaps8HeapType(0x170, 0xf);

    if (obj) {
        fn_56_F90(obj, name);
        *(void**)((char*)obj + 0x3c) = lbl_56_data_D00;
    }

    if (obj) {
        obj->init(id);
    }

    return obj;
}
