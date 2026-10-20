#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800E5858(void*);
extern "C" void fn_800E5E34(void*, void*);
extern "C" void* lbl_27_bss_5668;

class ObjBase {
public:
    u8 data[0x3c];
};

class Obj : public ObjBase {
public:
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void init();
};

extern "C" void fn_27_250EC8(void* self) {
    u8* base = (u8*)self;
    Obj* m_obj = *(Obj**)(base + 0xcc);
    if (m_obj == 0) {
        Obj* p = static_cast<Obj*>(__nw__FUlQ25Heaps8HeapType(0x44ac, 0x2a));
        if (p != 0) {
            p = static_cast<Obj*>(fn_800E5858(p));
        }
        p->init();
        *(Obj**)(base + 0xcc) = p;
        fn_800E5E34(p, *(void**)((char*)lbl_27_bss_5668 + 0x1a0));
    }
}
