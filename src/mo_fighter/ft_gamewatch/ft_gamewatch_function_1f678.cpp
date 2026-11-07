#pragma force_active on

class Class_9C3C {
public:
    virtual void fn_107_8720();
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
    virtual float slot12(int);
    virtual void slot13(float, int);
    virtual void slot14();
    virtual void slot15();
};

class Class_9E14 {
public:
    virtual void fn_107_8720();
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
    virtual void slot15(int, void*);
};

struct Modules {
    char pad0[0x54];
    Class_9E14* module54;
    char pad58[0xC];
    Class_9C3C* work;
};

struct Accesser {
    char pad0[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad0[0x60];
    Accesser* accesser;
};

extern "C" {
void fn_107_1F764(void* obj, void* p, float f, unsigned char b);
void fn_27_1DB174(void* self, float f, int i, float g);
extern const float lbl_107_rodata_138;
extern const float lbl_107_rodata_140;
}

extern "C" int fn_107_1F678(Fighter* self) {
    char buf[16];
    float value = self->accesser->modules->work->slot12(0x11000001);
    if (value > lbl_107_rodata_140) {
        fn_107_1F764(buf, (void*)0x839, value, 0);
        self->accesser->modules->module54->slot15(3, buf);
        fn_27_1DB174(self, value, 0, lbl_107_rodata_138);
        self->accesser->modules->work->slot13(lbl_107_rodata_140, 0x11000001);
    }
    return 0;
}
