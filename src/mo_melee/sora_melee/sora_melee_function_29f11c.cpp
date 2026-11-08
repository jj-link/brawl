#pragma force_active on

class ftOwner {
public:
    void setSlipMul(float);
    void setSlipInterval(bool);
};

class ftManager {
public:
    void setCurry(int);
    int getEntryIdFromTaskId(int, int*);
    ftOwner* getOwner(int);
};

extern ftManager* g_ftManager;

extern "C" {
extern void* lbl_27_bss_F0;
extern float lbl_27_rodata_4790;
extern float lbl_27_rodata_46C8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
int fn_27_10A35C(ftManager*);
int fn_27_10B21C(ftManager*, int*);
void fn_27_10CF94(ftManager*, int, int, int, float);
void fn_27_29EF44(void*, void*);
}

class ObjA {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int call28();
};

class ObjB {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual int call48();
};

class ObjC {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int call18(unsigned int);
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual int call4C(unsigned int);
    virtual void v12();
    virtual void call54(unsigned int);
    virtual void call58(int, unsigned int);
};

struct Inner {
    char pad0[0x18];
    ObjA* m18;
    char pad1[0x48];
    ObjC* m64;
};

struct Outer {
    char pad[0xd8];
    Inner* md8;
};

struct Mods {
    char pad[0x70];
    ObjB* m70;
};

struct Fighter {
    char pad0[0x60];
    Outer* m60;
    char pad1[0x1a4 - 0x64];
    Mods* m1a4;
};

extern "C" int fn_27_29F11C(void* self, Fighter* f) {
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }

    if (fn_27_5BEA8(lbl_27_bss_F0) == 0) {
        return 1;
    }

    if (f->m1a4->m70->call48() == 6) {
        fn_27_29EF44(self, f);
        return 1;
    }

    Inner* in = f->m60->md8;
    ObjA* a = in->m18;
    ObjC* c = in->m64;
    int r27 = a->call28();
    int var28 = 0;
    if (fn_27_10A35C(g_ftManager) == 0 && (unsigned int)(r27 + 0x10000) != 0xFFFF) {
        var28 = 1;
    }
    c->call58(var28, 0x12000001);
    if (c->call4C(0x12000000) == 0) {
        return 1;
    }
    c->call54(0x12000000);
    int r31 = c->call18(0x10000000);
    if (r31 < 0) {
        return 1;
    }

    int entries[8];
    int count = fn_27_10B21C(g_ftManager, entries);
    switch (r31) {
    case 1:
        for (int i = 0; i < count; i++) {
            g_ftManager->setCurry(entries[i]);
        }
        break;
    case 2:
        for (int i = 0; i < count; i++) {
            int id = entries[i];
            if (id != g_ftManager->getEntryIdFromTaskId(r27, (int*)0)) {
                g_ftManager->getOwner(id)->setSlipMul(lbl_27_rodata_4790);
                g_ftManager->getOwner(id)->setSlipInterval(false);
            }
        }
        break;
    case 3:
        break;
    case 4:
        if (var28 != 0) {
            fn_27_10CF94(g_ftManager, g_ftManager->getEntryIdFromTaskId(r27, (int*)0), 1, 0x3C, lbl_27_rodata_46C8);
        }
        break;
    }
    return 1;
}
