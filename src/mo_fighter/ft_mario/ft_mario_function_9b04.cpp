#pragma force_active on

typedef int s32;
typedef float f32;
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
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual float n26(s32);
};

extern "C" void fn_27_135CE8(void*, s32, f32, s32, s32, f32, f32, s32);

extern "C" void fn_91_9B04(void* self, s32 a, f32 e, s32 b, s32 c, f32 f, f32 g, s32 d) {
    if (c == 2) {
        void* p1 = *(void**)((u8*)self + 0x60);
        void* p2 = *(void**)((u8*)p1 + 0xd8);
        QueryObj* q = *(QueryObj**)((u8*)p2 + 0x28);
        float result = q->n26(c);
        if (e >= result) {
            *(u8*)((u8*)self + 0x2DBD4) = 1;
            return;
        }
    }
    fn_27_135CE8(self, a, e, b, c, f, g, d);
}
