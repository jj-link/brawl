#pragma force_active on
struct GameWatchState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_107_EFDC(const GameWatchState* object) {
    return object->value;
}
