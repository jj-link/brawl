#pragma force_active on

typedef unsigned int u32;

struct ObjBase {
    char pad[0x3c];
};

struct Obj : ObjBase {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual int check();
};

struct Status {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
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
    virtual int kind();
};

struct Work {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void on(u32);
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFUl(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_122_data_8C98[];
extern char lbl_122_data_8D98[];

void fn_122_1FDAC(void* self, void* event) {
    if (event == 0) {
        return;
    }
    Obj* obj = (Obj*)__dynamic_cast(
        getTask__15gfTaskSchedulerFUl(
            getInstance__15gfTaskSchedulerFv(),
            *(u32*)((char*)event + 0xc)),
        0x3c, lbl_122_data_8C98, lbl_122_data_8D98, 0);
    if (obj == 0 || obj->check() == 3) {
        return;
    }
    Status* status =
        *(Status**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xd8) + 0x70);
    if (status->kind() == 1) {
        Work* work =
            *(Work**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xd8) + 0x64);
        work->on(0x22000000);
    }
}
}
