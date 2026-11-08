#include <types.h>
#pragma force_active on

struct MotionPath {
    char pad[0x3c];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void setMotionRatio(float);
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void changeNodeAnim(u32, u32);
};

struct Self {
    char pad[0xc];
    MotionPath* mp;
    u32 index;
    u8 flags;
    char pad2[3];
    float f18;
    float f1c;
};

extern "C" float getFrame__16gfModelAnimationFd(void*, float);
extern "C" void setFrame__16gfModelAnimationFd(void*, float);
extern "C" void changeVisibleAnim__9grGimmickFUlUl(MotionPath*, u32, u32);
extern "C" void fn_27_26BEBC(MotionPath*, u32, u32);
extern "C" void changeTexSrtAnim__9grGimmickFUlUl(MotionPath*, u32, u32);
extern "C" void changeMatColAnim__9grGimmickFUlUl(MotionPath*, u32, u32);
extern "C" void changeShapeAnim__9grGimmickFUlUl(MotionPath*, u32, u32);

extern "C" void fn_27_2373C8(Self* self, float frame) {
    float val = getFrame__16gfModelAnimationFd(**(void***)((char*)self->mp + 0x48), frame);
    u8 flags = self->flags;
    self->f1c = val;
    if (flags & 1) {
        self->mp->changeNodeAnim(self->index, 0);
    }
    if (self->flags & 2) {
        changeVisibleAnim__9grGimmickFUlUl(self->mp, self->index, 0);
    }
    if (self->flags & 4) {
        fn_27_26BEBC(self->mp, self->index, 0);
    }
    if (self->flags & 8) {
        changeTexSrtAnim__9grGimmickFUlUl(self->mp, self->index, 0);
    }
    if (self->flags & 0x10) {
        changeMatColAnim__9grGimmickFUlUl(self->mp, self->index, 0);
    }
    if (self->flags & 0x20) {
        changeShapeAnim__9grGimmickFUlUl(self->mp, self->index, 0);
    }
    setFrame__16gfModelAnimationFd(**(void***)((char*)self->mp + 0x48), self->f1c);
    self->mp->setMotionRatio(self->f18);
}