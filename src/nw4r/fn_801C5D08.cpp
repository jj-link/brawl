#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_801BF440(void*);
void fn_801BF470(void*, int);
void fn_801BF4F8(void*, int);
extern char lbl_80466AF0[];
extern char lbl_80466B40[];

void* fn_801C5D08(char* self, int arg1, int arg2) {
    *(int*)(self + 0x4) = arg1 + 0xC;
    *(char**)(self + 0x0) = lbl_80466B40;
    __construct_array(self + 0x8, (void (*)(void*))fn_801BF440, (void (*)(void*))fn_801BF470, 0x14, 8);
    fn_801BF4F8(self + 0x8, 0x7FFFFFFF);
    *(int*)(self + 0xAC) = arg2;
    *(char**)(self + 0x0) = lbl_80466AF0;
    *(char**)(self + 0xA8) = lbl_80466AF0 + 0x14;
    *(int*)(self + 0xB0) = arg1;
    return self;
}
}
