#pragma force_active on
// fn_67_5F3C: copies a 0xA0-byte Param record from the object returned by
// virtual slot 0x70 (called with no arguments) into the object returned by
// the same slot when called with the data argument.
// Member names are placeholders named by byte offset.
// The second parameter (r4) is never read.
// Note: st_palutena_function_8ca8.cpp declares this function with a single
// void* parameter, which is narrower than the signature used here.

struct Pair {
    unsigned int a;
    unsigned int b;
};

struct Param {
    float m00;
    float m04;
    float m08;
    float m0C;
    Pair m10;
    unsigned int m18;
    unsigned int m1C;
    Pair m20;
    unsigned int m28;
    unsigned short m2C;
    unsigned short m2E;
    unsigned char m30;
    unsigned char m31;
    unsigned char m32;
    unsigned char m33;
    unsigned char m34;
    unsigned char m35;
    unsigned char m36;
    unsigned char m37;
    unsigned char m38;
    unsigned char m39;
    unsigned char m3A;
    unsigned int m3C;
    Pair m40;
    unsigned int m48;
    float m4C;
    unsigned int m50;
    unsigned int m54;
    unsigned int m58;
    unsigned int m5C;
    float m60;
    float m64;
    float m68;
    unsigned int m6C;
    unsigned int m70;
    unsigned int m74;
    unsigned int m78;
    float m7C;
    Pair m80;
    unsigned int m88;
    Pair m8C;
    float m94;
    unsigned int m98;
    unsigned char m9C;
};

// 26 dummy slots place getSrc/getDst at vtable offset 0x70 under this compiler.
struct VtBase {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
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
};

struct VtGet : VtBase {
    virtual Param* getSrc();
};

struct VtSet : VtBase {
    virtual Param* getDst(Param* p);
};

extern "C" void fn_67_5F3C(void* self, void* unused, Param* p) {
    Param* src = reinterpret_cast<VtGet*>(self)->getSrc();
    Param* dst = reinterpret_cast<VtSet*>(self)->getDst(p);
    *dst = *src;
}
