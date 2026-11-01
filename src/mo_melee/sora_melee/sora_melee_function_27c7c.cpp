#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Vec2f {
    float x;
    float y;
};

struct Entry {
    u32 field0;
    void* collStatus;
};

class ShapeArray {
public:
    virtual void* v0();
    virtual Entry* at(u32 index);
};

class Self {
public:
    u32 pad0;
    u32 pad4;

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
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual Vec2f fn150(u32 index);
    virtual Vec2f fn154(u32 index);
    virtual Vec2f fn158(u32 index);
    virtual Vec2f fn15c(u32 index);

    u32 pad12[7];
    ShapeArray* shapeArray;
};

extern "C" u32 fn_80134534(void*, u32);
extern "C" void fn_80111DE4(u32*, void*, float*);
extern "C" const float lbl_27_rodata_3C4;

extern "C" Vec2f fn_27_27C7C(Self* self, u32 index) {
    ShapeArray* shapeArray = self->shapeArray;
    Vec2f out = { lbl_27_rodata_3C4, lbl_27_rodata_3C4 };

    u8 flags = ((u8*)shapeArray->at(index)->collStatus)[0x6d];

    if (flags & 8) {
        Vec2f p = self->fn154(index);
        u32 v = fn_80134534(self->shapeArray->at(index)->collStatus, 3);
        fn_80111DE4(&v, &p, &out.x);
    } else if (flags & 1) {
        Vec2f p = self->fn150(index);
        u32 v = fn_80134534(self->shapeArray->at(index)->collStatus, 0);
        fn_80111DE4(&v, &p, &out.x);
    } else if (flags & 2) {
        Vec2f p = self->fn158(index);
        u32 v = fn_80134534(self->shapeArray->at(index)->collStatus, 1);
        fn_80111DE4(&v, &p, &out.x);
    } else if (flags & 4) {
        Vec2f p = self->fn15c(index);
        u32 v = fn_80134534(self->shapeArray->at(index)->collStatus, 2);
        fn_80111DE4(&v, &p, &out.x);
    }

    return out;
}
