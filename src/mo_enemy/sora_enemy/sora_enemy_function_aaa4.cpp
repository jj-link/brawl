#pragma force_active on
typedef unsigned char u8;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_41_ABE0(void*);
extern "C" u8 lbl_41_data_12DC[];
extern "C" u8 lbl_41_data_1304[];
extern "C" u8 lbl_41_bss_504[];

class soNullable {
public:
    virtual int isNull();  // offset 0x8: isNull__10soNullableCFv
    virtual void slot1();
    virtual void slot2();
    virtual soNullable* slot3(int, bool, bool);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(soNullable*);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual int slot20(int);
};

class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC(int, int);
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8();
    virtual void fn_41_350FC();
    virtual void fn_41_35108();
    virtual void fn_41_3510C();
    virtual void fn_41_13638();
    virtual void fn_41_34F38();
};

struct Enum {
    u8 pad[0x64];
    Class_6E20* mod;
};
struct Acc {
    u8 pad[0xd8];
    Enum* e;
};
struct Holder {
    u8 pad[0x84];
    soNullable* n;
};
struct Self {
    u8 pad[0x60];
    Acc* acc;
    u8 pad2[0x1b4 - 0x64];
    Holder* h;
};

extern "C" int fn_41_AAA4(Self* self, int a, int b, int c)
{
    soNullable* n = self->h->n;
    if (__dynamic_cast(n, 0, lbl_41_data_12DC, lbl_41_data_1304, 0)) {
        return 0;
    }
    if (n->slot20(a)) {
        self->acc->e->mod->fn_41_350BC(b, 0x10000007);
        fn_41_ABE0(lbl_41_bss_504 + 4);
        *(void**)(lbl_41_bss_504 + 0x2c) = (u8*)self + 0x4490;
        *(int*)(lbl_41_bss_504 + 0x8) = c;
        soNullable* r = n->slot3(a, false, false);
        if (!r->isNull()) {
            n->slot13(r);
        }
    } else {
        return 0;
    }
    return 1;
}
