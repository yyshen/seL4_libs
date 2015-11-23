/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <errno.h>
#include <stddef.h>
#include <vspace/vspace.h>
#include <sel4utils/stack.h>
#include <sel4utils/util.h>
#include <utils/stack.h>

int
sel4utils_run_on_stack(vspace_t *vspace, void * (*func)(void *arg), void *arg, void **retval)
{
    void *stack_top = vspace_new_stack(vspace);
    if (stack_top == NULL) {
        LOG_ERROR("Failed to allocate new stack\n");
        return -1;
    }

    void *ret = utils_run_on_stack(stack_top, func, arg);
    if (retval != NULL) {
        *retval = ret;
    }

    return 0;
}
