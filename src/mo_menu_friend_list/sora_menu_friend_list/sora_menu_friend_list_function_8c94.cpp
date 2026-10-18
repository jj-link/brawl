#pragma force_active on
extern "C" {
int fn_14_3424(void* self, int b);
int fn_800B5854(void* p, int a, int b, int c, int d);
void fn_14_A18(void* self);
unsigned char* fn_14_3EC();
void fn_80147434();
}

class VObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(int) = 0;
};

extern "C" void fn_14_8C94(void* self) {
    unsigned char* s = (unsigned char*)self;
    fn_14_3424(self, 4);
    fn_800B5854(*(void**)(s + 0x8c), 1, 3, 1, 0);
    fn_800B5854(*(void**)(s + 0xc4), 1, 3, 1, 0);
    ((VObj*)*(void**)(s + 0x204))->v13(*(int*)(s + 0x1e8));
    if (s[0x40] == 0) {
        fn_14_A18(self);
        unsigned char* p = fn_14_3EC();
        p[0xfca] &= ~0x10;
        fn_80147434();
    }
}
