#pragma force_active on
class Stage {
public:
    void setStageOutEffectInit();
};

void Stage::setStageOutEffectInit() {
    unsigned char *p = (unsigned char *)this;
    p[0xe9] = 0;
    p[0xea] = 0;
}
