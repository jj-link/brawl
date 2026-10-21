#pragma force_active on
extern "C" {

typedef signed int s32;

s32 fn_8006B618(s32, s32);

s32 fn_800B8EDC(void* arg0, void* arg1) {
    return fn_8006B618(*(s32*)((char*)arg0 + 8), *(s32*)((char*)arg1 + 0x10));
}

}
