#pragma force_active on
extern "C" {
void fn_27_1D5474(void* p);

void fn_27_112F20(char* p) {
    if (*(unsigned char*)(p + 0xa) == 1) {
        fn_27_1D5474((char*)*(void**)p + 0x9e8);
    }
}
}
