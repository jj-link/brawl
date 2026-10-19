#pragma force_active on
extern "C" void fn_8007266C(void*);
extern "C" unsigned char lbl_90_data_2A8C[];

extern "C" void* fn_90_1234(void* self) {
    *(unsigned int*)((char*)self + 4) = 0;
    void* member = (char*)self + 0x10;
    fn_8007266C(member);
    *(void**)member = lbl_90_data_2A8C;
    return self;
}
