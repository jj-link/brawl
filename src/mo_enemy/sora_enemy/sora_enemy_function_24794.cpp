#pragma force_active on
struct V3 {
    float x, y, z;
};

extern "C" {
void getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
    V3*, void*, unsigned long, bool);

unsigned long fn_41_245B8(void*, V3*);
void fn_41_24660(void*, unsigned long, unsigned long);

void fn_41_24794(void* acc, unsigned long target, unsigned long mode) {
    V3 pos;
    getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
        &pos, acc, target, true);

    unsigned long r = fn_41_245B8(acc, &pos);
    fn_41_24660(acc, r, mode);
}
}
