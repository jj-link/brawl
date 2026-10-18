#pragma force_active on
class muMenu {
public:
    int getNumCharColor(int, int, int);
};

extern "C" int fn_10_110F8(int unused, int a, int b, int c) {
    return ((muMenu*)a)->getNumCharColor(a, b, c);
}
