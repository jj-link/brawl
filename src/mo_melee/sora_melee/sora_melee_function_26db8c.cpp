#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos) {
    struct Sub {
        int pad[2];
        float x;
        float y;
        float z;
    };
    Sub* sub = *(Sub**)((char*)self + 0xd4);
    if (sub == 0) {
        return;
    }
    float x = pos->x;
    float y = pos->y;
    sub->x = x;
    float z = pos->z;
    sub->y = y;
    sub->z = z;
}
