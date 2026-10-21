#pragma force_active on
extern "C" void fn_80164F30(int a, void* b);

extern "C" void fn_8016C470(void* arg0) {
    fn_80164F30(*(int*)((char*)arg0 + 0x20), arg0);
}
