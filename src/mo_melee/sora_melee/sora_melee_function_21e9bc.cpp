#include <types.h>
#include <ai/ai_mgr.h>
#pragma force_active on

typedef struct FState {
    u8 pad0[0x50];
    u32 unk50;
    u8 pad54[0x8];
    f32 unk5C;
    f32 unk60;
    u8 pad64[0x44];
    s16 unkA8;
    u8 padAA[0x2];
    s32 unkAC;
    u8 padB0[0x4];
    s32 unkB4;
    u8 padB8[0x4];
    void* unkBC;
    u8 padC0[0x1C];
    f32 unkDC;
    u8 padE0[0xDA];
    u8 unk1BA;
} FState;

extern "C" {
FState* fn_27_1F1F58(s8* fighterId);
s32 fn_27_1F2D0C(s8* fighterId);
s32 fn_27_20B568(FState* st);
s32 fn_27_20B6AC(FState* st, u32 a, s32 b);
f32 fn_27_20B758(FState* st, s8* id, f32 f);
f32 fn_27_20BC28(FState* st, s8* id);
f32 fn_27_20BCBC(FState* st, void* vec, f32 f);
u16 fn_27_21F7E4(void* a, s32 b, s32 c);
}

extern "C" const float lbl_27_rodata_3290[];

extern "C" s32 fn_27_21E9BC(FState* p, void* arg1, s8* arg2, s32 script, u32 flags, void* arg5) {
    const f32* c;
    FState* s;
    f32 f31;
    f32 t;
    f32* bc;
    u32 f50;
    u8 b8;

    c = lbl_27_rodata_3290;
    s = fn_27_1F1F58(arg2);

    if (!(flags & 1)) {
        switch (script & 0x7FF0) {
        case 0x1090:
            return 1;
        }
    }
    if (flags & 2) goto L_EA9C;
    if ((u32)script == 0x603B) {
        if (p->unkAC == 0x1D || p->unkAC == 0x1E || p->unkAC == 0x1F) goto L_EAE8;
    }
    if (((u32)script & 0xF000) == 0x1000 || ((u32)script & 0xF000) == 0x6000) return 1;
    switch (script & 0x7FF0) {
    case 0x2020:
    case 0x2030:
    case 0x3030:
        return 1;
    }
    goto L_EAE8;

L_EA9C:
    if (flags & 4) goto L_EAC8;
    switch (script & 0x7FF0) {
    case 0x1070:
    case 0x1080:
        return 1;
    }
L_EAC8:
    if (flags & 0x10) goto L_EAE8;
    switch (script & 0x7FF0) {
    case 0x1050:
        return 1;
    }

L_EAE8:
    if (flags & 8) goto L_EB08;
    switch (script & 0x7FF0) {
    case 0x1070:
        return 1;
    }

L_EB08:
    if (p->unkA8 > 0) goto L_EB44;
    switch (script & 0x7FF0) {
    case 0x50:
    case 0x80:
    case 0x1070:
        return 1;
    }

L_EB44:
    if (flags & 0x20) {
        if (!(p->unkDC < c[25])) {
            b8 = s->unk1BA;
            if (b8 != 9 && (u8)(b8 + 0xFC) > 1) goto L_EB90;
        }
    }
    switch (script & 0x7FF0) {
    case 0x3020:
        return 1;
    }

L_EB90:
    if (flags & 0x200) goto L_EBB0;
    switch (script & 0x7FF0) {
    case 0x70:
        return 1;
    }

L_EBB0:
    f50 = p->unk50;
    if ((f50 & 0x80) || (f50 & 0x100)) {
        switch (script) {
        case 0x21:
        case 0x31:
        case 0x55:
        case 0x1040:
        case 0x1050:
        case 0x10D0:
        case 0x3030:
            return 1;
        }
    }

    if (f50 & 1) {
        switch (script & 0x7FF0) {
        case 0x20:
        case 0x30:
        case 0x40:
        case 0x70:
        case 0x10A0:
        case 0x3010:
        case 0x3020:
        case 0x3030:
        case 0x3040:
        case 0x3050:
            return 1;
        }
    }

L_ECAC:
    if (fn_27_20B568(p) == 0) {
        switch (script) {
        case 0x10A0:
            return 1;
        case 0x1140:
            if (p->unkA8 < 1) return 1;
            break;
        case 0x2020:
            bc = (f32*)p->unkBC;
            if (p->unk5C < bc[0]) {
                if (p->unk60 < c[9] + bc[1]) return 1;
            } else {
                if (p->unk60 < c[9] + bc[3]) return 1;
            }
            break;
        }
    }

    if (fn_27_20B568(s) == 0) {
        switch (script) {
        case 0x80:
            return 1;
        }
    }
    if (s->unkB4 == 0xBE) {
        if (((u32)script & 0xF000) == 0x1000) return 1;
        switch (script & 0x7FF0) {
        case 0x50:
            return 1;
        }
    }
    if (fn_27_20B6AC(p, 2, 0x12) != 0) {
        switch (script) {
        case 0x1140:
        case 0x10A0:
            return 1;
        }
    }
    if (fn_27_1F2D0C(arg2) == 0) {
        switch (script) {
        case 0x3080:
        case 0x10F0:
        case 0x1060:
        case 0x30B0:
        case 0x3090:
            return 1;
        }
        if (*(s32*)((u8*)g_aiMgr + 0x370) == 0x1C) {
            switch (script) {
            case 0x3020:
            case 0x1110:
            case 0x10A0:
            case 0x71:
            case 0x72:
            case 0x3010:
            case 0x1160:
            case 0x3050:
            case 0x3040:
            case 0x3030:
            case 0x30A0:
            case 0x3060:
                return 1;
            }
        }
    }

    switch (script) {
    case 0x21:
    case 0x31:
        goto L_EF80;
    case 0x22:
    case 0x32:
        goto L_EF34;
    case 0x10F0:
        goto L_EFB0;
    case 0x3030:
        goto L_F010;
    case 0x3060:
        goto L_F024;
    default:
        goto L_F038;
    }

L_EF34:
    f31 = *(f32*)((u8*)arg1 + 0x18);
    t = fn_27_20B758(p, arg2, c[1]);
    if (t > f31) goto L_F038;
    f31 = *(f32*)((u8*)arg1 + 0x18);
    t = fn_27_20BCBC(p, (u8*)p + 0x5C, -fn_27_20BC28(p, arg2));
    if (t < f31) return 1;
    goto L_F038;

L_EF80:
    f31 = *(f32*)((u8*)arg1 + 0x14);
    t = fn_27_20BCBC(p, (u8*)p + 0x5C, -fn_27_20BC28(p, arg2));
    if (t < f31) return 1;
    goto L_F038;

L_EFB0:
    if (!(s->unk50 & 0x20000)) {
        if (s->unk1BA != 6 || fn_27_21F7E4(arg1, 9, 0) == 0) return 1;
    }
    if (arg5 == 0) goto L_F038;
    if ((u32)script == *(u16*)((u8*)arg5 + 0x78) || (u32)script == *(u16*)((u8*)arg5 + 0x7C)) return 1;
    goto L_F038;

L_F010:
    if (p->unk50 & 4) return 1;
    goto L_F038;

L_F024:
    if (p->unkB4 == 0x49) return 1;

L_F038:
    return 0;
}
