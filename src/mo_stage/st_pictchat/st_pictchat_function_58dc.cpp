#pragma force_active on
extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern char lbl_73_data_10B8[];

void* fn_73_58DC(void* self) {
    const char* base = (const char*)lbl_73_data_10B8;
    unsigned long flag = 0;
    void* ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x29c), flag, base + 0x98);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x2a0), flag, base + 0x78);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x2a4), flag, base + 0xa8);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x2a8), flag, base + 0xb8);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x2ac), flag, base + 0x88);
    getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x2b0), flag, base + 0xc8);
    return ret;
}
}
