#pragma force_active on
extern "C" {
void fn_801ECD70(void*, void*, void*);

void* fn_80178568(void* arg0, void* arg1, void* arg2) {
    fn_801ECD70(arg1, arg2, arg0);
    return arg0;
}
}
