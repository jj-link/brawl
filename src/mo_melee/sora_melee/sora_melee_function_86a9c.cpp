#pragma force_active on
struct soSoundEffectInfo {
    virtual int getGroupNo();
    virtual int getLoadFlag();
    virtual int getRangeStart();
    virtual int isStop();
};

extern "C" bool fn_27_86A9C(soSoundEffectInfo* info) {
    return info->isStop() == 0;
}