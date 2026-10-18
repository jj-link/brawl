#pragma force_active on
extern "C" long long fn_56_5490() {
    union {
        long long ll;
        int i[2];
    } u;
    u.i[0] = 0;
    u.i[1] = 0;
    return u.ll;
}
