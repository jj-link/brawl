#pragma force_active on
struct Value {
    int a;
    int b;
};

class Container {
public:
    virtual void reserved();
    virtual Value* get(int index);
    virtual void reserved2();
    virtual int size();
};

extern "C" void fn_73_CDB4(Container* self, int start,
                           const Value* value, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i)
    {
        *self->get(start + i) = *value;
    }
}
