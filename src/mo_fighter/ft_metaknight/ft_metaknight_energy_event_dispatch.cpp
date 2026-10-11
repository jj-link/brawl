#include <types.h>

extern "C" void fn_111_AEDC(s16*, const s16*);
extern "C" void fn_111_C3AC(s16*, const s16*);
extern "C" void fn_111_C314(void*, const s16*, void*);
extern "C" void fn_111_C078(void*, const s16*, void*);
extern "C" void fn_111_BDDC(void*, const s16*, void*);
extern "C" void fn_111_BB40(void*, const s16*, void*);
extern "C" void fn_111_B8A4(void*, const s16*, void*);
extern "C" void fn_111_B608(void*, const s16*, void*);
extern "C" void fn_111_B378(void*, const s16*, void*);
extern "C" void fn_111_B0E0(void*, const s16*, void*);

extern "C" void fn_111_AB04(void* object, void* context, const s16* event) {
    u8* state = static_cast<u8*>(object);
    s16 mask;
    s16 incoming = *event;
    s16 copy1;
    s16 copy3;
    s16 copy5;
    s16 copy7;
    s16 copy6;
    s16 copy4;
    s16 copy2;
    s16 copy0;
    fn_111_AEDC(&mask, &incoming);
    fn_111_C3AC(&copy0, &mask);
    fn_111_C314(state + 0x208, &copy0, context);
    fn_111_C3AC(&copy1, &mask);
    fn_111_C078(state + 0x1CC, &copy1, context);
    fn_111_C3AC(&copy2, &mask);
    fn_111_BDDC(state + 0x180, &copy2, context);
    fn_111_C3AC(&copy3, &mask);
    fn_111_BB40(state + 0x138, &copy3, context);
    fn_111_C3AC(&copy4, &mask);
    fn_111_B8A4(state + 0xF0, &copy4, context);
    fn_111_C3AC(&copy5, &mask);
    fn_111_B608(state + 0x98, &copy5, context);
    fn_111_C3AC(&copy6, &mask);
    fn_111_B378(state + 0x64, &copy6, context);
    fn_111_C3AC(&copy7, &mask);
    fn_111_B0E0(state + 8, &copy7, context);
}
