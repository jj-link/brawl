#pragma force_active on
extern "C" {
void* fn_40_24D88(void* self);
extern char lbl_40_data_149B0[];

void* fn_40_3A0C8(void* self) {
    fn_40_24D88(self);
    *(int*)((char*)self + 0x1a4) = 0;
    *(char**)((char*)self + 0x3c) = lbl_40_data_149B0;
    return self;
}
}
