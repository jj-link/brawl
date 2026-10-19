#pragma force_active on
extern "C" {
void fn_67_2058(void* self);
extern char lbl_67_data_2388[];
void* fn_67_A040(void* self);
}

void* fn_67_A040(void* self) {
    fn_67_2058(self);
    *(int*)((char*)self + 0x158) = 0;
    *(char**)((char*)self + 0x3c) = lbl_67_data_2388;
    return self;
}
