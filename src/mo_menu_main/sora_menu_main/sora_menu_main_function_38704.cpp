#pragma force_active on
typedef unsigned char u8;

class SubBase5C {
public:
    u8 pad[0x5C];
};

class Entry : public SubBase5C {
public:
    virtual ~Entry();
};

class SubBase3C {
public:
    u8 pad[0x3C];
};

class MenuCtrl : public SubBase3C {
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
    virtual void f24();
    virtual void f25();
};

extern "C" {
extern u8 lbl_2_data_4C90[];

void fn_16_AF8(void*);
void fn_800B8A0C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_2_38704(u8* self, int deleting)
{
    if (self) {
        *reinterpret_cast<void**>(self + 0x3C) = lbl_2_data_4C90;

        fn_16_AF8(self + 0x14C);

        void* obj = *reinterpret_cast<void**>(self + 0x1E4);
        if (obj) {
            reinterpret_cast<MenuCtrl*>(obj)->f23();
        }

        if (*reinterpret_cast<void**>(self + 0x74)) {
            fn_800B8A0C(*reinterpret_cast<void**>(self + 0x74), 1);
        }

        if (*reinterpret_cast<void**>(self + 0x6C)) {
            Destroy__Q34nw4r3g3d6G3dObjFv(*reinterpret_cast<void**>(self + 0x6C));
        }

        u8* cursor = self;
        for (int i = 0; i < 10; ++i, cursor += 4) {
            Entry* entry = *reinterpret_cast<Entry**>(cursor + 0x44);
            if (entry) {
                delete entry;
            }
        }

        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
