#pragma force_active on

extern "C" int fn_801C6B78(void*);
extern "C" int fn_801C6BB4(void*);
extern "C" void fn_801C8104(void*, void*);
extern "C" void fn_801C8140(void*, int);
extern "C" int fn_801C8180(void*, unsigned int, int, int*, int);

struct Slot {
    char pad0[0x18];
    int unk18;
    char pad1[0x200];
    int unk21C;
};

struct Obj {
    int pad0[4];
    void* p10;
    void* p14;
};

extern "C" int fn_801CA274(void* self, unsigned int index, int arg2, int arg3) {
    Obj* s = (Obj*)self;
    int sp8;
    Slot sp10;

    void* child = s->p10;
    int result;
    if (child == 0) {
        result = 0;
    } else {
        result = fn_801C6B78(child);
    }
    if (result == 0) {
        return 0;
    }

    int max_idx = fn_801C6BB4(s->p10);
    if (index >= (unsigned int)max_idx) {
        return 0;
    }

    char* p = (char*)s->p14;
    int val;
    if (p == 0) {
        val = 0;
    } else {
        if (index >= (unsigned int)*(int*)p) {
            val = 0;
        } else {
            val = *(int*)(p + index * 8 + 4);
        }
    }
    if (val != 0) {
        return 1;
    }
    if (arg2 == 0) {
        return 0;
    }

    fn_801C8104(&sp10, s->p10);
    int ret = fn_801C8180(&sp10, index, arg2, &sp8, arg3);
    if (ret == 0) {
        fn_801C8140(&sp10, -1);
        return 0;
    }

    if (s->p14 != 0) {
        *(int*)((char*)s->p14 + index * 8 + 4) = ret;
    }
    int sp8_val = sp8;
    char* p14 = (char*)s->p14;
    if (p14 != 0) {
        *(int*)(p14 + index * 8 + 8) = sp8_val;
    }

    fn_801C8140(&sp10, -1);
    return 1;
}