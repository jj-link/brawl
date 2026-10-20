#pragma force_active on
struct Flags { unsigned int pad[2]; unsigned int flags; };
extern "C" unsigned int fn_27_19C8EC(Flags* f) {
    return (f->flags >> 25) & 1;
}
