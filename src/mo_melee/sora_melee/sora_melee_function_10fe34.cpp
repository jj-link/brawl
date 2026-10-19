#pragma force_active on
extern "C" void fn_800765B0(void*, void*, int);
extern void* g_sndSystem;

struct Obj {
    unsigned char pad[0x78];
    void* field78;
    unsigned char field7C;
};

extern "C" void fn_27_10FE34(Obj* obj) {
    fn_800765B0(g_sndSystem, obj->field78, 0);
    obj->field7C = 0;
}
