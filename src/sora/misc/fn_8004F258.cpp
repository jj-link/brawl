#pragma force_active on
extern "C" void fn_8004F258(int* a, unsigned b, unsigned c) {
    unsigned flag = 0;
    if (b > c || (unsigned)*a > c - b) {
        flag = 1;
    }
    c = flag ? c : *a + b;
    *a = (int)c;
}