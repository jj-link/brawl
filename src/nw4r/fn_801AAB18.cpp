#pragma force_active on
extern "C" void fn_801EC1B8(void* a, void* b, void* c);

extern "C" void fn_801AAB18(void* self, void* arg) {
    fn_801EC1B8(arg, (char*)self + 0x3c, (char*)self + 0x6c);
}
