#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(void*, void*);

struct Anim {
    void* data;
    unsigned char flag;
    unsigned int unk8;
    unsigned int unkC;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

extern "C" void fn_67_9A90(void* self, void* arg) {
    void* model = *(void**)((char*)self + 0x44);
    void* scn = *(void**)model;
    if (scn) {
        Anim* anim = (Anim*)__nw__FUlQ25Heaps8HeapType(0x20, 0xF);
        if (anim) {
            anim->data = *(void**)arg;
            anim->flag = 1;
            anim->unk8 = 0;
            anim->unkC = 0;
            anim->unk10 = 0;
            anim->unk14 = 0;
            anim->unk18 = 0;
            anim->unk1C = 0;
        }
        *(Anim**)((char*)self + 0x16C) = anim;
        if (anim) {
            anim->flag = 0;
            bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(
                scn, *(Anim**)((char*)self + 0x16C));
        }
    }
}
