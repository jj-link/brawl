#pragma force_active on
typedef struct DestructorChain
{
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern DestructorChain *__global_destructor_chain;

void __destroy_global_chain(void)
{
    DestructorChain *dc;

    while ((dc = __global_destructor_chain) != 0)
    {
        __global_destructor_chain = dc->next;
        ((void (*)())dc->destructor)(dc->object, -1);
    }
}
