#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 flag, const char* name);
}

extern const char lbl_51_data_2C08[];
extern const char lbl_51_data_2C18[];

extern "C" void* fn_51_B73C(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)self + 0x1a8), 0, lbl_51_data_2C08);
    getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)self + 0x1ac), 0, lbl_51_data_2C18);
    return ret;
}
