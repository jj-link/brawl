#pragma force_active on

typedef unsigned char u8;
typedef signed long s32;

extern "C" {
extern const float lbl_27_rodata_2754;
extern const float lbl_27_rodata_2758;
}

struct Inner {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual float getValue();
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
    virtual void set(void*);
};

struct Node {
    unsigned char pad[8];
    Inner* object;
};

struct Mid {
    unsigned char pad[0xD8];
    Node* node;
};

struct Root {
    unsigned char pad[0x60];
    Mid* mid;
};

struct Record {
    s32 value;
    float x;
    float y;
    u8 a, b, c, d;
};

extern "C" void fn_27_1DA444(Root* arg0, s32 arg1, u8 arg2)
{
    float x;
    if (arg2 == 1)
        x = arg0->mid->node->object->getValue();
    else
        x = lbl_27_rodata_2754;

    Record rec;
    rec.value = arg1;
    rec.x = x;
    rec.y = lbl_27_rodata_2758;
    rec.a = 0;
    rec.b = 0;
    rec.c = arg2;
    rec.d = 0;
    arg0->mid->node->object->set(&rec);
}
