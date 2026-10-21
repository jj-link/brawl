#pragma force_active on
extern "C" {
void* fn_801AF98C(void* self, int arg);
}

extern "C" void* fn_801B32B0(char* self, int arg) {
    if (arg == 5) {
        return *(void**)(self + 0x138);
    }
    return fn_801AF98C(self, arg);
}
