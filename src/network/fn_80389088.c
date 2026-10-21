#pragma force_active on
extern int fn_803FCAA8(const char* a, const char* b);

int fn_80389088(const char** a, const char** b) {
    if (*a == 0) {
        goto done;
    }
    if (*b != 0) {
        goto call;
    }
done:
    return 1;
call:
    return fn_803FCAA8(*a, *b);
}
