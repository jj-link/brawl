#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(unsigned int);
};
class Interface {
    char pad[0x3c];
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
};
struct Module { char pad[0x64]; Object_vptr_0* work; };
struct Self : Interface { char pad40[0x174]; Module* module; char pad1b8[0xf50]; char field1108[4]; };
struct Arg { char pad[12]; int value; };
extern "C" void fn_41_A3C4(void*, int);
extern "C" void fn_41_2A40C(void*);
extern "C" void fn_41_3ACC(void*);
extern "C" void fn_41_A2A4(Self* self, void* a, void* b, Arg* arg) {
    self->s43();
    Object_vptr_0* work = self->module->work;
    work->slot5(arg->value >> 28, 0x10000004);
    fn_41_A3C4(self, 2);
    work->slot19(0x12000005);
    fn_41_2A40C(self->field1108);
    work->slot19(0x1200000e);
    work->slot19(0x12000009);
    work->slot19(0x1200000d);
    work->slot19(0x12000012);
    work->slot19(0x12000013);
    fn_41_3ACC(self);
}