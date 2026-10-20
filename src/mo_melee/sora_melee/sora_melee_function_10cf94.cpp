#pragma force_active on
typedef unsigned int u32;
typedef float f32;

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116F08(ftEntry* entry, f32 value, u32 a, u32 b);

extern "C" void fn_27_10CF94(void* self, f32 value, u32, u32 a, u32 b) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_116F08(entry, value, a, b);
}
