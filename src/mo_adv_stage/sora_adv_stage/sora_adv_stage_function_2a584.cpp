#pragma force_active on
extern "C" {
void fn_27_272D8C(void* self);
extern char lbl_40_data_9080[];
}

extern "C" void* fn_40_2A584(char* self) {
    fn_27_272D8C(self);
    *(int*)(self + 0x154) = 0;
    *(char**)(self + 0x3C) = lbl_40_data_9080;
    *(int*)(self + 0x158) = 0;
    *(int*)(self + 0x15C) = 0;
    return self;
}
