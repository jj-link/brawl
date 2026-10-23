#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class Pad4 {
public:
    u32 pad;
};

class Pad8 {
public:
    u32 pad[2];
};

class ObjA {
public:
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
    virtual int f17();
};

class ObjB {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void f5(int a, void* b);
};

class ObjD : public Pad8 {
public:
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
    virtual int f15();
};

class ObjF {
public:
    virtual void d0();
    virtual void d1();
    virtual u32* f4(int a);
};

class ObjC {
public:
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
    virtual void f20(int a);
};

class ObjE : public Pad8 {
public:
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
    virtual int f20(void* a, int b, u8 c, void* d);
};

class Lbl71C8 : public Pad4 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual int f8(void* a, int b, int c);
};

extern Lbl71C8 lbl_27_bss_71C8;
extern "C" int fn_27_28B340(char* self);
extern "C" int fn_27_28B4CC(char* self);

extern "C" int fn_27_28BBA8(char* self) {
    int r;
    char* t;
    ObjE* e;

    if ((u32)(*(u32*)(self + 0x3D34) + 0x10000) == 0xFFFF) {
        return 0;
    }
    r = ((ObjA*)(self + 0x1AA0))->f17();
    if (r & 0x10) {
        ((ObjB*)(self + 0x2C34))->f5(6, self + 0xCC);
        return 1;
    }
    if ((u32)(*(u32*)(self + 0x3D38) + 0x10000) != 0xFFFF && (r & 8)) {
        t = *(char**)(self + 0x60);
        t = *(char**)(t + 0xD8);
        t = *(char**)(t + 0xBC);
        if (((ObjD*)t)->f15() != 0 && fn_27_28B4CC(self) != 0) {
            return 1;
        }
        goto done;
    }
    if ((u32)(*(u32*)(self + 0x3D3C) + 0x10000) != 0xFFFF && (r & 4)) {
        if (*(u8*)(self + 0x3D41) != 0 &&
            ((Lbl71C8*)&lbl_27_bss_71C8)->f8(self + 0xCC, 0x5B73, 0) == 3 &&
            (*((ObjF*)(self + 0x297C))->f4(8) & 0x8000)) {
            ((ObjC*)(self + 0x2AAC))->f20(0x22000005);
            e = *(ObjE**)(self + 0x8D0);
            if (e->f20(self, *(int*)(self + 0x3D34), *(u8*)(self + 0x3D40), self + 0x3D44) != 0) {
                return 1;
            }
        }
        if (fn_27_28B340(self) != 0) {
            return 1;
        }
        goto done;
    }
    ((ObjC*)(self + 0x2AAC))->f20(0x22000005);
    e = *(ObjE**)(self + 0x8D0);
    if (e->f20(self, *(int*)(self + 0x3D34), *(u8*)(self + 0x3D40), self + 0x3D44) != 0) {
        return 1;
    }
done:
    return 0;
}
