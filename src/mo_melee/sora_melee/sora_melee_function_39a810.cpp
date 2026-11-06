#pragma force_active on
extern float lbl_27_rodata_7DC8;
struct Param {
    int kind;
    char flag;
    float value;
    char padding[4];
    char flag2;
};
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(int, Param*, int);
    virtual int slot17(int);
    virtual void slot18(int);
};
struct Sub {
    char pad[0x54];
    Object_vptr_0* p54;
    char pad2[0xc];
    Object_vptr_0* p64;
};
struct Actor {
    char pad[0xd8];
    Sub* sub;
};
extern "C" void fn_27_39A810(void*, Actor* actor) {
    if (!actor->sub->p64->slot17(0x22000000)) {
        Param p;
        p.kind = 0x1a;
        p.flag = 0;
        p.value = lbl_27_rodata_7DC8;
        p.flag2 = 0;
        actor->sub->p54->slot16(0, &p, 0);
        actor->sub->p64->slot18(0x22000000);
    }
}