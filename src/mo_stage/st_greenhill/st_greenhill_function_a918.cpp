#pragma force_active on
extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern char lbl_72_data_2240[];

void* fn_72_A918(void* self) {
    const char* base = lbl_72_data_2240;
    void* ret = setNode__9grGimmickFv(self);
    unsigned char c = ((unsigned char*)self)[0x16c];
    switch (c) {
    case 0:
        getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x184), 0, base + 0x24);
        break;
    case 1:
        getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x184), 0, base + 0x30);
        break;
    case 2:
        getNodeIndex__6GroundFPUlUlPCc(self, (unsigned long*)((char*)self + 0x184), 0, base + 0x3c);
        break;
    }
    return ret;
}
}
