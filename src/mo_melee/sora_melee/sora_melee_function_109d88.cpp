#include <types.h>
#pragma force_active on

typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32, u32);
extern "C" void fn_27_111B5C(void**, const Vec3f*);
extern "C" void fn_27_111B38(void**, float);
extern "C" void fn_27_114308(ftEntry*, u8);

extern "C" void fn_27_109D88(char* self, u32 kind, const Vec3f* v, float f) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), kind);
    void** p = *(void***)((char*)entry + 0x28);
    fn_27_111B5C(p, v);
    fn_27_111B38(p, f);
    fn_27_114308(getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), kind), 2);
}
