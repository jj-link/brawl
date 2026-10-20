#pragma force_active on
struct Result {
    unsigned int reserved;
    unsigned int value;
};

class Interface {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char reserved[16];
    Interface member;
};

extern "C" unsigned int fn_27_F02E4(Object* object) {
    return object->member.get()->value;
}
