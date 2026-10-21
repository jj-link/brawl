#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int upper : 6;
    unsigned int value : 6;
    unsigned int lower : 20;
};

extern "C" void fn_27_19B798(Object* p, unsigned int value)
{
    p->value = value;
}
