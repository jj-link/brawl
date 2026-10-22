#pragma force_active on
typedef unsigned char u8;

struct MenuObjectBase {
    u8 padding[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D07C(void*, int);
void fn_8018E808(void*);

void fn_25_2A74(char* self) {
    fn_8000D07C(g_gfSceneRoot, 0);
    fn_8018E808(self + 0x48);

    MenuObject* obj = *(MenuObject**)(self + 0x4C);
    if (obj) obj->destroy(1);
    *(void**)(self + 0x4C) = 0;

    obj = *(MenuObject**)(self + 0x50);
    if (obj) obj->destroy(1);
    *(void**)(self + 0x50) = 0;

    obj = *(MenuObject**)(self + 0x54);
    if (obj) obj->destroy(1);
    *(void**)(self + 0x54) = 0;

    char* p = self;
    for (int i = 0; i < 0x23; i++) {
        MenuObject* o = *(MenuObject**)(p + 0x58);
        if (o) o->destroy(1);
        *(void**)(p + 0x58) = 0;
        p += 4;
    }

    obj = *(MenuObject**)(self + 0xE4);
    if (obj) obj->destroy(1);
    *(void**)(self + 0xE4) = 0;

    obj = *(MenuObject**)(self + 0xE8);
    if (obj) obj->destroy(1);
    *(void**)(self + 0xE8) = 0;

    obj = *(MenuObject**)(self + 0xEC);
    if (obj) obj->destroy(1);
    *(void**)(self + 0xEC) = 0;

    obj = *(MenuObject**)(self + 0xF0);
    if (obj) obj->destroy(1);
    *(void**)(self + 0xF0) = 0;

    p = self;
    for (int i = 0; i < 0x23; i++) {
        MenuObject* o = *(MenuObject**)(p + 0xF4);
        if (o) o->destroy(1);
        *(void**)(p + 0xF4) = 0;
        p += 4;
    }
}
}
