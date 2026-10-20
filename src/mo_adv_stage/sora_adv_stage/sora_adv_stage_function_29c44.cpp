#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
extern "C" void getPos__9grGimmickFv(Vec3* out, void* self);
extern "C" void fn_27_272594(void* obj, Vec2* pos, int arg, void* extra);

extern "C" void fn_40_29C44(void* self, float deltaFrame) {
    Vec3 tmp;
    Vec2 pos;
    update__9grGimmickFf(self, deltaFrame);
    updateCallback__9grGimmickFUl(self, 0);
    getPos__9grGimmickFv(&tmp, self);
    pos.x = tmp.x;
    pos.y = tmp.y;
    fn_27_272594((char*)self + 0x14c, &pos, 0, *(void**)((char*)self + 0x168));
}
