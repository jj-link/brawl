#pragma force_active on
typedef int s32;

extern "C" bool isExistTarget__16emAreaModuleImplFP16soModuleAccesserUl(void*, unsigned long);

extern "C" bool fn_41_152CC(s32* p1, void* p2) {
    if (p1[0] == -2) {
        return true;
    }
    if (p1[1] == -1) {
        return true;
    }
    return !isExistTarget__16emAreaModuleImplFP16soModuleAccesserUl(p2, p1[1]);
}
