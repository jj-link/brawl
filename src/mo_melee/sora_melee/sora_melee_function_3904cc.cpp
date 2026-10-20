#pragma force_active on
struct S { unsigned a : 12; signed b : 6; };
extern "C" int fn_27_3904CC(const void * self) {
    const S * s = reinterpret_cast<const S *>(reinterpret_cast<const char *>(self) + 8);
    return s->b;
}
