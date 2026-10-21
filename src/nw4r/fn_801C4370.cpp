#pragma force_active on
extern "C" void fn_801BC554(void* p);

extern "C" void fn_801C4370(void* p) {
    fn_801BC554(p);
    *(int*)((char*)p + 0x204) = 0;
}
