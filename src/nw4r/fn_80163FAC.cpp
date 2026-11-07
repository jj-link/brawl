#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8016DF20(void*, int);
extern "C" void fn_8016DF8C(void*);
extern "C" u16 fn_8016F198(void*, void*, u16);
extern "C" void fn_801703B8(void*);

struct Counter {
    char pad[0x10];
    s32 unk10;
};

struct Mgr {
    char pad0[0x20];
    Counter* unk20;
    char list[0x8];
    u16 unk2C;
    char pad1[0x22];
    u32 flags;
};

struct Class_804652C8_base {
    char pad[0x1c];
};

class Class_804652C8 : public Class_804652C8_base {
public:
    virtual void fn_80164E3C();
    virtual void fn_80164E48();
    virtual void fn_80165370();
    virtual void fn_801654C8();
    virtual void fn_801662E4();
    virtual void fn_801665C0();
    virtual void fn_80166648();
    virtual void fn_8016675C();

    void decrement() {
        if (unkE8 != 0) {
            unkE8--;
        }
    }

    char pad2[0x4];
    u32 flags;
    char pad3[0x8c];
    s32 state;
    char pad4[0x8];
    char childList[0x8];
    char pad5[0x1c];
    s32 unkE4;
    u16 unkE8;
};

extern "C" void fn_80163FAC(Mgr* self, s32 arg1) {
    Class_804652C8* buf[1024];
    u16 count;

    if (arg1 != 0) {
        Class_804652C8* a = NULL;
        while ((a = (Class_804652C8*)fn_8015C1B0(&self->list, a)) != NULL) {
            if ((u32)(*(s32*)((char*)a + 0xc) - 1) <= 1U &&
                ((a->flags & 0x10000) || (a->flags & 0x8000))) {
                a->fn_8016675C();
            }
        }
        return;
    }

    if (self->flags & 1) {
        return;
    }

    {
        Class_804652C8* b = NULL;
        while ((b = (Class_804652C8*)fn_8015C1B0(&self->list, b)) != NULL) {
            if ((u32)(*(s32*)((char*)b + 0xc) - 1) <= 1U && b->state == 1) {
                b->state = 0;
            }
            Class_804652C8* bc = NULL;
            while ((bc = (Class_804652C8*)fn_8015C1B0(b->childList, bc)) != NULL) {
                fn_8016DF20(bc, 0);
            }
        }
    }

    self->flags |= 0x10000;

    while (self->flags & 0x10000) {
        self->flags &= ~0x10000;
        for (;;) {
            count = fn_8016F198(&self->list, buf, self->unk2C);
            for (u16 i = 0; i < count; i++) {
                buf[i]->fn_801662E4();
            }

            {
                Class_804652C8* w = NULL;
                while ((w = (Class_804652C8*)fn_8015C1B0(&self->list, w)) != NULL) {
                    if ((u32)(*(s32*)((char*)w + 0xc) - 1) <= 1U &&
                        ((w->flags & 0x10000) || (w->flags & 0x8000))) {
                        w->fn_8016675C();
                    }
                }
            }

            count = fn_8016F198(&self->list, buf, self->unk2C);
            for (u16 i = 0; i < count; i++) {
                Class_804652C8* n = buf[i];
                if (n->state == 0) {
                    n->unkE4++;
                }
                n->fn_801665C0();
                if (n->state == 0) {
                    n->unkE4--;
                }
            }

            count = fn_8016F198(&self->list, buf, self->unk2C);
            for (u16 i = 0; i < count; i++) {
                buf[i]->fn_80166648();
            }

            count = fn_8016F198(&self->list, buf, self->unk2C);
            for (u16 i = 0; i < count; i++) {
                buf[i]->fn_801665C0();
            }

            if (self->unk20->unk10 != 0) {
                fn_801703B8(&self->unk20->unk10);
                continue;
            }

            if (self->flags & 0x10000) {
                Class_804652C8* c = NULL;
                while ((c = (Class_804652C8*)fn_8015C1B0(&self->list, c)) != NULL) {
                    if (*(s32*)((char*)c + 0xc) == 1 && c->unkE8 != 0) {
                        c->decrement();
                        if (c->state == 1) {
                            c->state = 0;
                        }
                    }
                    Class_804652C8* cc = NULL;
                    while ((cc = (Class_804652C8*)fn_8015C1B0(c->childList, cc)) != NULL) {
                        fn_8016DF20(cc, 1);
                    }
                }
            }
            break;
        }
    }

    {
        Class_804652C8* d = NULL;
        while ((d = (Class_804652C8*)fn_8015C1B0(&self->list, d)) != NULL) {
            if ((u32)(*(s32*)((char*)d + 0xc) - 1) <= 1U && d->state == 3) {
                d->state = 1;
            }
            Class_804652C8* dc = NULL;
            while ((dc = (Class_804652C8*)fn_8015C1B0(d->childList, dc)) != NULL) {
                fn_8016DF8C(dc);
            }
        }
    }
}
