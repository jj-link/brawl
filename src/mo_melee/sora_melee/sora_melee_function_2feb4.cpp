#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct soModuleAccesser;
struct GroundData {
    u8 pad[0x73];
    u8 unused : 5;
    u8 enabled : 1;
    u8 other : 2;
};
struct soGroundShapeImpl {
    u32 unk0;
    GroundData* data;
    u8 pad[0x30];
    u32 flags;
    void updateRhombusModify(soModuleAccesser*);
    void updateRhombus(soModuleAccesser*);
    void updateRhombusFollowNode(soModuleAccesser*);
};
extern "C" void fn_27_2FEB4(soGroundShapeImpl* self, soModuleAccesser* accesser, int mode) {
    switch ((int)((self->flags >> 12) & 15)) {
    case 0:
        self->updateRhombusModify(accesser);
        break;
    case 1:
        self->updateRhombus(accesser);
        break;
    case 2:
        self->updateRhombusFollowNode(accesser);
        break;
    }
    GroundData* d = self->data;
    d->enabled = (mode == 1) ? 0 : 1;
}
