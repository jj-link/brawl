#pragma force_active on
typedef unsigned long u32;

struct grGimmick {
    char pad0[0x168];
    u32 node168;
    u32 node16C;
    u32 node170;
    u32 node174;
    u32 node178;
    u32 node17C;
};

extern "C" int setNode__9grGimmickFv(grGimmick* self);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 flag, const char* name);
extern "C" char lbl_71_data_15A0[];

extern "C" int fn_71_6724(grGimmick* self) {
    const char* base = (const char*)&lbl_71_data_15A0;
    int ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node168, 0, base + 0x80);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node16C, 0, base + 0x94);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node170, 0, base + 0xA8);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node174, 0, base + 0xBC);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node178, 0, base + 0xD0);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node17C, 0, base + 0xE8);
    return ret;
}
