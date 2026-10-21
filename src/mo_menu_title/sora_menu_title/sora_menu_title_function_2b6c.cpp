#include <types.h>
#pragma force_active on

struct MenuObjectBase {
    u8 padding[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D7B8(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_8018E808(void*);
void fn_8007EA78(void*, int);

struct SoraMenuTitleTask {
    u8 pad000[0x40];
    void* handle40;
    void* handle44;
    void* f48;
    void* f4C;
    MenuObject* f50;
    void* f54;
};

void fn_24_2B6C(SoraMenuTitleTask* self) {
    fn_8000D7B8(g_gfSceneRoot);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle40));
    release__14gfFileIOHandleFv(&self->handle40);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle44));
    release__14gfFileIOHandleFv(&self->handle44);
    fn_8018E808(&self->f48);
    fn_8018E808(&self->f4C);
    if (self->f50) {
        self->f50->destroy(1);
    }
    self->f50 = 0;
    fn_8007EA78(self->f54, 1);
    self->f54 = 0;
}
}
