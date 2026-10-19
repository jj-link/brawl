#pragma force_active on
typedef unsigned int u32;

struct fn27VirtBase {
    virtual void unk0();
    virtual u32* unkC(void* p);
};

extern "C" void fn_27_51FB4(fn27VirtBase* obj, u32* src, void* arg) {
    u32* dst = obj->unkC(arg);
    *dst = *src;
}
