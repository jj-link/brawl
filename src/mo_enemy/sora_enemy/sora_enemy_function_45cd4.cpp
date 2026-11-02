#pragma force_active on
typedef unsigned char u8;

extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
extern "C" void setProcFnc_LifeZero__10wnemSimpleFl(void*, long);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
extern "C" void changeProcFnc__10wnemSimpleFll(void*, long, long);

struct VBase7 {
    virtual int c0();
    virtual int c1();
    virtual int c2();
    virtual int c3();
    virtual int c4();
    virtual int c5();
    virtual int c6(int, int);
};

extern "C" void fn_41_45CD4(void* a, void* b) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;
    if (x) {
        setProcFnc_TouchGround__10wnemSimpleFl(a, 0x13);
        setProcFnc_LifeZero__10wnemSimpleFl(a, 0x13);
        void* c = *(void**)((char*)b + 0xD8);
        void* d = *(void**)((char*)c + 0x14);
        ((VBase7*)d)->c6(2, 1);
        executeAnimCmd__10wnemSimpleFUl(a, 5);
        executeAnimCmd__10wnemSimpleFUl(a, 6);
    }
    u8 y = *((u8*)a + 0x2218);
    if (y) {
        changeProcFnc__10wnemSimpleFll(a, 0x13, 1);
    }
}
