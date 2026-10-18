#pragma force_active on
extern "C" void fn_6_533C(char* self) {
    char* p = *(char**)(self + 0x1ac);
    char* q = *(char**)(p + 0x1ce4);
    if (*(int*)(q + 0x350) != 0) {
        return;
    }
    *(int*)(p + 0x1bf4) = 0;
}
