#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_106_DADC(void*, unsigned int);
void* getTask__6gfTaskFi(int);
extern const char lbl_106_data_28[];
extern const char lbl_106_data_18F0[];
}

struct VA {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(int);
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
};

extern "C" void fn_106_7A10(char* self) {
    char* p = *(char**)(self + 0x60);
    VA* a = *(VA**)(*(char**)(p + 0xd8) + 0x70);
    if (a->s16() == 0x120) {
        VA* b = *(VA**)(*(char**)(p + 0xd8) + 0x64);
        int n = b->s4(0x20000016);
        if (n > 0) {
            int i = 0;
            while (i < n) {
                VA* c = *(VA**)(*(char**)(p + 0xd8) + 0x64);
                void* t = getTask__6gfTaskFi(c->s4(0x20000004 + i));
                void* r = __dynamic_cast(t, 0x3c, lbl_106_data_28, lbl_106_data_18F0, 0);
                if (r != 0) {
                    fn_106_DADC(r, 1);
                }
                i++;
            }
        }
    }
}
