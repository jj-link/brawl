#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftEntry;

extern "C" s32 fn_27_1190D0(void*);
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" unsigned char fn_27_11535C(char* p);

extern "C" unsigned char fn_27_10B118(char* self, u32 arg) {
    if (fn_27_1190D0(*(void**)(self + 0x154)) == 0) {
        return 0;
    }
    return fn_27_11535C((char*)getEntity__14ftEntryManagerFUl(*(void**)(self + 0x154), arg));
}
