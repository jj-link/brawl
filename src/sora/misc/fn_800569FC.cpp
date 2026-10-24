#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void* fn_8004E5B8(char*);
extern "C" void fn_8004F7E0(int);
extern "C" void fn_8004FB48(unsigned int);
extern "C" void fn_80052704(u16, u32);
extern "C" void fn_800528D4(u16, u32);
extern "C" void fn_80052AC0(u16, u32, u16, u16, u16, u16, u16, void*);
extern "C" void fn_80052C78(u16, u32);
extern "C" char* g_GameGlobal;
extern "C" u16 lbl_80406E98[5];

extern "C" void fn_800569FC(int arg0, int arg1, u32 arg2) {
    switch (arg1) {
    case 5: {
        u32* p = (u32*)fn_8004E5B8(g_GameGlobal);
        int i = ((int)arg2 - 1) * 2;
        p[i / 32] |= 1u << (i % 32);
        break;
    }
    case 3: {
        u32* p = (u32*)fn_8004E5B8(g_GameGlobal);
        int i = ((int)arg2 + 2) * 2;
        p[i / 32] |= 1u << (i % 32);
        break;
    }
    case 1:
        fn_80052704((u16)arg2, 1);
        fn_800528D4((u16)arg2, 1);
        break;
    case 0: {
        u16 data[5];
        u16* p = lbl_80406E98;
        data[0] = *p++;
        data[1] = *p++;
        data[2] = *p++;
        data[3] = *p++;
        data[4] = *p;
        u16 v = data[arg2 - 1];
        fn_80052AC0(v, 1, data[4], data[3], data[2], data[1], data[0], lbl_80406E98);
        fn_80052C78(v, 1);
        break;
    }
    case 2:
        fn_8004FB48(arg2);
        break;
    case 4:
        fn_8004F7E0(arg2);
        break;
    }
}
