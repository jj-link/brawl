#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_48_79A4(void*, int);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);

struct Base {
    unsigned char padding[0x3c];
};

struct Gimmick : Base {
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

extern "C" Gimmick* fn_48_78E8(int arg0, int arg1) {
    Gimmick* obj = (Gimmick*)__nw__FUlQ25Heaps8HeapType(0x220, 15);
    if (obj) {
        obj = (Gimmick*)fn_48_79A4(obj, arg1);
    }
    if (obj) {
        obj->slot42(arg0);
        *(int*)((char*)obj + 0x70) = 15;
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(obj, 1, 15);
        setCalcuCallbackRoot__9grGimmickFUl(obj, 1);
        obj->slot26();
    }
    return obj;
}
