#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void* fn_8004E5D8(void*, void*);
extern "C" void* fn_8004E634(void*);
extern "C" void* fn_8004E658(void*);
extern "C" void* fn_8004E778(void*);
extern "C" void* g_GameGlobal;

extern "C" int fn_800587FC(int arg0) {
    int result;
    u32 val;
    u32 divided;
    u32 sum;
    int i;
    void* ptr;
    
    result = 0;
    val = *(u32*)fn_8004E778(g_GameGlobal);
    divided = *(u32*)fn_8004E634(g_GameGlobal) / 60 / 60;
    sum = 0;
    i = 0;
    do {
        ptr = fn_8004E5D8(g_GameGlobal, (void*)i);
        i += 1;
        sum += *(u32*)((char*)ptr + 0x80);
    } while (i < 0x23);
    
    switch (arg0) {
        case 0x1a:
            if (val >= 0x3e8) result = 1;
            break;
        case 0x2:
            if (val >= 0x7d0) result = 1;
            break;
        case 0x7a:
            if (val >= 0x1f4) result = 1;
            break;
        case 0x4f:
            if (divided >= 0x1e) result = 1;
            break;
        case 0x73:
            if (divided >= 0x32) result = 1;
            break;
        case 0x27:
            if (divided >= 0x64) result = 1;
            break;
        case 0x51:
            if (*(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)0xC) + 0x64) >= 5)
                result = 1;
            break;
        case 0x48:
            if (*(u32*)fn_8004E658(g_GameGlobal) >= 0xa)
                result = 1;
            break;
        case 0x77:
            if (sum >= 0x3e8) result = 1;
            break;
        case 0x5b:
            if (sum >= 0x1388) result = 1;
            break;
        case 0x50:
            break;
    }
    return result;
}
