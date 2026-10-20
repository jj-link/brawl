#pragma force_active on
extern "C" {
void setFrameUpdate__19grGimmickMotionPathFf(void*, float);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;

void onInflict__21grYakumonoPunchSliderFP14soCollisionLogUlf(
    void* self, void*, unsigned long, float)
{
    switch (*(unsigned char*)((char*)self + 0x158)) {
    case 2:
    case 3:
        void* motion = *(void**)((char*)self + 0x150);
        void* data = *(void**)((char*)self + 0x154);
        float frame = *(float*)((char*)motion + 0x158);
        setFrameUpdate__19grGimmickMotionPathFf(
            motion, *(float*)((char*)data + 0x94) * frame);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2269, -1, 0, 0, -1);
        break;
    }
}
}
