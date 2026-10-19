#pragma force_active on
struct ftSnake;

extern "C" {
ftSnake* fn_122_3EA4(ftSnake* self, short flag);
void __dl__FPv(void* ptr);
}

extern "C" ftSnake* fn_122_3E48(ftSnake* self, short flag) {
    if (self != 0) {
        fn_122_3EA4(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
