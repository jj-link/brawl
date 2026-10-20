#pragma force_active on
typedef unsigned long u32;

extern "C" float fn_27_192278(void* self, unsigned long arg);

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(u32 x);
};

extern "C" void fn_27_3C6ED0(void* r3, void* self, int frame) {
    switch (frame) {
    case 0x19:
        fn_27_192278(self, 0xfc5);
        void* p = *(void**)((char*)self + 0xd8);
        VObj* q = *(VObj**)((char*)p + 0x64);
        q->v13(0x11000000);
        break;
    }
}
