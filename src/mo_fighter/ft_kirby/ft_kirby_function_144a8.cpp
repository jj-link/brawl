#pragma force_active on
class Class_CD28 {
public:
    virtual void fn_96_28D0(); virtual void fn_96_2331C(); virtual void fn_96_23D84();
    virtual void fn_96_23D7C(); virtual void fn_96_23D74(); virtual void fn_96_23D6C();
    virtual void fn_96_23D64(); virtual void fn_96_23D5C(); virtual void fn_96_23D54();
    virtual void fn_96_23D4C(); virtual void fn_96_23D44(); virtual void fn_96_23D3C();
    virtual void fn_96_23D34(); virtual void fn_96_23D2C(); virtual void fn_96_23CDC();
    virtual void fn_96_23D24(); virtual void fn_96_23D14(); virtual void fn_96_23D04();
    virtual void fn_96_23CF4(); virtual void fn_96_23CE4(); virtual void fn_96_23CCC();
};

class WorkModule {
public:
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3();
    virtual int f18(unsigned int); virtual void f1C(int, unsigned int); virtual void w6();
    virtual void f24(unsigned int); virtual void w8(); virtual void w9(); virtual void w10();
    virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14();
    virtual void w15(); virtual void w16(); virtual void* f4C(unsigned int);
    virtual void f50(unsigned int); virtual void f54(unsigned int);
    virtual void f58(void*, unsigned int);
};

class Module {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual int getKind();
    virtual void s4(); virtual void s5(); virtual void* getEnergy(int);
};

struct Modules {
    char pad00[0x14];
    Module* situation;
    char pad18[0x64 - 0x18];
    WorkModule* work;
    char pad68[0x7c - 0x68];
    Module* kinetic;
};

struct Accesser {
    char pad00[0xd8];
    Modules* modules;
};

struct FtData {
    char pad[0x4c];
    unsigned char* p4C;
    int count;
    unsigned char* p54;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern const char lbl_96_data_B09C[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_48;

void* __dynamic_cast(void*, long, const void*, const void*, short);
FtData* fn_27_147C38(void*);
void fn_96_14A80(Accesser&, int);
}

extern "C" void fn_96_144A8(void*, Accesser* accesser) {
    if (accesser->modules->situation->getKind() == 2) {
        void* energy = accesser->modules->kinetic->getEnergy(0);
        float* p = reinterpret_cast<float*>(
            __dynamic_cast(energy, 0, lbl_96_data_B09C, lbl_96_data_5E00, 1));
        p[0x10] = lbl_96_rodata_48;
    }

    void* r28;
    void* r29;
    WorkModule* work = accesser->modules->work;
    r29 = work->f4C(0x22000012);
    r28 = work->f4C(0x22000011);

    if (r29 != 0 && r29 != r28) {
        work->f1C(0, 0x20000003);
        if (accesser->modules->situation->getKind() == 0) {
            work->f54(0x22000010);
        } else {
            work->f50(0x22000010);
        }
    }

    work->f58(r28, 0x22000012);
    FtData* data = fn_27_147C38(&g_ftCommonDataAccesser);
    work = accesser->modules->work;

    if (work->f4C(0x22000011) != 0) {
        int count;
        unsigned char* arr;
        if (work->f4C(0x22000010) == 0) {
            arr = data->p4C;
            count = data->count;
        } else {
            arr = data->p54;
            count = data->count;
        }

        int clamped = work->f18(0x20000003);
        fn_96_14A80(*accesser, arr[(clamped >= count) ? count - 1 : clamped] != 0);
        work->f24(0x20000003);
    }
}
