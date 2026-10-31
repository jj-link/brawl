#pragma force_active on
struct Vec3f { float x, y, z; };
struct stPositions;
struct KirifudaData {
    char pad[0xAC];
    Vec3f pos;
};
struct Stage {
    char pad[0x90];
    stPositions* positions;
    char pad94[4];
    KirifudaData* data;
};
extern const float lbl_27_rodata_33D8;
extern "C" void getKirifudaPos__11stPositionsFUlP5Vec3f(stPositions*, unsigned long, Vec3f*);
extern "C" void getKirifudaPos__5StageFP5Vec3fUl(Stage* stage, Vec3f* out, unsigned long kind) {
    out->x = out->y = out->z = lbl_27_rodata_33D8;
    switch (kind) {
    case 5:
        if (stage->data) {
            out->x = stage->data->pos.x;
            out->y = stage->data->pos.y;
            out->z = stage->data->pos.z;
        }
        break;
    default:
        if (stage->positions)
            getKirifudaPos__11stPositionsFUlP5Vec3f(stage->positions, kind, out);
        break;
    }
}