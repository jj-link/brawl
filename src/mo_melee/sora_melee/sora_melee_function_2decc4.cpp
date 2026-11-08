#pragma force_active on
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual int slot40();
};
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int slot4(unsigned int); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float slot12(unsigned int); virtual void slot13(float, unsigned int); virtual void slot14();
    virtual void slot15(float, unsigned int); virtual void slot16(); virtual int slot17(unsigned int);
};
struct Modules {
    char pad[0x64];
    Object_vptr_0* work;
    char pad2[0x14];
    void* other;
};
struct Context {
    char pad[8];
    Object_vptr_3c* owner;
    char pad2[0xcc];
    Modules* modules;
};
extern "C" {
    extern unsigned char g_ftCommonDataAccesser;
    extern float lbl_27_rodata_63A8;
    float* fn_27_147D94(void*, int);
    void fn_27_894D4(void*, unsigned int);
    void fn_27_2DECC4(void*, Context* context) {
        int kind = context->owner->slot40();
        float* data = fn_27_147D94(&g_ftCommonDataAccesser, kind);
        int state = context->modules->work->slot4(0x20000000);
        if (state == 0) {
            if (context->modules->work->slot17(0x22000013)) {
                context->modules->work->slot15(lbl_27_rodata_63A8, 0x21000004);
            }
        } else if (state == 1) {
            if (context->modules->work->slot12(0x21000004) < *data) {
                context->modules->work->slot13(*data, 0x21000004);
            }
        }
        fn_27_894D4(context->modules->other, 0);
    }
}