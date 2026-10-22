#pragma force_active on

struct NessQueryObj {
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual float n26(int);
};

struct NessMid {
    unsigned char pad[0x28];
    NessQueryObj* obj;
};

struct NessOuter {
    unsigned char pad[0xd8];
    NessMid* mid;
};

struct NessReal {
    unsigned char pad0[0x60];
    NessOuter* outer;
};

extern "C" void fn_27_135CE8(void* self, int a, float b, int c, int d, float e, float f, int g);

extern "C" void fn_101_BF64(void* self, int a, float b, int c, int d, float e, float f, int g) {
    if (d == 2) {
        NessReal* s = static_cast<NessReal*>(self);
        float r = s->outer->mid->obj->n26(d);
        if (b >= r) {
            *(reinterpret_cast<unsigned char*>(self) + 0x4AE25) = 1;
            return;
        }
        *(reinterpret_cast<unsigned char*>(self) + 0x4AE24) = 1;
    }
    fn_27_135CE8(self, a, b, c, d, e, f, g);
}
