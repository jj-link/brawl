#pragma force_active on
struct Entry {
    void* object;
    int priority;
};

extern "C" int fn_2_24DE0(void*);

extern "C" int fn_2_28620(const Entry* a, const Entry* b) {
    int result = b->priority - a->priority;
    return result != 0
        ? result
        : fn_2_24DE0(a->object) - fn_2_24DE0(b->object);
}
