#pragma force_active on
extern "C" unsigned int getFrameCount__16gfModelAnimationFd(void*);
extern "C" float getFrame__16gfModelAnimationFd(void*);

extern "C" bool fn_27_2793BC(void* self, float delta)
{
    void* animation = **(void***)((char*)self + 0x48);
    if (!animation) return false;
    if (*(int*)((char*)self + 0x1A0) == 0) {
        float frame = (float)getFrameCount__16gfModelAnimationFd(animation);
        if (delta + getFrame__16gfModelAnimationFd(animation) >= frame) return true;
    } else {
        float frame = (float)getFrameCount__16gfModelAnimationFd(animation);
        if (delta + getFrame__16gfModelAnimationFd(animation) >= frame &&
            *(int*)((char*)self + 0x1A0) == 0) return true;
    }
    return false;
}