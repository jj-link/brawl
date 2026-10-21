#pragma force_active on

extern "C" {
extern char lbl_20_data_A0[];
void __dl__FPv(void*);
void fn_20_120(void*, int);
void fn_8009A060(void*, int);
}

struct Inner {
    virtual ~Inner();
    unsigned short active;
    short refs;
};

extern "C" void* fn_20_930(char* self, int flags) {
    if (self) {
        Inner* inner = *(Inner**)(self + 0xC);
        *(char**)(self + 0x0) = lbl_20_data_A0;
        *(char**)(self + 0x8) = lbl_20_data_A0 + 0x18;
        if (inner->active != 0) {
            inner->refs -= 1;
            if (inner->refs == 0) {
                delete inner;
            }
        }
        *(void**)(self + 0xC) = 0;
        fn_8009A060(self + 0x8, 0);
        fn_20_120(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
