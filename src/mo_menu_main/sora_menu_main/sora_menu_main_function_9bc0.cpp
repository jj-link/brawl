#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef void (*FnA)(void*);
typedef s32 (*FnB)(void*);

struct StateEntry {
    FnA a;
    FnB b;
};

extern "C" void fn_800B9984(void* arg);
extern "C" void fn_2_9C64(void* self);
extern "C" StateEntry lbl_2_rodata_218[];

extern "C" void fn_2_9BC0(void* self) {
    u8* p = (u8*)self;
    fn_800B9984(p + 0x190);

    s32 cur = *(s32*)(p + 0x238);
    if (*(s32*)(p + 0x23c) != cur) {
        FnA fa = lbl_2_rodata_218[cur].a;
        if (fa) {
            fa(self);
        }
        *(s32*)(p + 0x23c) = *(s32*)(p + 0x238);
    }

    FnB fb = lbl_2_rodata_218[*(s32*)(p + 0x238)].b;
    if (fb) {
        *(s32*)(p + 0x238) = fb(self);
    }

    fn_2_9C64(self);
}
