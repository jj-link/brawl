#pragma force_active on
#include <mt/mt_vector.h>

typedef float f32;

extern "C" {
    extern const f32 lbl_27_rodata_910[];
    void fn_8003E3BC(const f32*, const f32*, f32*);
}

struct Pad8 {
    char pad[8];
};

class MatrixRequest : public Pad8 {
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
    virtual void request(u32, f32*, u32);
};

class CurrentValue {
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
    virtual f32 get();
    virtual void slot10();
    virtual void update();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void notify();
};

struct Modules {
    unsigned char pad0[4];
    MatrixRequest* request;
    unsigned char pad1[4];
    CurrentValue* value;
};

struct Outer {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Object {
    unsigned char pad0[0x10];
    Outer* outer;
    unsigned char pad1[8];
    u32 requestArg;
    unsigned char pad2[13];
    unsigned char flag;
};

struct LocalData {
    Vec2f factors;
    Vec2f coords;
    Vec3f input;
    Vec3f output;
    f32 matrix[12];
};

extern "C" void fn_27_66CBC(Object* self) {
    f32* lbl = (f32*)lbl_27_rodata_910;

    if (self->flag == 1) {
        LocalData data;

        self->outer->modules->request->request(
            self->requestArg, data.matrix, 0);

        data.output.m_x = lbl[0];
        data.output.m_y = lbl[0];
        data.output.m_z = lbl[0];
        data.input.m_x = lbl[0];
        data.input.m_y = lbl[0];
        data.input.m_z = lbl[1];

        fn_8003E3BC(data.matrix, &data.input.m_x, &data.output.m_x);

        f32 y = data.output.m_y;
        data.coords.m_x = data.output.m_x;
        data.coords.m_y = y;
        data.factors.m_x = lbl[1];
        data.factors.m_y = lbl[0];

        f32 x = data.coords.m_x;
        f32 sum = lbl[1] * x + lbl[0] * y;
        f32 candidate = lbl[2];

        if (sum >= lbl[3])
            candidate = lbl[1];

        if (candidate != self->outer->modules->value->get()) {
            self->outer->modules->value->update();
            self->outer->modules->value->notify();
        }
    }
}
