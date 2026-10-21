#pragma force_active on
extern "C" int fn_80218D54();

extern "C" int fn_8002B504() {
    return fn_80218D54() == 1;
}
