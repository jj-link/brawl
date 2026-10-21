#include <types.h>
#pragma force_active on

struct Motion {
    float x, y, z;
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(int, float);
};

extern "C" {
    void* getEntity__14ftEntryManagerFUl(u32, u32);
    void fn_27_111B5C(void*, const void*);
    void fn_27_111B38(void*, float);
    void fn_27_114CE4(void*);
    extern const float lbl_27_rodata_F0C;
}

extern "C" void fn_27_109E6C(char* self, u32 kind, const void* v, float f) {
    void* obj;
    void* entry = getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), kind);
    obj = *(void**)((char*)entry + 0x28);
    fn_27_111B5C(obj, v);
    fn_27_111B38(obj, f);
    ((Motion*)((char*)obj + 0xd54))->vf2(0, lbl_27_rodata_F0C);
    fn_27_114CE4(entry);
}
