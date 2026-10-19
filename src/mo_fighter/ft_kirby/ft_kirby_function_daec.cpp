#pragma force_active on
extern "C" unsigned int fn_96_1DA24(void*);
extern "C" unsigned int fn_27_135A70(void*);

extern "C" unsigned int fn_96_DAEC(void* self)
{
    if (fn_96_1DA24(static_cast<unsigned char*>(self) + 0x1B72C) == 1)
        return 1;

    return fn_27_135A70(self);
}
