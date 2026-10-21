#pragma force_active on
struct Data {
    char pad[0x1C];
    int offset;
};
struct Res {
    Data* data;
    Res(Data* p) : data(p) {}
};
struct Name {
    int data;
    Name(const Name& n) : data(n.data) {}
};
extern "C" void fn_8018CFAC(Res*, const Name&, int);
inline Data* resolve(Res* self)
{
    Data* base = self->data;
    int offset = base->offset;
    return offset ? (Data*)((char*)base + offset) : 0;
}
extern "C" void fn_8018EFAC(Res arg0, const Name& arg1)
{
    Data* resolved = resolve(&arg0);
    int loaded = arg1.data;
    Res result(resolved);
    Name value(arg1);
    fn_8018CFAC(&result, value, loaded);
}
