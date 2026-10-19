#pragma force_active on
struct Obj {
    char pad[0x0C];
    void* state;
    char pad2[0x0C];
    unsigned char flag;
    float value;
};

extern const float lbl_40_rodata_14C;

extern "C" void fn_40_F2C8(Obj* p) {
    if (*(int*)((char*)p->state + 0x52C) == 2)
        return;
    if (p->flag != 0)
        return;
    p->flag = 1;
    p->value = lbl_40_rodata_14C;
}
