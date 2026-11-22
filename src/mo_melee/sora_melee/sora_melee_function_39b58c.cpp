#pragma force_active on
struct Vec { float x, y, z; };
extern const float lbl_27_rodata_7DE0;
extern const float lbl_27_rodata_7DE4;
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void fn_27_248088();
    virtual int slot40();
};
class soNullable {
public:
    virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int slot4(int); virtual void slot5(int, int); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
};
class Class_1250 {
public:
    virtual void fn_27_13C90(); virtual void fn_27_14068(); virtual void fn_27_140C0();
    virtual void fn_27_1412C(); virtual void fn_27_14134(); virtual void fn_27_14370();
    virtual void fn_27_14A28(); virtual void fn_27_14A30(); virtual void fn_27_14A38();
    virtual void fn_27_14A48(); virtual void fn_27_14A68();
    virtual int fn_27_14AD8(int, int, Vec*, Vec*, int, int, int, float, int);
};
struct Modules { char pad[0x64]; soNullable* work; char pad68[0x20]; Class_1250* effect; };
struct Object { char pad[8]; gfTask* task; char pad0c[0xcc]; Modules* modules; };

extern "C" void fn_27_39B58C(Object* obj) {
    soNullable* work;
    int b, c, d;
    unsigned short a;
    a = 0x1d;
    b = 0x220008;
    c = 0x220009;
    d = 0x31;
    if (5 == obj->task->slot40()) {
        a = 0x1b1; b = 0x1230002; d = 0x1b8; c = 0x1230003;
    }
    work = obj->modules->work;
    if (work->slot4(0x10000043) == 0) {
        Vec rot = { lbl_27_rodata_7DE4, lbl_27_rodata_7DE4, lbl_27_rodata_7DE4 };
        Vec pos = { lbl_27_rodata_7DE4, lbl_27_rodata_7DE4, lbl_27_rodata_7DE4 };
        int effect = obj->modules->effect->fn_27_14AD8(b, a, &pos, &rot, 0, 0, 0, lbl_27_rodata_7DE0, -1);
        work->slot5(effect, 0x10000043);
    }
    work = obj->modules->work;
    if (work->slot4(0x10000044) == 0) {
        Vec rot = { lbl_27_rodata_7DE4, lbl_27_rodata_7DE4, lbl_27_rodata_7DE4 };
        Vec pos = { lbl_27_rodata_7DE4, lbl_27_rodata_7DE4, lbl_27_rodata_7DE4 };
        work->slot5(obj->modules->effect->fn_27_14AD8(c, d, &pos, &rot, 0, 0, 0, lbl_27_rodata_7DE0, -1), 0x10000044);
    }
}