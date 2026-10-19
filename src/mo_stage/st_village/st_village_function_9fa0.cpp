#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Data {
    float f00;
    float f04;
    float f08;
    float f0c;
    Pair p10;
    int i18;
    int i1c;
    Pair p20;
    int i28;
    unsigned short h2c;
    unsigned short h2e;
    unsigned char b30;
    unsigned char b31;
    unsigned char b32;
    unsigned char b33;
    unsigned char b34;
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    int i3c;
    Pair p40;
    int i48;
    float f4c;
    int i50;
    int i54;
    int i58;
    int i5c;
    float f60;
    float f64;
    float f68;
    int i6c;
    int i70;
    int i74;
    int i78;
    float f7c;
    Pair p80;
    int i88;
    Pair p8c;
    float f94;
    int i98;
    unsigned char b9c;
};

class Village {
public:
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
    virtual Data* getData(unsigned int index);
};

extern "C" void fn_70_9FA0(Village* self, unsigned int srcIndex, unsigned int dstIndex) {
    Data* src = self->getData(srcIndex);
    Data* dst = self->getData(dstIndex);
    *dst = *src;
}
