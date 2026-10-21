#pragma force_active on
typedef unsigned char u8;

struct VObj {
    virtual void s2() {}
    virtual void s3() {}
    virtual void m4(int, int);
    virtual void s5() {}
    virtual void s6() {}
    virtual void s7() {}
    virtual void s8() {}
    virtual void s9() {}
    virtual void s10() {}
    virtual void s11() {}
    virtual int m12(int);
    virtual void s13() {}
    virtual void s14() {}
    virtual void s15() {}
    virtual unsigned int m16(int);
};

extern "C" void fn_27_13138C(void*, int, int, void*, void*);

extern "C" void fn_112_9F64(void* a, int b, int c, void* d, void* self) {
    fn_27_13138C(a, b, c, d, self);

    VObj* sub = *(VObj**)((u8*)*(void**)((u8*)self + 0xd8) + 0xa8);
    if (sub->m16(0) == 1) {
        VObj* obj = *(VObj**)((u8*)*(void**)((u8*)self + 0xd8) + 0x58);
        if (obj->m12(1) != 3) {
            obj->m4(1, 2);
        }
    }
}
