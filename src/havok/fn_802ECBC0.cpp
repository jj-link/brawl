#include <types.h>

#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct Entry {
    char* name;
    u32 time;
    u32 unused;
};

struct Timer {
    u32 pad;
    Entry* cur;
    u32 pad8;
    Entry* end;
    u32 pad10[2];
};

extern Timer lbl_80532448;
extern char lbl_80413438[];

struct Msg {
    s8 flag;
    void* p;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();

    u16 m4;
};

struct Self {
    u8 pad[0x78];
    int f78;
    int f7c;
    u8 pad80[4];
    s8 f84;
    u8 f85;
};

extern "C" void fn_802EFF2C(void*, void*);
extern "C" void fn_802EFE70(void*);
extern "C" void fn_802F0668(void*);
extern "C" void fn_802F3C88(void*, void*);
extern "C" void fn_802F8584(void*, void*);
extern "C" void fn_802F880C(void*, void*);
extern "C" void fn_802E3D50(void*);

inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    Entry* entry = timer->cur;

    if ((s8)(((u32)timer->end <<
              __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->cur = entry + 1;
    }
}

extern "C" u32 fn_802ECBC0(Self* self, Object_vptr_0* arg1) {
    if (((const s32*)self)[0x7C / 4] != 0) {
        Msg m;
        m.flag = 2;
        m.p = arg1;
        fn_802EFF2C(self, &m);
        return 0;
    }

    self->f7c++;
    Timer* timer = &lbl_80532448;
    Entry* entry = timer->cur;
    if ((s8)(((u32)timer->end <<
              __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + 0xF8;
        *(char**)((char*)entry + 0xC) = lbl_80413438 + 0xB8;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->cur = (Entry*)((char*)entry + 0x10);
    }
    fn_802F8584(self, arg1);
    record(0xC5);
    fn_802F3C88(self, arg1);
    fn_802E3D50(arg1);
    self->f85 = 0;
    record(0xAF);
    fn_802F880C(self, arg1);

    if (arg1->m4 == 0) {
        arg1->slot4();
    }

    fn_802F0668(arg1);
    self->f85 = 1;

    int c = self->f7c - 1;
    self->f7c = c;
    if (c == 0 && self->f78 != 0 && self->f84 == 0) {
        fn_802EFE70(self);
    }

    record(0x62);
    return 0x01000000;
}
