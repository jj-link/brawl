#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_122_27124(void* self);
void fn_27_1A5384(void* h, int x);
void fn_27_1A53A8(void* h, short x);
extern char lbl_122_data_FFB4[];
extern char lbl_122_data_8554[];
}

struct VObj {
    virtual void s0();
    virtual void* s1(int);
    virtual void s2();
    virtual int s3();
    virtual int s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(void*);
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26(void*, int, int);
};

struct Handle {
    char storage[0x20];
};

extern "C" void fn_122_22D9C(char* self) {
    Handle h;
    unsigned int sp8;

    fn_27_1A5384(&h, 0);
    VObj* o = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x84);
    o->s26(&h, 0, 2);

    if (((VObj*)&h)->s4() == 0) {
        void** rp = (void**)((VObj*)&h)->s1(0);
        void* p = __dynamic_cast(*rp, 0, lbl_122_data_FFB4, lbl_122_data_8554, 0);
        if (p == 0) {
            fn_27_1A53A8(&h, -1);
            return;
        }
        fn_122_27124(p);
        int r30 = 1;
        int r29 = 0;
        while (r29 < ((VObj*)(self + 0x67B0))->s3()) {
            void** e = (void**)((VObj*)(self + 0x67B0))->s1(r29);
            if ((unsigned int)(unsigned long)*e == *(unsigned int*)((char*)p + 0x28)) {
                r30 = 0;
            }
            r29++;
        }
        if (r30 != 0) {
            sp8 = *(unsigned int*)((char*)p + 0x28);
            ((VObj*)(self + 0x67B0))->s10(&sp8);
        }
    }

    fn_27_1A53A8(&h, -1);
}
