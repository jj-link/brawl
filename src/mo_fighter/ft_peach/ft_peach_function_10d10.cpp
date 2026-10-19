#pragma force_active on
extern "C" {
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);

void fn_103_10D10(void* self, float rate) {
    for (int i = 0; i < 1; i++) {
        void* member = *(void**)((char*)self + 0x4c + i * 4);
        if (member != 0) {
            setUpdateRate__16gfModelAnimationFf(*(void**)((char*)member + 0x14), rate);
        }
    }
}
}
