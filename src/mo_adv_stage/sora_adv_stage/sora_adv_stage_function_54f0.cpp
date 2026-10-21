#pragma force_active on

class CameraController;

extern "C" CameraController* getInstance__16CameraControllerFv();
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_800A59C4(void*);
extern "C" void fn_800A5704(void*);
extern "C" const char lbl_40_data_1590[];
extern "C" const char lbl_40_data_15D8[];

struct Flags8 {
    unsigned int a : 8;
    unsigned int b : 8;
    unsigned int c : 16;
};

struct SelfBase {
    char pad[0x3C];
};

struct SelfObj : SelfBase {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void invoke();

    char pad1[0x52C - 0x40];
    int unk52C;
};

extern "C" void fn_40_54F0(SelfObj* self, int arg1)
{
    char* p;
    unsigned char one;

    self->unk52C = 2;
    self->invoke();

    if (getInstance__16CameraControllerFv() != 0) {
        p = (char*)__dynamic_cast(
            *(void**)((char*)getInstance__16CameraControllerFv() + 0x48),
            4, lbl_40_data_1590, lbl_40_data_15D8, 0);

        if (p != 0) {
            if (arg1 != 0) {
                ((Flags8*)(p + 8))->b = 3;
                *(unsigned char*)(p + 0x144) = 1;
                fn_800A59C4(p);
            } else {
                one = 1;
                ((Flags8*)(p + 8))->b = one;
                *(unsigned char*)(p + 0x144) = one;
                fn_800A59C4(p);
            }

            fn_800A5704(p);
        }
    }
}
