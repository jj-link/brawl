#pragma force_active on

class Ground {
public:
    char pad[0x44];
    void** m_models;
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

extern "C" unsigned int getNodeIndex__6GroundFPUlUlPCc(Ground* self, unsigned long* out, unsigned long index, const char* name) {
    if (name == 0) {
        return 0;
    }
    unsigned long val = 0;
    void* local = 0;
    void* model = self->m_models[index];
    if (model == 0) {
        return 0;
    }
    local = *(void**)((char*)model + 0xe8);
    if (local == 0) {
        return 0;
    }
    void* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
    if (res == 0) {
        return 0;
    }
    if (res != 0) {
        val = *(unsigned long*)((char*)res + 0xc);
    }
    *out = val;
    return 1;
}