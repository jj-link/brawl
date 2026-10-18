#pragma force_active on
extern "C" {
struct Fn119Obj {
    char pad[0xC];
    int* counts;
};

void fn_119_99F4(Fn119Obj* obj, int index)
{
    obj->counts[index]++;
}
}
