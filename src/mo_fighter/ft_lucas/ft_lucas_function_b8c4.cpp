#pragma force_active on
struct QueryObj {
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
    virtual float n28(int c);
};

struct MidObj {
    unsigned char pad[0x28];
    QueryObj* obj;
};

struct OuterObj {
    unsigned char pad[0xd8];
    MidObj* mid;
};

struct SelfObj {
    unsigned char pad[0x60];
    OuterObj* outer;
};

extern "C" void fn_27_135CE8(void* self, int a, float e, int b, int c, float f, float g, int d);

extern "C" void fn_114_B8C4(void* self, int a, float e, int b, int c, float f, float g, int d) {
    if (c == 2) {
        SelfObj* s = static_cast<SelfObj*>(self);
        float r = s->outer->mid->obj->n28(c);
        if (e >= r) {
            *(reinterpret_cast<unsigned char*>(self) + 0x50000 - 0x733b) = 1;
            return;
        }
        *(reinterpret_cast<unsigned char*>(self) + 0x50000 - 0x733c) = 1;
    }
    fn_27_135CE8(self, a, e, b, c, f, g, d);
}
