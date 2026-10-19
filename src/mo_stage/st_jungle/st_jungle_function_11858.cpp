#pragma force_active on
extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern const char lbl_51_data_7BCC[];
extern const char lbl_51_data_7BDC[];
}

extern "C" void* fn_51_11858(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x198), 0, lbl_51_data_7BCC);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x19C), 0, lbl_51_data_7BDC);
    return ret;
}
