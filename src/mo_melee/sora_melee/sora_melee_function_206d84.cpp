#pragma force_active on
struct Obj {
    char pad[0x18];
    unsigned int a;
    unsigned int b;
};

extern "C" unsigned long long fn_27_206D84(Obj* self)
{
    return *(unsigned long long*)&self->a;
}
