#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct MuObject {};

extern "C" void fn_800B6838(MuObject*, const Vec3f*);

extern "C" void fn_3_223C(int* self) {
    Vec3f pos;
    float* obj = (float*)(self + (self + self[0xf28/4])[0xf14/4])[0xfd0/4];
    pos.x = obj[0x3c/4];
    pos.y = obj[0x40/4];
    pos.z = obj[0x44/4];
    pos.x = ((float*)(self + self[0xf28/4]))[0xf3c/4];
    fn_800B6838((MuObject*)(self + (self + self[0xf28/4])[0xf14/4])[0xfd0/4], &pos);
    self[0xf24/4] = self[0xf4c/4];
}
