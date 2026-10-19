#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69868(void*, short);

extern "C" {
void* fn_41_698D4(void* self, short flag) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0x278, -1);
        fn_41_69868((char*)self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
