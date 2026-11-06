#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern float lbl_27_rodata_7BC0;
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
int fn_27_1922CC(void*, unsigned long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(int);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38(int, float);
    virtual void slot39(int);
};

struct Modules {
    char pad0[0x64];
    Object_vptr_0* work;
    char pad1[8];
    Object_vptr_0* status;
    char pad2[0x14];
    Object_vptr_0* state;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_373078(void*, Accesser* accesser, int status) {
    unsigned long base = 0x20000000;
    int value = accesser->modules->work->slot4(base + 3);
    if (value != 0) {
        accesser->modules->state->slot20(value);
        accesser->modules->work->slot5(0, base + 3);
    }
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0:
    case 0xe:
        if (fn_27_30FACC(lbl_27_bss_7B0C, 0, accesser->modules->status->slot16(), accesser, 1) == 0x117) {
            Object_vptr_0* work = accesser->modules->work;
            int timer = fn_27_1922CC(accesser, 0x5dc0);
            if (work->slot4(0x10000040) >= timer) {
                accesser->modules->state->slot38(0x1a, lbl_27_rodata_7BC0);
            }
        }
        break;
    case 0x1f:
    case 0x20:
    case 0x117:
        break;
    default:
        accesser->modules->state->slot39(0x1a);
        break;
    }
}
