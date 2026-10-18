#pragma force_active on
extern "C" void fn_27_D46B8();

extern "C" void fn_108_ADB0(void* observer, short manageId, char unitId) {
    ((long (*)(void*, long, void*, char))fn_27_D46B8)(observer, (long)manageId,
                                                      observer, unitId);
}
