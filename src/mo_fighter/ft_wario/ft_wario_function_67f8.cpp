#pragma force_active on
extern "C" void fn_27_19C818(void*, short);

struct ftWarioObj {
    int unk0;
};

extern "C" {
void* fn_110_67F8(ftWarioObj* self, short flag) {
    if (self != 0) {
        fn_27_19C818(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
