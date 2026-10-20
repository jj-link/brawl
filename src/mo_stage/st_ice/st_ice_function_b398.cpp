#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Words3 {
    u32 x, y, z;
};

struct Words2 {
    u32 x, y;
};

struct Data {
    float f00, f04, f08, f0c;
    Words3 w10;
    u32 w1c;
    Words3 w20;
    u16 h2c, h2e;
    u8 b30, b31, b32, b33, b34, b35;
    u8 b36, b37, b38, b39, b3a;
    u32 w3c;
    Words3 w40;
    float f4c;
    u32 w50, w54, w58, w5c;
    float f60, f64, f68;
    u32 w6c, w70, w74, w78;
    float f7c;
    Words3 w80;
    Words2 w8c;
    float f94;
    u32 w98;
    u8 b9c;
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual Data* get(int);
};

extern "C" void fn_62_B398(Object* self, int from, int to) {
    Data* src = self->get(from);
    Data* dst = self->get(to);
    *dst = *src;
}
