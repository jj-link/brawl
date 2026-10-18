#pragma force_active on
struct Fn103Object {
    char pad[0x14];
    int base;
};

extern "C" int fn_103_134AC(Fn103Object* object, void*, int index, int element)
{
    char* entry = (char*)object + (index - object->base) * 4;
    return (*(int**)(entry + 0x20))[element];
}
