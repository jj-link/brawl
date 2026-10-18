#pragma force_active on
static inline void* at(void* p, int off) {
    return *(void**)((char*)p + off);
}

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void*, void*);
};

extern "C" {
void fn_800B753C(void*, float);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
extern const char lbl_24_data_3D0[];
extern const float lbl_24_rodata_18;
extern const float lbl_24_rodata_1C;

void fn_24_1030(void* self) {
    VObj* obj = (VObj*)at(at(self, 0x44), 0x48);
    void* arg = at(at(self, 0x48), 0x0c);
    obj->v11(at(obj, 0xe4), arg);

    VObj* obj2 = (VObj*)at(at(self, 0x44), 0x48);
    void* arg2 = at(at(self, 0x4c), 0x0c);
    obj2->v11(at(obj2, 0xe4), arg2);

    changeAnimN__8MuObjectFPCc(at(self, 0x48), lbl_24_data_3D0);
    fn_800B753C(at(self, 0x48), lbl_24_rodata_18);
    setUpdateRate__16gfModelAnimationFf(at(at(self, 0x48), 0x14), lbl_24_rodata_1C);
}
}
