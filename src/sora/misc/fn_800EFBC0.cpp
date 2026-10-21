#pragma force_active on
extern "C" {
extern char lbl_8045B824[];
void fn_800EFC08(void* self, const char* name);

void* fn_800EFBC0(void* self) {
    *(int*)((char*)self + 0x54) = 0;
    *(const char**)((char*)self + 0x74) = lbl_8045B824;
    *(int*)((char*)self + 0x68) = 0;
    fn_800EFC08(self, lbl_8045B824);
    return self;
}
}
