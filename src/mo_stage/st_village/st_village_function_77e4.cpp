#pragma force_active on
extern "C" {
extern void* setNode__9grGimmickFv(void* self);
extern void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned int* out, unsigned int flag, const char* name);
extern const char lbl_70_data_2D80[];
}

extern "C" void* fn_70_77E4(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned int*)((char*)self + 0x1e4), 0, lbl_70_data_2D80);
    return ret;
}
