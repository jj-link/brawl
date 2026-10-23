#pragma force_active on
#pragma optimization_level 2
#pragma use_lmw_stmw on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(unsigned int, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_802A1FD4 {
public:
    static void operator delete(void* p);

    static void* operator new(unsigned long size) {
        void* p = lbl_805A0EB8->alloc(size, 0x1d);
        ((unsigned short*)p)[2] = 0x38;
        return p;
    }
};

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
};

class Class_802BAE28 {
public:
    Class_802BAE28() {}
};

extern "C" char lbl_80486DEC[];
extern "C" char lbl_80486DB0[];

struct Vtable_Class_802BAEB8 {
    void* vtable;
    unsigned short m4;
    char pad[0x2e];

    Vtable_Class_802BAEB8() : vtable(lbl_80486DEC) {}
    Vtable_Class_802BAEB8(int) {}
};

class Class_802BAEB8;

extern "C" void __ct__14Class_802BAEB8Fiiii(
    Class_802BAEB8*, int, int, int, int);

class Class_802BAEB8 : public Vtable_Class_802BAEB8,
                      public Class_802A1FD4,
                      public Class_802A0DC4 {
public:
    Class_802BAEB8(int a, int b, int c, int d)
        : Vtable_Class_802BAEB8(0) {
        __ct__14Class_802BAEB8Fiiii(this, b, a, c, d);
        vtable = lbl_80486DB0;
    }

    Class_802BAE28 m_C;
};

extern "C" Class_802BAEB8* fn_802BAD0C(int a, int b, int c, int d) {
    Class_802BAEB8* object0 = new Class_802BAEB8(a, b, c, d);
    return object0;
}
