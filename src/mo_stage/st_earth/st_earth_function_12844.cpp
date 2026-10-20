#pragma force_active on
extern const float lbl_66_rodata_270;
extern const float lbl_66_rodata_280;
extern "C" float getFrame__16gfModelAnimationFd(void*, double);

extern "C" bool fn_66_12844(char* self) {
    float a = lbl_66_rodata_270;
    if (a == *(float*)(self + 0x158)) {
        return true;
    }
    void* p = *(void**)(*(char**)(self + 0x48));
    if (!p) {
        return false;
    }
    float frame = getFrame__16gfModelAnimationFd(p, a);
    return frame >= lbl_66_rodata_280 * *(float*)(self + 0x158);
}
