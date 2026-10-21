#pragma force_active on
extern "C" {
extern void* lbl_8059FF90;
void fn_80012470(void*, void*);

void fn_80010ED4(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (!((p[0x1C] >> 4) & 1)) {
        fn_80012470(lbl_8059FF90, self);
        p[0x1C] = (unsigned char)(p[0x1C] | 0x10);
    }
}
}
