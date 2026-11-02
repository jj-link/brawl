#pragma force_active on
#pragma use_lmw_stmw on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" void __ct__14Class_802B87B8Fiiii(void*, int, int, int, int);

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
    static void* operator new(unsigned long size) {
        void* p = lbl_805A0EB8->alloc(size, 0x1d);
        ((short*)p)[2] = size;
        return p;
    }
};

class Class_802B87B8 : public Class_802A1FD4 {
public:
    void* m_00;
    unsigned short m_04;
    unsigned char pad_06[0x1A];

    Class_802B87B8(int a, int b, int c, int d) {
        __ct__14Class_802B87B8Fiiii(this, a, b, c, d);
    }
};

extern "C" void* fn_802B873C(int a, int b, int c, int d) {
    Class_802B87B8* obj = new Class_802B87B8(a, b, c, d);
    return obj;
}
