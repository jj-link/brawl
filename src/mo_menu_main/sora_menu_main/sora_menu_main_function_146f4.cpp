#include <gm/gm_global.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
void fn_18_1C4C(void*, int);
void fn_800557C0();
int fn_800557D8();
void fn_8005A0E4(int);
}
extern char lbl_2_data_1C78[];
extern char lbl_2_data_1CE8[];

#define PTR(p, o) (*reinterpret_cast<void**>(reinterpret_cast<char*>(p) + (o)))
#define INT(p, o) (*reinterpret_cast<int*>(reinterpret_cast<char*>(p) + (o)))
#define U16(p, o) (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + (o)))

struct Scene {
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
    virtual void attach(void*, void*);
    char pad4[0xE0];
    void* root;
};
struct Control {
    char pad[0x3C];
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
    virtual void f26();
    virtual void set(int, int);
};
struct Menu { char pad[0x42]; unsigned short selection; };
struct Table { int value[7]; };
extern const Table lbl_2_rodata_558;

extern "C" void fn_2_146F4(Menu* self, Scene* scene, int mode) {
    unsigned int off;
    unsigned int i;
    PTR(self, 0x63C) = lbl_2_data_1C78;
    PTR(self, 0x654) = scene;
    PTR(self, 0x648) = lbl_2_data_1CE8;
    INT(self, 0x644) = 0x1D;
    i = 0;
    off = 0;
    do {
        void* p = PTR(reinterpret_cast<char*>(PTR(self, 0x64C)) + off, 0x74);
        scene->attach(scene->root, PTR(p, 0x10));
        ++i;
        off += 4;
    } while (i < 7);
    switch (mode) {
    case 0:
        INT(self, 0x664) = 0;
        self->selection = 0;
        INT(self, 0x638) = 0;
        fn_800557C0();
        break;
    default:
        if (fn_800557D8() != 0) {
            fn_8005A0E4(0x2E);
            fn_800557C0();
        }
        INT(self, 0x664) = 1;
        self->selection = mode - 7;
        INT(self, 0x638) = mode;
        break;
    }
    fn_18_1C4C(self, 1);
    Table table = lbl_2_rodata_558;
    reinterpret_cast<Control*>(PTR(self, 0x658))->set(0xB, table.value[self->selection]);
    reinterpret_cast<MuObject*>(PTR(PTR(self, 0x64C), 0x74))->setFrameTex((float)((static_cast<unsigned int>(reinterpret_cast<unsigned char*>(g_GameGlobal->getGlobalRecordMenuDatap())[0x28]) >> 7) & 1U));
}
