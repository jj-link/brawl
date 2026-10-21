#pragma force_active on
typedef struct DestructorChain
{
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern DestructorChain *__global_destructor_chain;

void __register_global_object(void *object, void *destructor, DestructorChain *chain)
{
    chain->next = __global_destructor_chain;
    chain->destructor = destructor;
    chain->object = object;
    __global_destructor_chain = chain;
}
