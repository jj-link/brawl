#pragma force_active on

extern "C" {
extern const float lbl_41_rodata_BE0[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern int g_stTriggerMng;
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
float fn_41_39C0(void*);
unsigned int fn_41_11BCC(void*, float, float);
void fn_27_2330C4(void*, void*);
}

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
    virtual void v16();
    virtual void v17();
    virtual void v18(float, unsigned long);
    virtual unsigned isFlag(unsigned long);
    virtual void v20(unsigned long);
};

extern "C" unsigned int fn_41_11CBC(void* self, float* arg1, int arg2) {
    const float* constants = lbl_41_rodata_BE0;
    Work* work;
    unsigned int result = 0;
    work = *(Work**)(*(char**)(*(char**)((char*)self + 0x3c) + 0xd8) + 0x64);

    if (work->getFloat(0x11000001) != constants[3]) {
        work->v18(*arg1, 0x11000001);
        if (work->getFloat(0x11000001) <= constants[12]) {
            work->setFloat(constants[0], 0x11000001);
            result = 1;
        }
    }

    if (work->isFlag(0x12000012) == 1) {
        float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0xbf1, 0);
        void* cast = __dynamic_cast(*(void**)(*(char**)((char*)self + 0x3c) + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        if (fn_41_11BCC(self, val, fn_41_39C0(cast)) == 1) {
            return 1;
        }
    }

    if (result == 1) {
        work->v20(0x12000000);
        if (arg2 == 0 && g_stTriggerMng != 0) {
            void* cast = __dynamic_cast(*(void**)(*(char**)((char*)self + 0x3c) + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
            fn_27_2330C4(*(void**)((char*)cast + 0xb0), (void*)1);
        }
    }

    return result;
}
