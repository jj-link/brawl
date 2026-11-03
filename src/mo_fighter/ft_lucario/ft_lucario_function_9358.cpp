#pragma force_active on

typedef unsigned char u8;

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
    virtual void n18(int);
    virtual void n19();
    virtual void n20(int);
};

extern "C" void fn_27_135848(void*, int, float, int, int, float, float, void*);

extern "C" void fn_118_9358(void* self, int a, float b, int c, int d, float e, float f, void* g) {
    if (d == 1) {
        void* p1 = *(void**)((u8*)g + 0xd8);
        QueryObj* q = *(QueryObj**)((u8*)p1 + 0x64);
        q->n18(0x22000010);
    }
    fn_27_135848(self, a, b, c, d, e, f, g);
}
