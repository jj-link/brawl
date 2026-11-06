#pragma force_active on
class Object_vptr_0 {
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
    virtual int slot9(int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual int slot17(int);
};
extern "C" int fn_27_28DCF8(char* self) {
    if (((Object_vptr_0*)(self + 0x2aac))->slot17(0x1200000f) == 0)
        return 0;
    int r;
    if ((*(Object_vptr_0**)(*(char**)(self + 0x1a4) + 0x70))->slot16() == 2)
        r = 1;
    else
        r = ((Object_vptr_0*)(self + 0x27a8))->slot9(3);
    if (r)
        return 0;
    return 1;
}