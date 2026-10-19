#pragma force_active on
extern "C" int randi__Fl(long);

extern "C" bool fn_27_8E8A4(long x) {
    if (x < 0) {
        return false;
    }
    return randi__Fl(x) == 0;
}
