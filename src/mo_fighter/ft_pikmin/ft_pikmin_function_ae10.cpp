#pragma force_active on
extern "C" void fn_113_23FD8(void*, void*);
extern "C" void fn_113_25530(void*);
extern "C" void fn_27_6654(void*, int, void*);

struct Inner { char pad[0x28]; void* v; void* get() { return v; } };
struct Data { char pad[8]; Inner* in; Inner* getIn() { return in; } };
struct Self {
    char pad[0x1FD08]; char list[4];
    void* getList() { return list; }
};

extern "C" void fn_113_AE10(Self* self, int arg, Data* data)
{
    if (arg == 0) {
        fn_113_23FD8(self->getList(), data->getIn()->get());
        fn_113_25530(self->getList());
    }
    fn_27_6654(self, arg, data);
}
