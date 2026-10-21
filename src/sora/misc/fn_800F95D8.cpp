#pragma force_active on
extern "C" void fn_800B8EDC(void*, void*);

extern "C" void fn_800F95D8(void* self) {
    if (*(void**)((char*)self + 0x340) != 0) {
        for (int i = 0; i < 2; i++) {
            fn_800B8EDC(*(void**)((char*)self + 0x340), *(void**)((char*)self + 0x268));
        }
    }
}
