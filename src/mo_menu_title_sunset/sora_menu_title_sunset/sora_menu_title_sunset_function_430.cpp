#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct MenuObjectBase {
    u8 padding[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

struct SunsetTask {
    u8 pad000[0x44];
    void* handle44;
    void* handle48;
    void* handle4C;
    void* handle50;
    void* f54;
    void* f58;
    void* f5C;
    MenuObject** items60;
    MenuObject* item64;
    u8 pad068[0x74 - 0x68];
    int count74;
    void* f78;
};

extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_8018E808(void*);

void fn_25_430(SunsetTask* self) {
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle44));
    release__14gfFileIOHandleFv(&self->handle44);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle48));
    release__14gfFileIOHandleFv(&self->handle48);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle4C));
    release__14gfFileIOHandleFv(&self->handle4C);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle50));
    release__14gfFileIOHandleFv(&self->handle50);
    fn_8018E808(&self->f54);
    fn_8018E808(&self->f58);
    fn_8018E808(&self->f5C);

    int off;
    int i = 0;
    off = 0;
    while (i < self->count74) {
        MenuObject* obj = *(MenuObject**)((char*)self->items60 + off);
        if (obj) {
            obj->destroy(1);
        }
        i++;
        *(MenuObject**)((char*)self->items60 + off) = 0;
        off += 4;
    }
    __dla__FPv(self->items60);
    self->items60 = 0;
    if (self->item64) {
        self->item64->destroy(1);
    }
    self->item64 = 0;
    __dl__FPv(self->f78);
    self->f78 = 0;
}
}
