#pragma force_active on

struct grGimmick {
    char pad0[0x164];
    unsigned long unk164;
    unsigned long unk168;
    unsigned long unk16C;
    unsigned long unk170;
    unsigned long unk174;
    unsigned long unk178;
};

extern "C" int setNode__9grGimmickFv(grGimmick* self);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern "C" struct { char d[0xC8]; } lbl_48_data_7A8;

extern "C" int fn_48_2F68(grGimmick* self) {
    const char* base = (const char*)&lbl_48_data_7A8;
    int ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk164, 0, base + 0xD0);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk168, 0, base + 0xE0);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk16C, 0, base + 0xF4);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk170, 0, base + 0x108);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk174, 0, base + 0x11C);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->unk178, 0, base + 0xC8);
    return ret;
}
