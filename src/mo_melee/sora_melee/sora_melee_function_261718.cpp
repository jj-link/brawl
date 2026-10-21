#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct ResNodeData {
    char pad[0x20];
    float m_scale_x;
    float m_scale_y;
    float m_scale_z;
};

struct Ground {
    char pad[0x44];
    void** m_models;
};

extern "C" float lbl_27_rodata_42A0;
extern "C" ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const void*, unsigned long);

extern "C" unsigned int getNodeScale__6GroundFP5Vec3fUlUl(Ground* self, Vec3f* out, unsigned long modelIndex, unsigned long nodeIndex) {
    if (out == 0) {
        return 0;
    }
    float v = lbl_27_rodata_42A0;
    out->x = v;
    out->y = v;
    out->z = v;

    void* local = 0;
    void* model = self->m_models[modelIndex];
    if (model == 0) {
        return 0;
    }
    local = *(void**)((char*)model + 0xe8);
    if (local == 0) {
        return 0;
    }
    ResNodeData* node = (ResNodeData*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&local, nodeIndex);
    if (node == 0) {
        return 0;
    }
    out->x = node->m_scale_x;
    out->y = node->m_scale_y;
    out->z = node->m_scale_z;
    return 1;
}
