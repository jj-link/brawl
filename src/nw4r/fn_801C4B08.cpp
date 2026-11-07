#pragma force_active on
extern "C" {
extern char lbl_80466AE0[];
void fn_801C0AB0(void*, void*);
void fn_801C4C6C(void*);
void* fn_801C4B08(void* self) {
    char* p = (char*)self;
    p[5] = 0;
    *(void**)p = lbl_80466AE0;
    fn_801C0AB0(p + 0x6c, lbl_80466AE0);
    *(int*)(p + 0xb8) = 0;
    *(int*)(p + 0xbc) = 0;
    fn_801C4C6C(self);
    return self;
}
}