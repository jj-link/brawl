#pragma force_active on
class Stage {
public:
    void saveMotionSubRatio(int dst);
private:
    char pad[0xd8];
    float sub[4];
};

void Stage::saveMotionSubRatio(int dst) {
    float* out = (float*)dst;
    out[0] = sub[0];
    out[1] = sub[1];
    out[2] = sub[2];
    out[3] = sub[3];
}
