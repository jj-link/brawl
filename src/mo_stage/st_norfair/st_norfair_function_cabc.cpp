#pragma force_active on
extern "C" {
void fn_54_2CB0(void*, int);
void __dl__FPv(void*);

void* fn_54_CABC(void* self, int flag)
{
    if (self != 0) {
        fn_54_2CB0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
