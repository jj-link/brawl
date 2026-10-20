#pragma force_active on
extern "C" void* fn_27_269C40(void* self, const char* a, const char* name);
extern "C" const float lbl_40_rodata_350;
extern "C" char lbl_40_data_6728[];

extern "C" void* fn_40_23E04(void* self, const char* a, const char* name) {
    fn_27_269C40(self, a, name);
    *(void**)((char*)self + 0x3c) = lbl_40_data_6728;
    *(float*)((char*)self + 0x160) = lbl_40_rodata_350;
    *(int*)((char*)self + 0x164) = 0;
    *(int*)((char*)self + 0x190) = 0;
    *(int*)((char*)self + 0x194) = 0;
    *(int*)((char*)self + 0x198) = 0;
    *(int*)((char*)self + 0x19c) = 0;
    *(int*)((char*)self + 0x1a0) = 0;
    return self;
}
