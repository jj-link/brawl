#pragma force_active on
typedef unsigned int u32;

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_1DA698(void*, int, int, int);
extern "C" extern const char lbl_27_data_248[];
extern "C" extern const char lbl_27_data_2D0F0[];

class IA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int m4(u32 a, void* b);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int m17(u32 a);
};

class IB {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void a64();
    virtual void a65();
    virtual void a66();
    virtual void a67();
    virtual void a68();
    virtual void a69();
    virtual void a70();
    virtual void a71();
    virtual void a72();
    virtual void a73();
    virtual void a74();
    virtual void a75();
    virtual void a76();
    virtual void a77();
    virtual void a78();
    virtual void a79();
    virtual void a80();
    virtual void a81();
    virtual void a82();
    virtual void a83();
    virtual void a84();
    virtual void a85();
    virtual void a86();
    virtual void b87(int a);
};

struct Holder {
    char pad[0x54];
    IB* b54;
    char pad2[0x64 - 0x58];
    IA* a64;
};

struct Ft {
    char pad[0x8];
    void* p8;
    char pad2[0xd8 - 0xc];
    Holder* hd8;
};

extern "C" void fn_27_1DEDC8(void*, Ft* p, int arg) {
    IA* a = p->hd8->a64;
    if (a->m17(0x22000005)) {
        Holder* h = p->hd8;
        IA* a2 = h->a64;
        if (arg == a2->m4(0x20000001, p->hd8)) {
            p->hd8->b54->b87(1);
            fn_27_1DA698(__dynamic_cast(p->p8, 0x3c, lbl_27_data_2D0F0, lbl_27_data_248, 1), -1, -1, -1);
        }
    }
}
