#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct grGimmick {
    char pad0[0x158];
    u8 unk158;
    char pad159[7];
    char* unk160;
    u32 unk164;
    s32 unk168;
    u32 unk16C;
} grGimmick;

typedef struct GimmickCmd {
    s32 id;
    char pad4[4];
    u8 flag8;
    u8 flag9;
} GimmickCmd;

extern "C" {
void fn_40_352BC(grGimmick* self, void* entry);
void startGimmickSE__9grGimmickFUl(void* self, u32 index);
}

extern "C" void fn_40_356AC(grGimmick* arg0, GimmickCmd* arg1) {
    s32 id = arg1->id;
    if (id <= 0x2A || id >= 0x2E) {
        return;
    }
    if (arg0->unk158 != 0) {
        return;
    }
    if (id == 0x2B) {
        if ((u32)(arg0->unk168 + 1) < arg0->unk164) {
            arg1->flag8 = 1;
        } else {
            arg1->flag8 = 0;
        }
        if (arg0->unk168 != 0) {
            arg1->flag9 = 1;
        } else {
            arg1->flag9 = 0;
        }
    }
    if (id == 0x2C) {
        arg0->unk16C = arg0->unk168 + 1;
        if (arg0->unk16C >= arg0->unk164) {
            arg0->unk16C = arg0->unk168;
            startGimmickSE__9grGimmickFUl(arg0, 2);
        } else {
            fn_40_352BC(arg0, arg0->unk160 + arg0->unk16C * 0xC);
        }
    }
    if (id == 0x2D) {
        arg0->unk16C = arg0->unk168 - 1;
        if (arg0->unk16C >= arg0->unk164) {
            arg0->unk16C = arg0->unk168;
            startGimmickSE__9grGimmickFUl(arg0, 2);
        } else {
            fn_40_352BC(arg0, arg0->unk160 + arg0->unk16C * 0xC);
        }
    }
}
