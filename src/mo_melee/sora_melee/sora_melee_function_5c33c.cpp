#pragma force_active on
struct State {
    unsigned char padding[0x2C];
    unsigned char request;
    unsigned int value;
};

class gfSlowManager {
public:
    static void removeRequest(const unsigned char&);
};

inline void removeSlowRequest(const unsigned char& request) {
    unsigned char copy = request;
    gfSlowManager::removeRequest(copy);
}

extern "C" void fn_27_5C33C(State* self) {
    if (self->request != 0xFF) {
        removeSlowRequest(self->request);
        self->request = 0xFF;
    }
    self->value = 0;
}
