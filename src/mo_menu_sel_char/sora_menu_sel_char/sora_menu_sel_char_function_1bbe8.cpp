#pragma force_active on
struct S { int pad[5]; void* f14; };
struct T { int pad[0x1b4/4]; void* f1b4; };

extern "C" void* fn_10_1BBE8(S* arg) {
    return ((T*)arg->f14)->f1b4;
}
