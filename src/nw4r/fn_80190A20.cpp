#pragma force_active on
extern "C" {
int fn_801D7718(void*, unsigned int);
int fn_801D7774(void*, unsigned int);

int fn_80190A20(void** self, unsigned int flag) {
    void* p = *self;
    if (flag != 0)
        return fn_801D7718(p, 0x20);
    return fn_801D7774(p, 0x20);
}
}
