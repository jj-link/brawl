#pragma force_active on
struct Entry {
    unsigned char flag : 1;
    unsigned char rest : 7;
};

class ByteArray {
public:
    virtual void unused();
    virtual Entry& at(int index);
};

struct Work {
    int unused;
    ByteArray* array;
    int index;
};

extern "C" void fn_27_76CDC(Work* work, int index) {
    Entry& entry = work->array->at(index <= -1 ? work->index : index);
    entry.flag = 0;
}
