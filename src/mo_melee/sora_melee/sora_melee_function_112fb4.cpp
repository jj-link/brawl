#pragma force_active on
extern "C" {
void fn_27_1D556C(void*);

void fn_27_112FB4(unsigned char* self) {
    if (self[0xa] == 1) {
        fn_27_1D556C((char*)(*(void**)self) + 0xcc8);
    }
}
}
