#pragma force_active on
extern "C" {
void fn_8019D950(void* p);
}

extern "C" void fn_10_EFA0(void* unused, void** p) {
    fn_8019D950(p[4]);
}
