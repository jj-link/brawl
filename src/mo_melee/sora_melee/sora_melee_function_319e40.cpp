#pragma force_active on
extern "C" void fn_27_2556C(void*, void*, void*, void*, void*);
extern unsigned char lbl_27_data_85080[];

extern "C" void* fn_27_319E40(void* self, void* a, void* b, void* c, void* d) {
    fn_27_2556C(self, a, b, c, d);

    unsigned char* p = lbl_27_data_85080;
    *(void**)((char*)self + 8) = p;
    *(void**)((char*)self + 0) = p + 8;
    *(void**)((char*)self + 12) = p + 0x270;
    *(void**)((char*)self + 24) = p + 0x280;
    *(void**)((char*)self + 36) = p + 0x294;

    return self;
}
