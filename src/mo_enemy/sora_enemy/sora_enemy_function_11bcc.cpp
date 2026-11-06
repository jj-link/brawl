#pragma force_active on

extern const float lbl_41_rodata_BE0;
extern "C" {
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern int g_stTriggerMng;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_2330C4(void*, int);
}

class Object_vptr_0 {
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned long);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(unsigned long);
};

extern "C" unsigned int fn_41_11BCC(void* self, float a, float b) {
    Object_vptr_0* work;
    unsigned int result = 0;
    if (b <= a) {
        work = *(Object_vptr_0**)(*(char**)(*(char**)((char*)self + 0x3c) + 0xd8) + 0x64);
        work->slot13(lbl_41_rodata_BE0, 0x11000001);
        work->slot18(0x1200000f);
        result = 1;
        work->slot18(0x12000000);
        if (g_stTriggerMng != 0) {
            void* enemy = __dynamic_cast(*(void**)(*(char**)((char*)self + 0x3c) + 8),
                0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
            fn_27_2330C4(*(void**)((char*)enemy + 0xb0), 1);
        }
    }
    return result;
}
