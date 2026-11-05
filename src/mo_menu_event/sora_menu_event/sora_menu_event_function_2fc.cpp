#pragma force_active on
typedef unsigned char u8;

struct Pad3C {
    u8 pad[0x3C];
};

class VTask3C : public Pad3C {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};

struct Pad5C {
    u8 pad[0x5C];
};

class VObj5C : public Pad5C {
public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_9_data_1C0[];
void fn_9_2BC(void*, int);
void fn_800B8A0C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_9_2FC(u8* self, int deleting) {
    if (self) {
        *reinterpret_cast<void**>(self + 0x3C) = lbl_9_data_1C0;

        u8* cursor = self;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            u8* obj = *reinterpret_cast<u8**>(cursor + 0x17CC);
            if (obj) {
                reinterpret_cast<VTask3C*>(obj)->f23();
            }
        }

        if (*reinterpret_cast<void**>(self + 0x17C0)) {
            fn_800B8A0C(*reinterpret_cast<void**>(self + 0x17C0), 1);
        }

        cursor = self;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x198);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = self;
        for (int i = 0; i < 0x56; ++i, cursor += 4) {
            u8* obj = *reinterpret_cast<u8**>(cursor + 0x40);
            if (obj && obj) {
                reinterpret_cast<VObj5C*>(obj)->f0(1);
            }
        }

        __destroy_arr(self + 0x1B8, fn_9_2BC, 0xA8, 3);
        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
