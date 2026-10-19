#pragma force_active on
struct Object {
    unsigned char padding0[0xCC];
    void* child;
};

extern "C" void fn_27_252938(Object* self)
{
    if (*((unsigned char*)self + 0x288)) {
        *(int*)((char*)self + 0x254) = 2;
        ((unsigned char*)self->child)[0x1378] = 5;
    } else {
        *(int*)((char*)self + 0x254) = 3;
        ((unsigned char*)self->child)[0x1378] = 4;
    }
}
