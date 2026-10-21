#pragma force_active on
extern "C" {
void update__9grGimmickFf(void* self, float deltaFrame);
void getPos__9grGimmickFv(void* out, void* self);
void getRot__9grGimmickFv(void* out, void* self);
void setPos__9grGimmickFP5Vec3f(void* self, void* pos);
void setRot__9grGimmickFP5Vec3f(void* self, void* rot);
void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
}

struct Vec3fLocal {
    float x;
    float y;
    float z;
};

class grGimmickCatapult {
public:
    void update(float deltaFrame);
};

void grGimmickCatapult::update(float deltaFrame) {
    Vec3fLocal pos2;
    Vec3fLocal rot2;
    Vec3fLocal pos;
    Vec3fLocal rot;
    char* self = (char*)this;

    update__9grGimmickFf(self, deltaFrame);
    if (*(unsigned char*)(self + 0x158) != 0) {
        getPos__9grGimmickFv(&pos, *(void**)(self + 0x154));
        pos2 = pos;
        getRot__9grGimmickFv(&rot, *(void**)(self + 0x154));
        rot2 = rot;
        setPos__9grGimmickFP5Vec3f(self, &pos2);
        setRot__9grGimmickFP5Vec3f(self, &rot2);
    }
    *(float*)(self + 0x15c) += deltaFrame;
    updateCallback__9grGimmickFUl(self, 0);
}
