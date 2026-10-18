#pragma force_active on
struct Status {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual int get(int);
};

struct Work {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void set(int, unsigned);
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual unsigned flag(unsigned);
};

struct Kinetic {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void* get(int);
};

struct Ground {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void dummy37();
    virtual void dummy38();
    virtual void dummy39();
    virtual void dummy40();
    virtual void dummy41();
    virtual void dummy42();
    virtual void dummy43();
    virtual void dummy44();
    virtual void dummy45();
    virtual void dummy46();
    virtual void dummy47();
    virtual void dummy48();
    virtual void dummy49();
    virtual void dummy50();
    virtual void dummy51();
    virtual void dummy52();
    virtual void dummy53();
    virtual void dummy54();
    virtual void call(int, int, int, int);
};

struct Energy {
    char pad[12];
    float speed;
};

struct Modules {
    char pad0[0x5c];
    Ground* ground;
    void* p60;
    Work* work;
    void* p68;
    void* p6c;
    Status* status;
    void* p74;
    void* p78;
    Kinetic* kinetic;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1677E0(void*, soModuleAccesser*, int);

void fn_27_167A40(void* self, soModuleAccesser* a) {
    if (a->modules->status->get(0) == 0xea) {
        int n = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0x5a82, 0);
        a->modules->work->set(n, 0x20000000);

        void* e = a->modules->kinetic->get(1);
        Energy* energy = (Energy*)__dynamic_cast(
            e, 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        energy->speed =
            -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xdaa, 0);
    }

    if (a->modules->work->flag(0x1200000b) == 1) {
        int n = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0x5a70, 0);
        a->modules->work->set(n, 0x1000001c);
    } else {
        fn_27_1677E0(self, a, 1);
    }

    a->modules->ground->call(9, 0, 1, -1);
}
}
