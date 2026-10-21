#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

struct Vec3f {
    float x, y, z;
};

struct CallbackData {
    u32 id;
    u32 unknown;
    Vec3f position;
};

struct CallbackOwner {
    u32 pad0;
    CallbackData* p;
    u32 f2;
    u32 f;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);

extern "C" void fn_88_7128(void* self) {
    unsigned char* s = (unsigned char*)self;
    CallbackOwner* st = (CallbackOwner*)(s + 0xd0);
    if (st != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                st->f = 0;
                st->p->id = *(u32*)(s + 0xc4);
                *(void**)(m + 0x11c) = st;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)st->p->id;
            }

            Vec3f* src = *(Vec3f**)(s + 0x158);
            if (src != 0) {
                st->p->position = *src;
            }
        }
    }
}
