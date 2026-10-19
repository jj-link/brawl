#pragma force_active on
extern "C" {
void fn_94_1AD0(void* self, short flag);
void* fn_94_1A74(void* p, short flag);
}
void operator delete(void* p);

extern "C" void* fn_94_1A74(void* p, short flag) {
    if (p != 0) {
        fn_94_1AD0(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
