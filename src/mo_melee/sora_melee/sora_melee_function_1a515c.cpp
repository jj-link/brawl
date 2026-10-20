#pragma force_active on
extern "C" int fn_27_1A515C(void* obj) {
    union {
        int word;
        struct {
            unsigned int : 10;
            signed int value : 5;
            unsigned int : 17;
        };
    } u;
    u.word = *(int*)((char*)obj + 8);
    return u.value;
}
