#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct Elem {
    s32 unk0;
    s32 unk4;
} Elem;

typedef struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Obj;

extern s32 fn_8035A590(s32);
extern Elem* fn_8035A598(s32, s32);

static inline s32 findNul(const s8* q, s32 len) {
    s32 i = 0;
    for (; i < len; i++, q++) {
        if (*q == 0) {
            return i + 1;
        }
    }
    return -1;
}

s32 fn_8038B278(Obj* self, u8* p, s32 len) {
    s32 count = fn_8035A590(self->unk8);
    s32 i;
    for (i = 0; i < count; i++) {
        Elem* e = fn_8035A598(self->unk8, i);
        switch (e->unk4) {
        case 1:
            p += 1;
            len -= 1;
            break;
        case 2:
            p += 2;
            len -= 2;
            break;
        case 0: {
            s32 c;
            if (len < 1) {
                return 0;
            }
            c = *p;
            p++;
            len--;
            if (c == 0xFF) {
                s32 n = findNul((s8*)p, len);
                if (n == -1) {
                    return 0;
                }
                p += n;
                len -= n;
            }
            break;
        }
        default:
            return 0;
        }
        if (len < 0) {
            return 0;
        }
    }
    return 1;
}
