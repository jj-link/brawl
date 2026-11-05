#pragma force_active on

extern "C" float fn_800F238C(void* self, int n);

extern float lbl_805A25E8;
extern float lbl_805A25EC;
extern float lbl_805A25F0;
extern float lbl_805A25F4;

class VObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual float m6(void* arg);
};

extern "C" void fn_800F2498(void* self) {
    char* s = (char*)self;
    void* a = *(void**)(s + 0x48);
    void* b = *(void**)((char*)a + 0x14);
    VObj* c = *(VObj**)((char*)b + 0x0c);
    float f = c->m6(a);

    int val = *(int*)(s + 0x70);
    switch (val) {
        case 1:
            if (f >= lbl_805A25E8) {
                fn_800F238C(self, 2);
            }
            break;
        case 3:
            if (f >= lbl_805A25EC) {
                fn_800F238C(self, 4);
            }
            break;
        case 6:
            if (f >= lbl_805A25F0) {
                fn_800F238C(self, 7);
            }
            break;
        case 8:
            if (f >= lbl_805A25F4) {
                fn_800F238C(self, 9);
            }
            break;
        case 9:
            break;
    }
}