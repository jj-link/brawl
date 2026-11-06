#pragma force_active on
typedef int s32;
extern s32 fn_8026CE80(void*, void*);
extern int fn_8026BBF0(void*, void*, s32);
extern int fn_8026BDE8(void*, void*, s32);

s32 fn_8026D978(s32 arg0, s32 arg1, s32 arg2, char* p) {
    char buf[0x288];
    s32 r;
    char* b;
    char* o;
    char* q;

    b = buf + 0x100;
    r = (*(s32 (**)(void*, s32, s32, s32))(p + 0xB0))(b, *(s32*)(p + 0xA8), arg0 << 4, arg1 << 4);
    if (r < 0) return r;

    o = b + 4;
    q = p + 0x1C;
    fn_8026BBF0(o, buf, 0x10);
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 8, buf, 0x10);
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 0x80, buf, 0x10);
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 0x88, buf, 0x10);
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BDE8(b + 0x104, buf, 8);
    r = fn_8026CE80(buf, p + 0x50);
    if (r < 0) return r;
    fn_8026BDE8(b + 0x144, buf, 8);
    r = fn_8026CE80(buf, p + 0x84);
    return r & (r >> 31);
}