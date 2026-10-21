#pragma force_active on
extern "C" {
void* fn_801B77F8(void*);
void fn_801B7EE8(void*, void*, void*);
void fn_801B7F54(void*, void*);
void* fn_801CC874(void*);
extern char fn_801CC650[];
}

extern "C" int fn_801CC75C(char* self) {
    void* a = fn_801B77F8(self);
    fn_801B7EE8(a, self + 0x36C, fn_801CC650);
    void* b = fn_801CC874(self);
    void* c = fn_801B77F8(b);
    fn_801B7F54(c, self + 0x36C);
    return 0;
}
