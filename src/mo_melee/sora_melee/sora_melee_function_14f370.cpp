#pragma force_active on
extern "C" {

int fn_27_14F370(void *ptr)
{
    unsigned int val = *(unsigned int *)((char *)ptr + 8);
    return (val >> 10) & 1;
}

}
