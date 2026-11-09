#pragma force_active on
struct Pair { int x; int y; };
struct Blk { Pair p0; Pair p1; Pair p2; };
extern "C" void* fn_801C07AC(void*);
extern "C" void fn_801C05C0(void*, void*, int);
extern float lbl_805A1AF0;
extern "C" void fn_80077288(unsigned char* self, int arg) {
    if (self[0x6EF]) {
        Blk blk;
        Blk* p = (Blk*)fn_801C07AC(self + 0x728);
        blk = *p;
        *(float*)&blk.p0.y = (float)arg / lbl_805A1AF0;
        fn_801C05C0(self + 0x728, &blk, blk.p2.x);
    }
}