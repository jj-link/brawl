#pragma force_active on
typedef signed int s32;

extern "C" {

s32 fn_27_D1650(const void* p) {
    const s32* pp = (const s32*)p;
    return pp[2] >> 24;
}

}
