#pragma force_active on
typedef int s32;

extern "C" unsigned char fn_10_1C56C(void* a);

extern "C" void fn_10_87CC(char* self) {
    char* cur = self;
    s32 i = 0;
    while (i < *(s32*)(self + 0x648)) {
        char* obj = *(char**)(cur + 0x44);
        if (*(s32*)(obj + 0x1B4) != 0) {
            fn_10_1C56C(*(void**)(obj + 0x1AC));
        }
        cur += 4;
        i++;
    }
}
