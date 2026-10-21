#pragma force_active on

struct InnerObj {
    virtual void vf0();
    virtual void vf1();
    virtual void* vf2(int idx);
    virtual int vf3();
};

struct OuterObj {
    char pad0[0x6d8];
    InnerObj inner;
};

struct VF2Ret {
    void* ptr;
};

struct ItemStruct {
    char pad0[0x8bc];
    unsigned int field8bc;
};

extern "C" int fn_27_2A7E08(void* self, void* item);

extern "C" void* fn_27_2A8054(void* arg0) {
    OuterObj* self = (OuterObj*)arg0;
    void* var_r30 = 0;
    int var_r29 = 0x2710;
    int count = self->inner.vf3();
    int var_r28 = 0;
    while (var_r28 < count) {
        VF2Ret* ret = (VF2Ret*)self->inner.vf2(var_r28);
        ItemStruct* item = (ItemStruct*)ret->ptr;
        int result = fn_27_2A7E08(arg0, (void*)item);
        if (result < 0x2710) {
            if (result == var_r29) {
                if (var_r30 == 0 || ((ItemStruct*)var_r30)->field8bc > item->field8bc) {
                    var_r29 = result;
                    var_r30 = (void*)item;
                }
            } else if (result < var_r29) {
                var_r29 = result;
                var_r30 = (void*)item;
            }
        }
        var_r28++;
    }
    return var_r30;
}
