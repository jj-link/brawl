#pragma force_active on
extern "C" void* fn_112_9448(void* p, int x);

extern "C" void* fn_112_9534(void* p, int x)
{
    switch (x) {
    case 0:
        return p;
    case 1:
        return (char*)p + 0x490;
    case 2:
        return fn_112_9448(p, x);
    default:
        return fn_112_9448(p, x);
    }
}
