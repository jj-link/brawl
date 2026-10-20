#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_56514[];
extern "C" const float lbl_27_rodata_4328;

extern "C" void* fn_27_269C40(void* self, int a, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = (void*)lbl_27_data_56514;
    *(int*)((char*)self + 0x150) = a;
    *(int*)((char*)self + 0x154) = 0;
    *(float*)((char*)self + 0x158) = lbl_27_rodata_4328;
    return self;
}
