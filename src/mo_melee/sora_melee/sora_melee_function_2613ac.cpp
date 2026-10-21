#pragma force_active on

class Ground {
public:
    char pad[0x44];
    void** m_models;
    int isNodeVisible(unsigned long modelIndex, unsigned long nodeIndex);
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, unsigned long index);

int Ground::isNodeVisible(unsigned long modelIndex, unsigned long nodeIndex) {
    void* local = 0;
    void* model = m_models[modelIndex];
    if (model == 0) {
        return 0;
    }
    local = *(void**)((char*)model + 0xe8);
    if (local == 0) {
        return 0;
    }
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&local, nodeIndex);
    if (node == 0) {
        return 0;
    }
    if (node != 0) {
        unsigned long raw = *(unsigned long*)((char*)node + 0x14);
        return (raw >> 8) & 1;
    }
    return 0;
}
