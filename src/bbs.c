#include "bbs.h"

uint64_t bbs_next(uint64_t *state, uint64_t n) {
    *state = (*state * *state) % n;
    return *state;
}