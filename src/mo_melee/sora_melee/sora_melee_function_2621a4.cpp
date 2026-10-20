#pragma force_active on
extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);

extern char lbl_27_data_549E8[];
extern char lbl_27_data_549F8[];

void* fn_27_2621A4(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x158), 0, lbl_27_data_549E8);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x15c), 0, lbl_27_data_549F8);
    return ret;
}
}
