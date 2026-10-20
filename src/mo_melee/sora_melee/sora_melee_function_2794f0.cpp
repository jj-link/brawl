#pragma force_active on
extern "C" float getFrame__16gfModelAnimationFd(void*);

extern "C" bool isFrameOffset__8grMadeinFf(void* self, float frame)
{
    void* animation = **(void***)((char*)self + 0x48);
    if (!animation) {
        return false;
    }

    if (*(int*)((char*)self + 0x1A0) == 0) {
        if (getFrame__16gfModelAnimationFd(animation) >= frame) {
            return true;
        }
    } else {
        if (getFrame__16gfModelAnimationFd(animation) >= frame &&
            *(int*)((char*)self + 0x1A0) == 0) {
            return true;
        }
    }
    return false;
}
