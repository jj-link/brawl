#pragma force_active on
struct Gimmick {
    char pad0[0x16C];
    unsigned long node16C;
    unsigned long node170;
    unsigned long node174;
    unsigned long node178;
};

extern "C" int setNode__9grGimmickFv(void* self);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);

extern "C" int fn_70_6CD8(Gimmick* self) {
    int ret = setNode__9grGimmickFv(self);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node16C, 0, "rampHikari1");
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node170, 0, "rampHikari2");
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node174, 0, "rampHikari3");
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node178, 0, "rampHikari4");
    return ret;
}
