#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_2636B4(void*, int, int, void*);
extern const char lbl_27_data_248[];
extern const char lbl_27_data_54E18[];
extern const float lbl_27_rodata_43C8;

struct Result {
    int unk0;
    int unk4;
    float unk8;
    float unkC;
};

class Getter {
public:
    virtual void vf0();
    virtual Result* get();
};

class Caller {
public:
    virtual void vf0();
    virtual int get(int arg);
};

struct Mid {
    char pad0[8];
    void* unk8;
};

class Owner {
public:
    char pad0[0x3C];
    Mid* unk3C;
    Getter* unk40;
};

extern "C" int fn_27_26F128(Owner* self, int arg) {
    Result* r = self->unk40->get();
    if (r->unkC > lbl_27_rodata_43C8 || r->unk8 > lbl_27_rodata_43C8) {
        void* p = __dynamic_cast(self->unk3C->unk8, 0x3C, lbl_27_data_54E18, lbl_27_data_248, 1);
        int v = reinterpret_cast<Caller*>(self->unk40)->get(arg);
        fn_27_2636B4(p, arg, v, (char*)self + 0x64);
        return 1;
    }
    return 0;
}
