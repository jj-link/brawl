#pragma force_active on
extern "C" void fn_113_CEF4(void*, void*, void*);

struct Tmp {
    unsigned char data[24];
};

extern "C" Tmp* fn_113_D020(void* a, void* b) {
    Tmp tmp;
    fn_113_CEF4(&tmp, a, b);
    return &tmp;
}
