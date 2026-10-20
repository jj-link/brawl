#pragma force_active on
struct Result {
    unsigned int unknown;
    unsigned int value;
};

class Interface {
public:
    virtual ~Interface();
    virtual Result* get();
};

extern "C" unsigned int fn_27_1E6EA8(void* object) {
    return reinterpret_cast<Interface*>(
        static_cast<char*>(object) + 0x10)->get()->value;
}
