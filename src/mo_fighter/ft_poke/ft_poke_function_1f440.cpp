#pragma force_active on
extern "C" void* fn_116_9178(void*, int);
extern "C" void* fn_116_1F440(void* arg0, int arg1)
{
    switch (arg1) {
    case 0:
        return arg0;
    case 1:
        return (char*)arg0 + 0x478;
    case 2:
        return fn_116_9178(arg0, arg1);
    default:
        return fn_116_9178(arg0, arg1);
    }
}