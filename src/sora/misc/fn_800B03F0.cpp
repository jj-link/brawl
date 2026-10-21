#pragma force_active on
extern "C" void* fn_80015DB4(void*, int, int, int, unsigned short);
extern "C" void Init__Q34nw4r3g3d7ResFileFPv(void*);

extern "C" void* fn_800B03F0(void* resource, int id) {
    void* sp8;
    sp8 = 0;
    sp8 = fn_80015DB4(resource, 0, 1, id, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(&sp8);
    return sp8;
}
