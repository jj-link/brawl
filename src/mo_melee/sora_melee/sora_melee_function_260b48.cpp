#pragma force_active on
class Ground {
public:
    char pad[0x44];
    void** m_nodes;
    void* getNodeIndex(unsigned long index, const char* name);
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

void* Ground::getNodeIndex(unsigned long index, const char* name) {
    if (name == 0) {
        return 0;
    }
    void* local = 0;
    char* node = (char*)m_nodes[index];
    if (node == 0) {
        return 0;
    }
    local = *(void**)(node + 0xe8);
    if (local == 0) {
        return 0;
    }
    void* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
    if (res == 0) {
        return 0;
    }
    if (res != 0) {
        return *(void**)((char*)res + 0xc);
    }
    return 0;
}
