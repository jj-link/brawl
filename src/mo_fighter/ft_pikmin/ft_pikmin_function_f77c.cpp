#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct Inner {
    u8 pad[5];
    u8 on : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" {
void fn_113_F72C(void* obj, s32 arg);
void fn_113_FD84(s16* destination, const s16* source);
s32 fn_113_F80C(void* obj, s16* data, s32 arg);
}

extern "C" void fn_113_F77C(void* object, const s16* source, s32 arg) {
    u8* self = static_cast<u8*>(object);
    Inner* p = reinterpret_cast<Inner*>(self + 0xC);
    if (source[0] & 1) {
        bool flag = p->on;
        if (flag == true && p->next == 0) {
            fn_113_F72C(p, arg);
        }
    }
    s16 tmp;
    fn_113_FD84(&tmp, source);
    fn_113_F80C(self + 4, &tmp, arg);
}
