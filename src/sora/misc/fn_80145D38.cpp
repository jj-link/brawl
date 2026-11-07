#include <string.h>
#pragma force_active on

extern "C" int fn_80145828(void* self, int idx, void** out, int size, int a, int b);
extern "C" void netReport__FPCce(const char*, ...);
extern "C" unsigned int g_NtAIDBitmap;
extern "C" unsigned char lbl_8059E742;
extern "C" char lbl_8045EE80[];

struct Entry {
    unsigned char pad[0x14];
    int w14;
    int w18;
    unsigned char data[0xE50 - 0x1C];
};

struct Object {
    unsigned char pad0[0x18];
    int state;
    unsigned int mask;
    char* buf;
    int stride;
    int size;
    unsigned char pad2[0x44 - 0x2C];
    Entry entries[4];
};

extern "C" Object* lbl_805A03A8;

static inline bool isPending(unsigned int aid) {
    Entry* e = &lbl_805A03A8->entries[aid];
    return e->w14 != e->w18;
}

static inline unsigned int findBusy() {
    unsigned int i;
    for (i = 0; i < 4; i++) {
        unsigned char a = i;
        if (i != lbl_8059E742 && (g_NtAIDBitmap & (1 << a)) && isPending(i))
            break;
    }
    return i;
}

static inline int sendTo(Object* self, unsigned char aid, void* src, int size) {
    void* out;
    int ret;
    if (!(g_NtAIDBitmap & (1 << aid)))
        return 0;
    ret = fn_80145828(self, aid, &out, size, 0, 0xE);
    if (ret == 0)
        return ret;
    if (size != 0)
        memcpy(out, src, size);
    Entry* e = &self->entries[aid];
    unsigned char* p;
    if (3 - ((e->w18 + 4 - e->w14) % 4) < 1) {
        p = NULL;
    } else {
        p = &e->data[e->w18 * 0x38C];
    }
    if (p == NULL)
        return 0;
    e->w18 = (*(int*)((char*)e + 0x18) + 1) % 4;
    return 1;
}

extern "C" void fn_80145D38(Object* self) {
    switch (self->state) {
    case 1: {
        if (findBusy() != 4)
            return;
        self->mask &= g_NtAIDBitmap;
        if (self->mask == 0) {
            self->state = 0;
            return;
        }
        char* src = self->buf + lbl_8059E742 * self->stride;
        unsigned char i;
        for (i = 0; i < 4; i++) {
            if ((g_NtAIDBitmap & (1 << i)) && (self->mask & (1 << i))) {
                if (sendTo(self, i, src, self->size))
                    netReport__FPCce(lbl_8045EE80, i);
            }
        }
        self->mask = 0;
        self->state = 2;
        break;
    }
    case 2:
        if (findBusy() == 4)
            self->state = 0;
        break;
    }
}
