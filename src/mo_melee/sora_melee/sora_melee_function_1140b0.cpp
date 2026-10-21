#pragma force_active on
extern "C" void fn_27_12CF78(void*, void*);
extern "C" void fn_27_1241D8(void*, int);

extern "C" {
void fn_27_1140B0(char* self, void* arg) {
    char* p = self;
    int i = 0;
    for (; i < (unsigned char)self[8]; p += 8, i++) {
        if (*(void**)(p + 0x34) != 0) {
            fn_27_12CF78(*(void**)(p + 0x34), arg);
        }
    }
    fn_27_1241D8(*(void**)(self + 0x2c), 0);
    self[0xf] = 1;
    self[0xc] = 0;
}
}
