#pragma force_active on

typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

class Part {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void fn4(int, int);
    Flags* data;
    u32 state;
};

struct Obj {
    Obj(const char* name);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    u32 f158;
    u32 f15c;
    u32 f160;
    float f164;
    float f168;
    float f16c;
    unsigned char f170;
};

namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void fn_48_1F28(void*, const char*);
extern char lbl_48_data_3218[];
extern const float lbl_48_rodata_A8;

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35();
    virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(int); virtual void f43();
    virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47();
    virtual void f48(); virtual void f49(); virtual void f50(); virtual void f51();
    virtual void f52(); virtual void f53(); virtual void f54(); virtual void f55();
    virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
    virtual void f60(); virtual void f61(); virtual void f62(); virtual void f63();
    virtual void f64(); virtual void f65(); virtual void f66(); virtual void f67();
    virtual void f68(); virtual void f69(); virtual void f70(); virtual void f71();
    virtual void f72(); virtual void f73(); virtual void f74(); virtual void f75();
    virtual void f76(); virtual void f77(); virtual void f78(const char*);
};

inline Obj::Obj(const char* name) {
    fn_48_1F28(this, name);
    vtable = lbl_48_data_3218;
    f158 = 0;
    f15c = 0;
    f160 = 0;
    f164 = lbl_48_rodata_A8;
    f168 = lbl_48_rodata_A8;
    f16c = lbl_48_rodata_A8;
    f170 = 0;
    Part* p = (Part*)part;
    if (!p)
        return;
    p->state = 1;
    p->fn4(0, 15);
    p->data->flags |= 1;
}

extern "C" Obj* fn_48_C28C(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Object_vptr_3c*)obj)->f42(arg0);
        ((Object_vptr_3c*)obj)->f78(arg1);
    }
    return obj;
}