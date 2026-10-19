#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Words3 { u32 x, y, z; };
struct Words2 { u32 x, y; };

struct Record {
    float f00, f04, f08, f0C;
    Words3 w10;
    u32 w1C;
    Words3 w20;
    u16 h2C, h2E;
    u8 b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3A;
    u32 w3C;
    Words3 w40;
    float f4C;
    u32 w50, w54, w58, w5C;
    float f60, f64, f68;
    u32 w6C, w70, w74, w78;
    float f7C;
    Words3 w80;
    Words2 w8C;
    float f94;
    u32 w98;
    u8 b9C;
};

class Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual Record* get(int);
};

extern "C" void fn_71_AEA4(Object* self, int sourceIndex, int destinationIndex) {
    Record* source = self->get(sourceIndex);
    Record* destination = self->get(destinationIndex);
    *destination = *source;
}
