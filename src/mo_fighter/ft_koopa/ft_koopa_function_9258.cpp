#pragma force_active on
struct FtKoopaCounterHolder {
    char pad[0xc];
    int* counts;
};

extern "C" void fn_102_9258(FtKoopaCounterHolder* holder, unsigned int index) {
    holder->counts[index] = holder->counts[index] - 1;
}
