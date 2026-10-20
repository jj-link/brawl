#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

struct FtDiddyFlags {
    u8 pad[5];
    u8 flag : 1;
    u8 other : 7;
    u8 next;
};

extern "C" void fn_115_CFDC(void* object, void* arg);
extern "C" void fn_115_D71C(s16* destination, const s16* source);
extern "C" void fn_115_D0BC(void* object, s16* data, void* arg);

extern "C" void fn_115_D02C(void* self, const s16* src, void* arg) {
    u8* obj = static_cast<u8*>(self);
    u8* p = obj + 0xC;
    if (src[0] & 1) {
        FtDiddyFlags* f = reinterpret_cast<FtDiddyFlags*>(p);
        if ((bool)f->flag == true && f->next == 0) {
            fn_115_CFDC(p, arg);
        }
    }

    s16 tmp;
    fn_115_D71C(&tmp, src);
    fn_115_D0BC(obj + 4, &tmp, arg);
}
