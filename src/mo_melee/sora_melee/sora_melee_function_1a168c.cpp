#pragma force_active on
extern "C" int fn_27_1A168C(const void *this_) {
    const int *f = (const int*)((const char*)this_ + 8);
    return (*f >> 25) & 1;
}
