#pragma force_active on
struct Inner { char pad[0x28]; void* val; void* get() { return val; } };
struct Arg { char pad[8]; Inner* inner; Inner* getIn() { return inner; } };
struct Owner {
    char pad[0x1FD08];
    char list[1];
    void* getList() { return list; }
};
extern "C" {
void fn_113_23FD8(void*, void*);
void fn_113_25530(void*);
void fn_27_6678(void*, int, int, Arg*);

void fn_113_AD98(Owner* self, int a, int b, Arg* arg) {
    if (a == 0) {
        fn_113_23FD8(self->getList(), arg->getIn()->get());
        fn_113_25530(self->getList());
    }
    fn_27_6678(self, a, b, arg);
}
}
