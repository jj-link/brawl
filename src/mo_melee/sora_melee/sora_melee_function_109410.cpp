#pragma force_active on
extern "C" {
extern void* g_ftAudienceManager;
void fn_27_10FC1C(void*);
void fn_27_11A418(void*, int);
}

extern "C" void fn_27_109410(void* self) {
    fn_27_10FC1C(g_ftAudienceManager);
    fn_27_11A418(*(void**)((char*)self + 0x154), 0);
}
