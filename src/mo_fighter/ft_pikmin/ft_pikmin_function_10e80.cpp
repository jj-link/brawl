#pragma force_active on

extern "C" {
extern const char lbl_113_data_61C[];
extern const char lbl_113_data_2950[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_113_243CC(void*);
void* fn_113_244FC(void*);
int fn_113_18EC8(void*, int);
extern float lbl_113_rodata_28;
}

class Target2 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13(float, int);
};

extern "C" void fn_113_10E80(void*, void* self) {
    void* target = __dynamic_cast(*(void**)((char*)self + 8), 0x3c, lbl_113_data_61C, lbl_113_data_2950, 0);
    if (target) {
        void* manager = (char*)target + 0x1fd08;
        if (fn_113_243CC(manager) > 0) {
            int r = (*(Target2**)(*(char**)((char*)self + 0xd8) + 0x64))->m4(0x20000000);
            switch (r) {
            case 0x72:
                fn_113_18EC8(fn_113_244FC(manager), 0x22000000);
                break;
            case 0x73:
                fn_113_18EC8(fn_113_244FC(manager), 0x22000001);
                break;
            case 0x74:
                fn_113_18EC8(fn_113_244FC(manager), 0x22000002);
                break;
            case 0x75:
                fn_113_18EC8(fn_113_244FC(manager), 0x22000003);
                break;
            }
            (*(Target2**)(*(char**)((char*)self + 0xd8) + 0x64))->m13(lbl_113_rodata_28, 0x21000004);
        }
    }
}