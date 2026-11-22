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
extern const f32 lbl_805A4430;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();

    u8 pad4[0x20];
    int field24;
    u8 pad28[0x88];
    float fieldb0;
    u8 padb4[0x130];
    int field1e4;
};

struct Self {
    u8 pad[0x78];
    int f78;
    int f7c;
    u8 pad80[4];
    s8 f84;
    u8 f85;
    u8 pad86[0x42];
    int fc8;
};

struct Msg {
    s8 flag;
    Object_vptr_0* p;
    int mode;
};

extern "C" void fn_802EFF2C(void*, void*);
extern "C" void fn_80286C14(float*, float, float);
extern "C" void fn_802F064C(void*);
extern "C" void fn_802F83E8(void*, void*, int);
extern "C" void fn_802F80F8(void*, void*);
extern "C" void fn_802F3B90(void*, void*);
extern "C" void fn_802E3CD4(void*);
extern "C" void fn_802EFE70(void*);

inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    Entry* entry = timer->cur;
    if ((s8)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->cur = entry + 1;
    }
}

inline void recordStart() {
    Timer* timer = &lbl_80532448;
    Entry* entry = timer->cur;
    if ((s8)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + 0xA3;
        *(char**)((char*)entry + 0xC) = lbl_80413438 + 0xAF;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->cur = (Entry*)((char*)entry + 0x10);
    }
}

extern "C" Object_vptr_0* fn_802EC1C0(Self* self, Object_vptr_0* object, int mode) {
    if (self->f7c != 0) {
        Msg m;
        m.flag = 1;
        m.p = object;
        m.mode = mode;
        fn_802EFF2C(self, &m);
        return 0;
    }

    recordStart();
    if (object->field24 == 0) {
        object->field24 = object->slot3();
    }
    fn_80286C14(&object->fieldb0, lbl_805A4430, lbl_805A4430);
    self->f85 = 0;
    self->fc8++;
    object->field1e4 = self->fc8;
    fn_802F064C(object);
    fn_802F83E8(self, object, mode);
    self->f85 = 1;
    self->f7c++;
    record(0xB8);
    fn_802F80F8(self, object);
    record(0xC5);
    fn_802F3B90(self, object);
    fn_802E3CD4(object);
    int c = self->f7c - 1;
    self->f7c = c;
    if (c == 0 && self->f78 != 0 && self->f84 == 0) {
        fn_802EFE70(self);
    }
    record(0x62);
    return object;
}