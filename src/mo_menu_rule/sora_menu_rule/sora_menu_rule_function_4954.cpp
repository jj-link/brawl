#pragma force_active on
extern "C" void fn_18_11C4(void*);
extern "C" unsigned char lbl_18_data_1680[];

extern "C" void* fn_18_4954(
    void* self,
    void*,
    void*,
    void* arg6,
    void* arg7
) {
    fn_18_11C4(self);

    *(void**)((unsigned char*)self + 0x68C) = arg7;
    self = self;
    *(void**)((unsigned char*)self + 0x668) = lbl_18_data_1680;
    *((unsigned char*)self + 0x69B) = 1;
    *(void**)((unsigned char*)self + 0x690) = arg6;
    *((unsigned char*)self + 0x694) = 1;
    *((unsigned char*)self + 0x695) = 1;
    *((unsigned char*)self + 0x696) = 1;
    *((unsigned char*)self + 0x697) = 1;
    *((unsigned char*)self + 0x698) = 1;
    *((unsigned char*)self + 0x699) = 1;

    return self;
}
