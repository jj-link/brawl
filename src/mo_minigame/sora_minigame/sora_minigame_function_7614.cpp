#pragma force_active on
extern "C" {
extern char lbl_20_data_800[];
extern char lbl_20_bss_18[];
extern int lbl_20_bss_8;
extern void* lbl_805A0EC8;
extern char* g_gfApplication;

void fn_80101BD8();
void fn_80106314();
void remove__14gfCallBackListFP10gfCallBack(void*, void*);
void fn_8027EABC(void*, void*, unsigned int, int);
void fn_80101384(void*, int);
void fn_20_46F8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_802CD174(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

struct Array {
    void* data;
    int size;
    unsigned int raw;

    unsigned int rawValue() const {
        return raw;
    }
};

struct Object {
    char pad0[0x3C];
    char* unk3C;
    char pad1[0x4C4 - 0x40];
    Array c4;
    Array d0;
    Array dc;
    Array e8;
    Array f4;
};

char* fn_20_7614(char* self, int flag) {
    if (self) {
        ((Object*)self)->unk3C = lbl_20_data_800;
        fn_80101BD8();
        fn_80106314();
        remove__14gfCallBackListFP10gfCallBack(g_gfApplication + 0x114, lbl_20_bss_18);
        if ((unsigned int)self + 0x4F4 != 0 && !(((Object*)self)->f4.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, ((Object*)self)->f4.data, ((Object*)self)->f4.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x4E8 != 0 && !(((Object*)self)->e8.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, ((Object*)self)->e8.data, ((Object*)self)->e8.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x4DC != 0 && !(((Object*)self)->dc.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, ((Object*)self)->dc.data, ((Object*)self)->dc.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x4D0 != 0 && !(((Object*)self)->d0.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, ((Object*)self)->d0.data, ((Object*)self)->d0.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x4C4 != 0 && !(((Object*)self)->c4.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, ((Object*)self)->c4.data, ((Object*)self)->c4.rawValue() << 2, 0x15);
        }
        fn_80101384(self + 0x374, -1);
        __destroy_arr(self + 0x34C, fn_20_46F8, 4, 3);
        fn_802CD174(self + 0x1A0, -1);
        if ((unsigned int)self + 0x40 != 0) {
            lbl_20_bss_8 = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
