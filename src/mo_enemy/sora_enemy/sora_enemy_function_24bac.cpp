#pragma force_active on

struct V2 {
    float x, y;
};

struct V3 {
    float x, y, z;
};

extern "C" {
void getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
    V3*, void*, unsigned long, bool);
int fn_41_247FC(char*, V2*);
void fn_41_24A48(void*, int, void*);

void fn_41_24BAC(void* acc, unsigned long target, void* p3) {
    V3 pos;
    getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
        &pos, acc, target, true);
    fn_41_24A48(acc, fn_41_247FC((char*)acc, (V2*)&pos), p3);
}
}
