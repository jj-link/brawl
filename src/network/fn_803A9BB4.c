#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct StrBuf {
    u8* m_ptr;
    u8* m_end;
    u32 m_pad;
    u32 m_id;
};

s32 fn_803A9864(u8*);
s32 fn_803A9FF8(u16*);

s32 fn_803A9BB4(struct StrBuf* a0, u8* a1, u32 a2) {
    if (a0 == 0 || a1 == 0) {
        return 0xa;
    }
    if (a2 == 1) {
        a0->m_ptr = a1;
        a0->m_end = a1 + fn_803A9864(a1);
    } else if (a2 == 2) {
        a0->m_ptr = a1;
        a0->m_end = a1 + (fn_803A9FF8((u16*)a1) * 2);
    } else {
        return 0xa;
    }
    a0->m_id = a2;
    return 0;
}
