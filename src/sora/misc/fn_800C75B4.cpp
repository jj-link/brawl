#pragma force_active on
class gfTask;

extern "C" {
void __dt__6gfTaskFv(gfTask* p, int flag);
void __dl__FPv(void* p);
}

extern "C" gfTask* fn_800C75B4(gfTask* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__6gfTaskFv(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
