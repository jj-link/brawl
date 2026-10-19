#pragma force_active on
extern "C" int fn_800BA3D8(void*);

extern "C" int fn_40_3F670(void* base, int index) {
    return fn_800BA3D8((char*)base + index * 0x150 + 0x970) >= 0;
}
