#pragma force_active on
extern "C" {

struct FnSrc_8000D530 {
    unsigned short m0;
    unsigned short m2;
    char pad[8];
    void* mC;
};

struct FnDst_8000D530 {
    void* m0;
    void* m4;
};

void fn_8000D530(FnDst_8000D530* dst, FnSrc_8000D530* src, int index) {
    if (index < src->m2 && index >= 0) {
        dst->m4 = (char*)src->mC + index * 0xC;
        dst->m0 = src;
    } else {
        dst->m0 = src;
        dst->m4 = 0;
    }
}

}
