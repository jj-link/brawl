#pragma force_active on
extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern char lbl_68_data_C18[];
extern char lbl_68_data_C24[];

void* fn_68_42E0(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x168), 0, lbl_68_data_C18);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x16c), 0, lbl_68_data_C24);
    return ret;
}
}
