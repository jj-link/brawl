#pragma force_active on

typedef unsigned int u32;
typedef int s32;

struct Arg1 {
    int type;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    char pad7;
    int val8;
    char padC[8];
    float f14;
};

struct BitField {
    unsigned int low : 17;
    int mid : 8;
    unsigned int high : 7;
};

class Work {
public:
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
    virtual float v12(u32);
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, void*);
};

extern "C" {
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32, u32);
void fn_27_23313C(void*, void*, void*, s32);
void fn_41_B8D4(void*, void*, void*, void*);
void fn_41_11CBC(void*, float*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern int g_stTriggerMng;
extern const char lbl_41_data_1EE8[];
extern const char lbl_41_data_2210[];
}

extern "C" void fn_41_48578(void* self, Arg1* arg1, void* arg3, void* param4) {
    switch (arg1->type) {
    case 6: {
        arg1->b4 = 1;
        arg1->b6 = 1;
        arg1->b5 = 0;
        arg1->val8 = -1;

        float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            (char*)self + 0xDC, 0xFA0, 0, (u32)param4);
        arg1->f14 = val;

        if (g_stTriggerMng != 0) {
            BitField* bf = (BitField*)((char*)param4 + 0x2C);
            fn_27_23313C(*(void**)((char*)self + 0xB0),
                         *(void**)((char*)param4 + 0x28),
                         *(void**)((char*)self + 0x28),
                         bf->mid);
        }

        Work* work = *(Work**)(*(char**)((char*)self + 0x1B4) + 0x64);
        float result2 = work->v12(0x11000001);

        void* cast_result = __dynamic_cast(
            *(void**)(*(char**)((char*)self + 0x1B4) + 0x38),
            8, lbl_41_data_1EE8, lbl_41_data_2210, 1);

        fn_41_11CBC(cast_result, &result2, 0);

        void* p1 = *(void**)((char*)self + 0x60);
        Inner* inner = *(Inner**)(*(char**)((char*)p1 + 0xD8) + 0x70);
        inner->v3(0xF, p1);
        break;
    }
    default:
        fn_41_B8D4(self, arg1, arg3, param4);
        break;
    }
}
