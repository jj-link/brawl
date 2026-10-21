#pragma force_active on
extern "C" {
extern void fn_80135950(void*, void*, int);

void fn_80135BA0(void* arg0, int arg1) {
    fn_80135950(arg0, (char*)arg0 + 0x14, arg1);
}
}
