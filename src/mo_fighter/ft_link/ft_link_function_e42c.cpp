#pragma force_active on
typedef signed short s16;
typedef signed int s32;

extern "C" {
void fn_93_E3DC(void* obj, void* arg);
s16* fn_93_E94C(s16* destination, const s16* source);
s32 fn_93_E4BC(void* obj, const s16* data, void* arg);
}

namespace {
struct LinkSub {
    unsigned char prefix[5];
    unsigned char flag : 1;
    unsigned char otherFlags : 7;
    unsigned char next;
};
}

extern "C" void fn_93_E42C(unsigned char* self, const s16* src, void* arg) {
    s16 tmp[4];
    LinkSub* sub = reinterpret_cast<LinkSub*>(self + 0xC);
    if (src[0] & 1) {
        bool f = sub->flag;
        if (f == true && sub->next == 0) {
            fn_93_E3DC(sub, arg);
        }
    }
    fn_93_E94C(tmp, src);
    fn_93_E4BC(self + 4, tmp, arg);
}
