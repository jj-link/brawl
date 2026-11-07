#pragma force_active on
extern "C" void* fn_100_8848();

extern "C" void* fn_100_8934(void* self, int state)
{
    switch (state)
    {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x494;
    case 2:
        return fn_100_8848();
    default:
        return fn_100_8848();
    }
}
