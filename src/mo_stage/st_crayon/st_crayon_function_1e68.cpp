#pragma force_active on

struct grCrayonGimicBase {
    unsigned char padding[0x3C];
};

class grCrayonGimic : public grCrayonGimicBase {
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

    static grCrayonGimic* create(int, const char*);
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" grCrayonGimic* fn_56_1EEC(grCrayonGimic*, const char*);

grCrayonGimic* grCrayonGimic::create(int id, const char* name) {
    grCrayonGimic* obj =
        (grCrayonGimic*)__nw__FUlQ25Heaps8HeapType(0x194, 0xf);

    if (obj) {
        obj = fn_56_1EEC(obj, name);
    }

    if (obj) {
        obj->init(id);
    }

    return obj;
}
