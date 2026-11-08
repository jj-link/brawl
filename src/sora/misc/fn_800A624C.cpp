#pragma fp_contract on
#pragma opt_common_subs off
#pragma force_active on
typedef unsigned int u32;
struct ScnObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFrame(float);
};
struct ResAnmScn { void* data; bool IsValid() const { return data != 0; } };
struct cmAnimationController {
    char pad[0xc];
    void* scene;
    ScnObj* animation;
    char pad14[8];
    u32 frame;
    int state;
};
extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
int fn_801971D0(ResAnmScn*, ResAnmScn*);
ScnObj* fn_8019CA18(void*, u32*, ResAnmScn*, int);
void* fn_801AC370(void*, u32*, int, int, int, int);
void fn_801AC650(void*, ScnObj*);
int setScnAnmRes__21cmAnimationControllerFQ34nw4r3g3d9ResAnmScnUl(cmAnimationController* self, ResAnmScn* res, u32 frame) {
    void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
    struct {
        ResAnmScn copy;
        ResAnmScn copy2;
        u32 sceneSize;
        u32 animSize;
    } locals;
    int result = 0;
    if (res->IsValid()) {
        locals.copy.data = res->data;
        if (fn_801971D0(res, &locals.copy)) {
            locals.copy2.data = res->data;
            self->animation = fn_8019CA18(allocator, &locals.animSize, &locals.copy2, 0);
            self->scene = fn_801AC370(allocator, &locals.sceneSize, 2, 2, 128, 128);
            fn_801AC650(self->scene, self->animation);
            self->animation->setFrame((float)(int)frame);
            self->frame = frame;
            result = 1;
            self->state = 0;
        }
    }
    return result;
}
}