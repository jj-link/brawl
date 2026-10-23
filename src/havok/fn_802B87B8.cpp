#pragma force_active on

extern "C" void fn_802FCB14(void*);
extern "C" char lbl_80486CE8[];

struct Vtable_Class_802B87B8 {
    void* vtable;
    Vtable_Class_802B87B8() : vtable(lbl_80486CE8) {}
};

class Class_802A0DC4 : public Vtable_Class_802B87B8 {
public:
    char pad[8];
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

class Class_802A9A5C {
public:
    char pad[12];
    Class_802A9A5C() {}
    ~Class_802A9A5C() {}
};

class Class_802B87B8 : public Class_802A0DC4 {
public:
    Class_802B87B8(int, int, int, int);
    int field_c;
    Class_802A9A5C m_10;
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

Class_802B87B8::Class_802B87B8(int a0, int a1, int a2, int a3) {
    char* s = (char*)this;
    char* t = s + 0x10;
    *(short*)(s + 0x6) = 1;
    *(int*)(s + 0x8) = a3;
    *(void**)s = lbl_80486CE8;
    *(char**)t = t + 0xc;
    *(int*)(t + 0x4) = 0;
    *(unsigned int*)(t + 0x8) = 0x80000001;
    *(int*)(s + 0xc) = *(int*)a2;
    if (t != 0) {
        *(char**)t = t + 0xc;
        *(int*)(t + 0x4) = 0;
        *(unsigned int*)(t + 0x8) = 0x80000001;
    }
    fn_802FCB14(s + 0x10);
}
