#pragma force_active on
extern "C" char lbl_80454AE0[];

extern "C" void fn_8009A048(void* p) {
    ((int*)p)[1] = 0;
    ((void**)p)[0] = &lbl_80454AE0;
}
