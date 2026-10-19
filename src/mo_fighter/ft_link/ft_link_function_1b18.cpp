#pragma force_active on
extern "C" {
void* fn_93_1AD8(void* p, short flags);
void __dl__FPv(void* p);

void* fn_93_1B18(void* p, short flags) {
    if (p != 0) {
        fn_93_1AD8(p, short(0));
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}