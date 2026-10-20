#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

struct Flags {
    u8 enabled : 1;
    u8 rest : 7;
};

extern "C" void fn_97_E0B4(void* a, void* b);
extern "C" void fn_97_E624(s16* destination, const s16* source);
extern "C" s32 fn_97_E194(void* a, s16* b, void* c);

extern "C" void fn_97_E104(void* object, const s16* index, void* argument) {
    u8* obj = static_cast<u8*>(object);
    s16 local[4];
    u8* p = obj + 0xC;

    if ((*index & 1) != 0) {
        Flags* f = reinterpret_cast<Flags*>(p + 5);
        bool on = static_cast<bool>(f->enabled);
        if (on == true && p[6] == 0) {
            fn_97_E0B4(p, argument);
        }
    }

    fn_97_E624(local, index);
    fn_97_E194(obj + 4, local, argument);
}
