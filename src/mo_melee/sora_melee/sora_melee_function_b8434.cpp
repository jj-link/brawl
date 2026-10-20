#pragma force_active on
struct Result {
    unsigned char padding[0x0C];
    unsigned int value;
};

class Receiver {
public:
    virtual ~Receiver();
    virtual Result* get();
};

struct Context {
    unsigned char padding[0x38];
    Receiver* receiver;
};

extern "C" unsigned int fn_27_B8434(Context* __restrict self) {
    return self->receiver->get()->value;
}
