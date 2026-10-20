#pragma force_active on
class WorkArray {
public:
    virtual ~WorkArray();
    virtual int& at(unsigned int index);
    virtual void unused();
    virtual int size();
};

struct Work {
    unsigned char padding[0x78];
    WorkArray** arrays;
};

extern "C" int fn_27_758F0(Work* work, unsigned int index) {
    if (index >= (unsigned int)(*work->arrays)->size() ||
        (*work->arrays)->size() <= 0) {
        return -1;
    }
    return (*work->arrays)->at(index);
}
