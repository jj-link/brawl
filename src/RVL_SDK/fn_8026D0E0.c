#pragma force_active on
typedef int s32;
extern int fn_8026BBF0(void*, void*, s32);
extern int fn_8026BDE8(void*, void*, s32);
extern s32 fn_8026CE80(void*, void*);

s32 fn_8026D0E0(s32 arg0, s32 arg1, char* p) {
    char buf[0x288];
    s32 r;
    char* o;
    char* q;
    r = (*(s32 (**)(void*, s32, s32, s32))(p + 0xAC))(buf + 0x100, *(s32*)(p + 0xA8), arg0 << 5, arg1 << 3);
    if (r < 0) return r;
    o = buf + 0x104;
    q = p + 0x1C;
    fn_8026BBF0(o, buf, *(s32*)(q + 4));
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 8, buf, *(s32*)(q + 4));
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 0x10, buf, *(s32*)(q + 4));
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    fn_8026BBF0(o + 0x18, buf, *(s32*)(q + 4));
    r = fn_8026CE80(buf, q);
    if (r < 0) return r;
    o = p + 0x50;
    fn_8026BDE8(buf + 0x204, buf, *(s32*)(o + 4));
    r = fn_8026CE80(buf, o);
    if (r < 0) return r;
    o = p + 0x84;
    fn_8026BDE8(buf + 0x244, buf, *(s32*)(o + 4));
    r = fn_8026CE80(buf, o);
    return r & (r >> 31);
}
