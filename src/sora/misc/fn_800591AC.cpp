#pragma force_active on
typedef unsigned short u16;

extern "C" void* fn_8004E5D8(void*, void*);
extern "C" void* g_GameGlobal;

extern "C" int fn_800591AC(int arg0) {
    int result;
    u16 max_val;
    u16 sum;
    int i;
    void* ptr;
    u16 val;

    result = 0;
    max_val = 0;
    sum = 0;
    i = 0;
    do {
        ptr = fn_8004E5D8(g_GameGlobal, (void*)i);
        val = *(u16*)((char*)ptr + 0xC8);
        if (val > max_val) {
            max_val = val;
        }
        i += 1;
        sum += val;
    } while (i < 0x23);

    switch (arg0) {
        case 0x6C:
            if (max_val >= 0xA) {
                result = 1;
            }
            break;
        case 0x21:
            if (sum >= 0x190) {
                result = 1;
            }
            break;
    }
    return result;
}
