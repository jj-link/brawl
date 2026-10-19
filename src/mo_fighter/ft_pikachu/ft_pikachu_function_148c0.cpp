#pragma force_active on

extern "C" void* fn_98_1492C(void*);
extern "C" int fn_98_14878(void*);
extern "C" int fn_98_14854(void*, int);
extern "C" void fn_98_1489C(void*, void*);

extern "C" void fn_98_148C0(void* owner) {
    void* first = fn_98_1492C(owner);
    int second = fn_98_14878(owner);
    if (first) fn_98_14854(first, second);
    if (second) fn_98_1489C(reinterpret_cast<void*>(second), first);
}
