#pragma force_active on
extern "C" {

extern void* fn_801D7718(void*, int);
extern void* fn_801D7774(void*, int);

void* fn_80190A58(void** r3, int r4) {
    void* obj = *r3;
    if (r4 != 0)
        return fn_801D7718(obj, 0x40);
    return fn_801D7774(obj, 0x40);
}

}
