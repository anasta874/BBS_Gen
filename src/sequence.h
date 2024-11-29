#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdint.h>

char *generate_sequence(const char *alphabet, int alphabet_size, uint64_t count, uint64_t seed, uint64_t n);
void save_to_file(const char *filename, const char *data);

#endif // SEQUENCE_H
