#pragma force_active on
struct soModelModuleImpl {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
};

struct ModelModule {
    void *unk0[0xEC / sizeof(void *)];
    void *worldMtxArray;
};

extern "C" void *getWorldMtxArray__17soModelModuleImplFv(soModelModuleImpl *self)
{
    ModelModule *module = *(ModelModule **)((char *)self + 0x0C);
    return *(void **)((char *)module + 0xEC);
}
