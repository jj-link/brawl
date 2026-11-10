#include <types.h>

#pragma force_active on

class Gate {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5(int, u32);
    virtual void slot6();
    virtual void slot7(u32);
    virtual void slot8(u32);
    virtual int slot9(int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual int slot17(u32);
    virtual void slot18(u32);
    virtual void slot19();
    virtual void slot20();
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
};

struct Modules {
    char pad0[0x44];
    Gate* gate;
    char pad48[0x0c];
    Object_vptr_0* meter;
    char pad58[0x0c];
    Object_vptr_0* work;
    char pad68[8];
    Object_vptr_0* status;
    char pad74[0x14];
    Object_vptr_0* visual;
};

struct Object {
    char pad0[0xd8];
    Modules* modules;
};

extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_79B8;
extern const float lbl_27_rodata_79BC;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_20084(void*, float);
}

inline void updateMeter(const int* limits, Object* object, void* meter,
                        int& level) {
    int frame;
    Object_vptr_0* work = object->modules->work;
    frame = work->slot4(0x10000041);
    level = 0;
    Object_vptr_0* status = object->modules->status;

    if (status->slot16() != 0x115 && status->slot16() != 0x12f) {
        ++frame;
    }

    if (frame >= limits[0] * 60) {
        frame = limits[0] * 60;
        level = 3;
        if (work->slot17(0x1200003f) == 0) {
            work->slot18(0x1200003f);
            object->modules->visual->slot38(0x27, lbl_27_rodata_79B8);
        }
    } else if (frame >= limits[2] * 60) {
        level = 2;
    } else if (frame >= limits[1] * 60) {
        level = 1;
    }

    work->slot5(frame, 0x10000041);
    work->slot5(level, 0x10000042);
    float value = (float)frame / (float)(limits[0] * 60);
    value *= lbl_27_rodata_79BC;
    fn_27_20084(meter, value);

    if (object->modules->meter->slot9(7) == 0) {
        work->slot7(0x10000043);
    }
    if (work->slot4(0x10000040) > 0) {
        work->slot8(0x10000040);
    }
}

extern "C" void fn_27_357E18(void* self, const int* limits,
                              Object* object, void* meter) {
    int level;

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0)) {
        if (object->modules->gate->slot9() == 0 &&
            object->modules->work->slot17(0x12000040) == 0) {
            updateMeter(limits, object, meter, level);
        }
    }
}
