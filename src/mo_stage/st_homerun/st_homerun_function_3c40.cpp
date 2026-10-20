#pragma force_active on
struct Global {
    char pad[8];
    void* object;
};

struct Object {
    char pad[0x63];
    unsigned char flag63;
    unsigned char flag64;
    char pad65[3];
    int value68;
    int value6C;
};

extern "C" Global* g_GameGlobal;

extern "C" int fn_88_3C40() {
    Object* object = (Object*)g_GameGlobal->object;
    if (!object)
        return 0;
    if (object->flag63 != 0)
        goto fail;
    if (object->flag64 != 0)
        goto fail;
    int a = object->value68;
    int b = object->value6C;
    if (a != 1)
        goto fail;
    if (b != 1)
        goto fail;
    return 1;

fail:
    return 0;
}
