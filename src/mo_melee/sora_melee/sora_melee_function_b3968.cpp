#pragma force_active on
class FlagArray {
public:
    virtual ~FlagArray();
    virtual void* at(unsigned int index);
};
struct Work {
    unsigned int padding[6];
    FlagArray* flags;
};
extern "C" void fn_27_B1E6C(void*, const void*);
extern "C" void fn_27_B3968(Work* __restrict work, const void* value, unsigned int index) {
    FlagArray* flags = work->flags;
    fn_27_B1E6C(flags->at(index), value);
}
