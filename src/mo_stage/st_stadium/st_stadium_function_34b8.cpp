#pragma force_active on
struct ST59Obj {
    char pad[0x184];
    unsigned char byte;
    int word;
    float flt;
};

extern "C" void fn_59_34B8(ST59Obj *obj, unsigned char b, int w, float f)
{
    obj->byte = b;
    obj->word = w;
    obj->flt = f;
}
