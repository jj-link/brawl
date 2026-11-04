#pragma force_active on

typedef unsigned int u32;

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
u32 lbl_27_data_4A000[];
extern const char lbl_27_data_248[];
extern const float lbl_27_rodata_5EA4;
void fn_27_60CDC(void*, void*, void*, float, float, float, float, float, float, float, float);
}

struct Input {
    char pad[0x8];
    void* task;
};

struct CastResult {
    char pad[0x8C0];
    int id;
};

extern "C" void fn_27_2B3068(void* unused, Input* self, void* arg2, void* arg3, float f0, float f1, float f2) {
    void* cast = __dynamic_cast(self->task, 0x3C, lbl_27_data_4A000, lbl_27_data_248, 1);
    CastResult* obj = (CastResult*)cast;
    if (obj->id == 0x31 || obj->id == 0x4F) {
        fn_27_60CDC(self, arg2, arg3, f0, f1, f2, lbl_27_rodata_5EA4, lbl_27_rodata_5EA4, lbl_27_rodata_5EA4, lbl_27_rodata_5EA4, lbl_27_rodata_5EA4);
    }
}
