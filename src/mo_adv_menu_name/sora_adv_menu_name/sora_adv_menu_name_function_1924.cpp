#pragma force_active on

extern "C" {
bool isReady__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void fn_28_15A0(void*, const void*, int, void*);
void fn_28_1694(void*, const void*, int);
void fn_28_51C(void*);
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern unsigned char lbl_28_rodata_40[0x38];
extern unsigned char lbl_28_rodata_78[0xc];
extern unsigned char lbl_28_data_1F8[0x8];
extern unsigned char lbl_28_data_228[0x8];
}

struct Menu {
    char pad0[0x160];
    void* buffer;
    char pad164[4];
    int state;
    char pad16C[0x340 - 0x16C];
    int handle[2];
    unsigned char loaded[2];
    char pad34A[2];
    int status;
};

static bool checkLoaded(Menu* self) {
    int i = 0;
    int one = 1;
    for (; i < 2; i++) {
        if (self->loaded[i] == 0 && self->handle[i] != 0) {
            if (!isReady__14gfFileIOHandleCFv(&self->handle[i])) {
                return true;
            }
            self->loaded[i] = one;
        }
    }
    return false;
}

extern "C" int fn_28_1924(Menu* self) {
    if (checkLoaded(self) == 1) {
        return self->state;
    }
    self->buffer = getBuffer__14gfFileIOHandleCFv(&self->handle[0]);
    Init__Q34nw4r3g3d7ResFileFPv(&self->buffer);
    fn_28_15A0(self, lbl_28_rodata_40, 7, &self->buffer);
    fn_28_1694(self, lbl_28_rodata_78, 3);
    fn_28_51C(self);
    int result;
    if (self->status == 0) {
        result = 6;
    } else if (self->status == 1) {
        result = 7;
    } else {
        result = 1;
        void* mgr = *(void**)getInstance__14gfSceneManagerFv();
        if (mgr != 0) {
            __dynamic_cast(mgr, 4, lbl_28_data_1F8, lbl_28_data_228, 0);
        }
    }
    return result;
}
