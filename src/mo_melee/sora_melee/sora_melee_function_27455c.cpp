#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" void updateCallback__9grGimmickFUl(void* self, unsigned long arg);

class grGimmickWarpZone {
public:
    void update(float deltaFrame);
};

void grGimmickWarpZone::update(float deltaFrame) {
    update__9grGimmickFf(this, deltaFrame);
    updateCallback__9grGimmickFUl(this, 0);
}
