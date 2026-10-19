#pragma force_active on
typedef unsigned long u32;

extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 flag, const char* name);
extern char lbl_70_data_4068[];
extern char lbl_70_data_407C[];
}

extern "C" void* fn_70_D140(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)self + 0x180), 0, lbl_70_data_4068);
    getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)self + 0x184), 0, lbl_70_data_407C);
    return ret;
}
