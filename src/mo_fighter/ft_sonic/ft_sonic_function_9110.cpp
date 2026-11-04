#pragma force_active on

typedef unsigned int u32;

class Class_70AC {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12D4C();
    virtual void fn_123_14120();
    virtual void fn_123_14118();
    virtual void fn_123_14110();
    virtual void fn_123_14108();
    virtual void fn_123_14100();
    virtual void fn_123_140F8();
    virtual void fn_123_140F0();
    virtual void fn_123_140E8();
    virtual void fn_123_140E0();
    virtual void fn_123_140D8();
    virtual void fn_123_140D0();
    virtual void fn_123_140C8();
    virtual void fn_123_14078();
    virtual void fn_123_140C0();
    virtual int fn_123_140B0();
    virtual void fn_123_140A0();
    virtual void fn_123_14090(u32);
};

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

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFUl(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_123_data_2238[];
extern char lbl_123_data_2338[];

void fn_123_9110(void* self, void* event) {
    if (event == 0) {
        return;
    }
    Obj* obj = (Obj*)__dynamic_cast(
        getTask__15gfTaskSchedulerFUl(
            getInstance__15gfTaskSchedulerFv(),
            *(u32*)((char*)event + 0xc)),
        0x3c, lbl_123_data_2238, lbl_123_data_2338, 0);
    if (obj == 0 || obj->check() == 3) {
        return;
    }
    Class_70AC* status =
        *(Class_70AC**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xd8) + 0x70);
    if (status->fn_123_140B0() == 0x11e) {
        Class_70AC* work =
            *(Class_70AC**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xd8) + 0x64);
        work->fn_123_14090(0x22000011);
    }
}
}