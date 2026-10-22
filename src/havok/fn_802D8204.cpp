#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, u16, int);
};
extern "C" {
extern char lbl_804878C8[];
extern char lbl_80487B10[];
extern SoHeapAllocator* lbl_805A0EB8;
extern void* lbl_805A0EC8;
void fn_802F8F98(void*, void*, int);
void fn_802DE7E0(void*, int);
void fn_802DA2B4(void*);
void fn_8027EABC(void*, void*, u32, int);
}
struct Array {
    void* data;
    int size;
    u32 raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw & 0x3fffffff, 0x15); }
    ~Array() { if (isOwned()) dealloc(); }
};
struct Array1 : Array { ~Array1() {} };
struct Array2 : Array1 { ~Array2() {} };
struct Obj {
    void* vt;
    u16 type;
    char pad[0x16];
    Array2 a;
};
extern "C" void* fn_802D8204(void* self, int flag) {
    char* s = (char*)self;
    if (s) {
        *(void**)s = lbl_804878C8;
        if (*(u16*)(*(char**)(s + 0x3c) + 4) != 0)
            fn_802F8F98(*(void**)(s + 8), s + 0x40, 1);
        *(u32*)(s + 0x54) = 0;
        *(u32*)(s + 0x58) = 0;
        *(u32*)(s + 0x4c) = 0;
        fn_802DE7E0(s + 0x40, -1);
        if (s + 0x10) {
            Obj* o = (Obj*)s;
            *(void**)(s + 0x10) = lbl_80487B10;
            if (*(void**)(s + 0x3c))
                fn_802DA2B4(*(void**)(s + 0x3c));
            o->a.~Array2();
        }
        if (flag > 0)
            lbl_805A0EB8->free(s, *(u16*)(s + 4), 0x20);
    }
    return self;
}
