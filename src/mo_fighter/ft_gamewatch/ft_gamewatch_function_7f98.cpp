#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void* fn_107_4554(void*, short);

void* fn_107_7F98(void* p, short s)
{
    if (p != 0) {
        fn_107_4554(p, (short)0);
        if (s > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

}
