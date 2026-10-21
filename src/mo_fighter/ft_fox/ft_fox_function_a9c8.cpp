#pragma force_active on

extern "C" void fn_27_135CE8(void*, int, float, int, int, float, float, int);

struct FoxQueryObj {
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

struct FoxObjB {
    unsigned char pad[0x28];
    FoxQueryObj* ptrC;
};

struct FoxObjA {
    unsigned char pad[0xD8];
    FoxObjB* ptrB;
};

extern "C" void fn_97_A9C8(void* self, int arg1, float farg0, int arg2, int arg3, float farg1, float farg2, int arg4) {
    if (arg3 == 2) {
        FoxObjA* a = *(FoxObjA**)((unsigned char*)self + 0x60);
        FoxObjB* b = a->ptrB;
        FoxQueryObj* q = b->ptrC;
        float result = q->n26(arg3);
        if (farg0 >= result) {
            *((unsigned char*)self + 0x1CD45) = 1;
            return;
        }
        *((unsigned char*)self + 0x1CD44) = 1;
    }
    fn_27_135CE8(self, arg1, farg0, arg2, arg3, farg1, farg2, arg4);
}
