#pragma force_active on

extern "C" void fn_27_135CE8(void*, int, float, int, int, float, float, int);

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
    virtual float n26(int);
};

struct ObjB {
    unsigned char pad[0x28];
    QueryObj* obj;
};

struct ObjA {
    unsigned char pad[0xD8];
    ObjB* b;
};

struct Self {
    unsigned char pad[0x60];
    ObjA* a;
};

extern "C" void fn_108_A888(void* self, int arg1, float f1, int arg2, int arg3, float f2, float f3, int arg4) {
    if (arg3 == 2) {
        Self* s = static_cast<Self*>(self);
        float result = s->a->b->obj->n26(arg3);
        if (f1 >= result) {
            *(reinterpret_cast<unsigned char*>(self) + 0x1D091) = 1;
            return;
        }
        *(reinterpret_cast<unsigned char*>(self) + 0x1D090) = 1;
    }
    fn_27_135CE8(self, arg1, f1, arg2, arg3, f2, f3, arg4);
}
