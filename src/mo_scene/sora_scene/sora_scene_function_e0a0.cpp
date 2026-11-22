#include <types.h>
#pragma force_active on

struct Param {
    s32 type;
    s32 unused;
    union {
        u16 seal;
        u32 value;
    } data;
    u8 flag;
};

struct Entry {
    s32 type;
    union {
        u16 seal;
        u32 value;
    } data;
    u8 flag;
};

struct Self {
    u8 pad[0x36C];
    void* obj;
    s32 count;
    Entry entries[16];
};

extern "C" {
void fn_800C1B04(void*, s32, Param*);
void fn_800C11A4(void*, Param*);
void fn_800C1B20(void*, Param*);
void fn_800C07D0(void*);
}

inline void setSeal(u16 seal, void* obj, Param* p) {
    s32 id = 0x75;
    p->type = 0;
    p->data.seal = seal;
    if ((seal >= 0x5D && seal <= 0x7B) ||
        (seal >= 0x17F && seal <= 0x18A)) {
        id = 0x76;
    }
    fn_800C1B04(obj, id, p);
    fn_800C11A4(obj, p);
}

inline void setOne(void* obj, u16 seal, Param* p) {
    p->type = 1;
    p->data.seal = seal;
    fn_800C1B04(obj, 0x77, p);
    fn_800C11A4(obj, p);
}

inline void setTwo(u8 flag, void* obj, s32 value, Param* p) {
    p->type = 2;
    p->data.value = value;
    p->flag = flag != 0;
    fn_800C1B04(obj, 0x79, p);
    fn_800C11A4(obj, p);
}

inline void setThree(void* obj, s32 value, Param* p) {
    p->type = 3;
    p->data.value = value;
    fn_800C1B04(obj, value, p);
    fn_800C11A4(obj, p);
}

inline void process(Self* self) {
    Param p4, p3, p2, p1, p0;
    Entry* entry = self->entries;
    s32 i;
    for (i = 0; i < self->count; i++, entry++) {
        switch (entry->type) {
        case 0: {
            setSeal(entry->data.seal, self->obj, &p0);
            break;
        }
        case 1: {
            setOne(self->obj, entry->data.seal, &p1);
            break;
        }
        case 2: {
            setTwo(entry->flag, self->obj, entry->data.value, &p2);
            break;
        }
        case 3: {
            setThree(self->obj, entry->data.value, &p3);
            break;
        }
        case 4: {
            s32 value = entry->data.value;
            void* obj = self->obj;
            p4.type = 4;
            p4.data.value = value;
            fn_800C1B20(obj, &p4);
            fn_800C1B04(obj, value, &p4);
            fn_800C11A4(obj, &p4);
            break;
        }
        }
    }
    fn_800C07D0(self->obj);
}

extern "C" void fn_1_E0A0(Self* self) {
    process(self);
}
