#pragma force_active on

extern "C" void fn_27_135CE8(void*, int, float, int, int, float, float, int);

struct KirbyVirtual {
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

struct KirbyB {
    unsigned char pad[0x28];
    KirbyVirtual* virt;
};

struct KirbyA {
    unsigned char pad[0xD8];
    KirbyB* b;
};

struct Self {
    unsigned char pad[0x60];
    KirbyA* a;
};

extern "C" void fn_96_DEC4(void* self, int a1, float f1, int a2, int a3, float f2, float f3, int a4) {
    if (a3 == 2) {
        Self* s = static_cast<Self*>(self);
        KirbyVirtual* c = s->a->b->virt;
        float result = c->n26(a3);
        if (f1 >= result) {
            *(unsigned char*)((unsigned char*)self + 0x1B68D) = 1;
            return;
        }
        *(unsigned char*)((unsigned char*)self + 0x1B68C) = 1;
    }
    fn_27_135CE8(self, a1, f1, a2, a3, f2, f3, a4);
}
