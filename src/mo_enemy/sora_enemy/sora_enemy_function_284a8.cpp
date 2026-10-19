#pragma force_active on
struct acCmdArgConv;

template <typename T>
struct soArrayContractibleTable {
    ~soArrayContractibleTable();
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_284A8(
    soArrayContractibleTable<const acCmdArgConv>* self, short flag)
{
    if (self != 0) {
        if (self != 0) {
            self->~soArrayContractibleTable();
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
