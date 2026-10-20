#pragma force_active on
struct Fn27Object
{
    int padding[6];
    int state;
    char entries[1];
};

extern "C" char* fn_27_1ADF80(Fn27Object* self, int index)
{
    int offset = self->state >> 29;
    int adjusted = offset + index;

    if (adjusted < 2)
        adjusted = adjusted;
    else
        adjusted -= 2;

    return self->entries + adjusted * 12;
}
