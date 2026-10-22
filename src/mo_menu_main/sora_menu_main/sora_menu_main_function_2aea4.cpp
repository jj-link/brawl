#pragma force_active on
extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned int, unsigned int, unsigned int);
void allocMsgBuf__5MuMsgFUlUl(void*, unsigned int, unsigned int);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, unsigned int, void*, unsigned int, float);
void getWScale__5MuMsgFUlf(void*, unsigned int, float);
void printIndex__5MuMsgFUlUlPv(void*, unsigned int, unsigned int, void*);
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, unsigned long long, short);
void* fn_16_1EA0(void*, int, void*, void*, void*, int, int, int, int, int, int, int);
extern float lbl_2_rodata_EE8;
extern float lbl_2_rodata_EEC;
extern unsigned char lbl_2_data_19A0[];
extern unsigned char lbl_2_data_19D0[];

struct Fl { unsigned char b0 : 1; unsigned char rest : 7; };
struct Base { char pad[0x3c]; };
struct O : Base {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void f64(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void f74(int, int);
};

void fn_2_2AEA4(char* self, void* arg) {
    int a[4];
    int b[2];
    *(void**)(self + 0x654) = arg;
    *(int*)(self + 0x670) = 0;
    ((Fl*)(self + 0x66c))->b0 = 0;
    *(short*)(self + 0x710) = 0;
    *(short*)(self + 0x712) = 0;
    *(void**)(self + 0x71c) = 0;
    *(unsigned char*)(self + 0x724) = 0;
    (*(O**)(self + 0x658))->f74(0x10, 0x28);
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *(void**)(self + 0x674) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 1);
    setMsgData__5MuMsgFPv(*(void**)(self + 0x674), *(void**)(self + 0x678));
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        *(void**)(self + 0x674), 0,
        *(void**)(*(char**)(*(char**)(self + 0x64c) + 0x2b4) + 0x10),
        0, lbl_2_rodata_EE8);
    getWScale__5MuMsgFUlf(*(void**)(self + 0x674), 0, lbl_2_rodata_EEC);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x674), 0, 0x2b, 0);
    a[0] = *(int*)(*(char**)(self + 0x64c) + 0x2a8);
    a[1] = *(int*)(*(char**)(self + 0x64c) + 0x2ac);
    a[2] = *(int*)(*(char**)(self + 0x64c) + 0x2b0);
    a[3] = *(int*)(*(char**)(self + 0x64c) + 0x2b8);
    b[0] = *(int*)(*(char**)(self + 0x650) + 0x54);
    b[1] = *(int*)(*(char**)(self + 0x650) + 0x58);
    char* m = (char*)getInstance__14gfSceneManagerFv();
    unsigned long long types = ((unsigned long long)(unsigned int)lbl_2_data_19A0 << 32) | (unsigned int)lbl_2_data_19D0;
    char* s = (char*)__dynamic_cast(*(void**)(m + 4), 4, types, 0);
    O* old = *(O**)(self + 0x71c);
    if (old) {
        old->f64();
        *(void**)(self + 0x71c) = 0;
    }
    *(void**)(self + 0x71c) = fn_16_1EA0(arg, 1, a, b, s + 0xa98, 0xf0, 0x19, 0, 0,
        *(int*)(self + 0x728), *(int*)(self + 0x730), *(int*)(self + 0x72c));
    *(int*)(self + 0x664) = 0;
}
}
