#pragma force_active on
extern "C" {
extern const float lbl_67_rodata_1C8[5];
extern char lbl_67_data_2E70[];
void __ct__9grGimmickFPCc(void*, const char*);

void* fn_67_C978(void* self, const char* name) {
    __ct__9grGimmickFPCc(self, name);
    const float* fp = lbl_67_rodata_1C8;
    char* dp = lbl_67_data_2E70;
    char* p = (char*)self;
    *(char**)(p + 0x3c) = dp;
    *(unsigned char*)(p + 0x150) = 0;
    *(float*)(p + 0x154) = fp[0];
    *(float*)(p + 0x158) = fp[0];
    return self;
}
}
