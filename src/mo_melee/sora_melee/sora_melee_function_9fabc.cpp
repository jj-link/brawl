#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Prefix {
    unsigned char pad[8];
};

struct X : Prefix {
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
    virtual Vec3 get(void*, int);
};

struct Holder {
    unsigned char pad[4];
    X* obj;
};

struct B {
    unsigned char pad[0xD8];
    Holder* h;
};

struct A {
    unsigned char pad0[4];
    void* p4;
    unsigned char pad8[8];
    Vec3 pos;
    Vec3 prev;
    unsigned char pad28;
    unsigned char flag;
};

extern "C" int fn_27_9FABC(A* a, B* b) {
    if (a->flag == 0) {
        a->prev = a->pos;
    }

    a->pos = b->h->obj->get(a->p4, 0);

    if (a->flag == 1) {
        a->prev = a->pos;
        a->flag = 0;
        return 1;
    }

    return 0;
}
