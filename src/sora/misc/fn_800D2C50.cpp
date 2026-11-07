#pragma force_active on
extern "C" void* memset(void*, int, unsigned int);
extern "C" void netReport__FPCce(const char*, ...);
extern int g_NtAIDBitmap;
extern char lbl_80458808[];

struct Slot { unsigned char name[0x218]; };

extern "C" short* fn_800D2C50(char* a, unsigned int id, short* out) {
    if (id != 4 && (!(g_NtAIDBitmap & (1 << id)) || !((a[0xFC9] >> 7) & 1))) {
        *out = 0;
        return out;
    }
    unsigned char* dst = (unsigned char*)out;
    unsigned char* src = ((Slot*)(a + 0x250))[id].name;
    int i = 5;
    memset(out, 0, 12);
    goto cond;
body:
    {
        int c = (dst[0] = src[0]) | (dst[1] = src[1]);
        src += 2;
        dst += 2;
        if (c == 0) goto done;
    }
cond:
    i -= 1;
    if (i >= 0) goto body;
done:
    netReport__FPCce(lbl_80458808, id);
    return out;
}
