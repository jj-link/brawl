#pragma force_active on
struct Container {
    virtual void unused();
    virtual void* get(int index);
    virtual void unused2();
    virtual int size();
};

extern "C" void fn_96_1F8A4(void* dst, const void* src);

extern "C" void fn_96_1EFF0(Container* self, int start,
                            const void* value, unsigned int countArg)
{
    int count = countArg;
    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i)
        fn_96_1F8A4(self->get(start + i), value);
}
