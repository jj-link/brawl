#pragma force_active on
struct SnakeState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_122_12D9C(const SnakeState* object) {
    return object->value;
}
