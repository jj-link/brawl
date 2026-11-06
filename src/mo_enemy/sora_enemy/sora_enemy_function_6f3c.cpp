#pragma force_active on

extern "C" const float lbl_41_rodata_14;

struct Params {
    int kind;
    unsigned char flag;
    int a;
    int b;
    int c;
    int d;
    float value;
    unsigned char enabled;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
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
    virtual void slot16(int, Params*, int);
    virtual void slot17();
    virtual void slot18();
    virtual int slot19(int);
};

struct Modules {
    char pad[0x54];
    Object_vptr_0* article;
    char pad58[0xC];
    Object_vptr_0* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
    Object_vptr_0& getArticle() { return *modules->article; }
    Object_vptr_0& getWork() { return *modules->work; }
};

struct Enemy {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_41_6F3C(Enemy* self, int arg1, int arg2, int arg3, int arg4) {
    Params p;
    p.kind = 11;
    p.flag = 0;
    p.a = arg4;
    p.b = -1;
    p.c = -1;
    p.d = -1;
    p.value = lbl_41_rodata_14;
    p.enabled = 1;
    self->accesser->modules->article->slot16(0, &p, 0);
    self->accesser->getWork().slot5(self->accesser->getArticle().slot19(0), arg1);
    self->accesser->modules->work->slot5(p.b, arg2);
    self->accesser->modules->work->slot5(p.c, arg3);
}
