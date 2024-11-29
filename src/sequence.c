#include <stdio.h>
#include <stdlib.h>
#include "bbs.h"
#include "sequence.h"

char *generate_sequence(const char *alphabet, int alphabet_size, uint64_t count, uint64_t seed, uint64_t n) {
    uint64_t state = seed;
    char *sequence = (char *)malloc((count + 1) * sizeof(char));
    if (sequence == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint64_t i = 0; i < count; i++) {
        uint64_t random_value = bbs_next(&state, n);
        sequence[i] = alphabet[random_value % alphabet_size];
    }
    sequence[count] = '\0';
    return sequence;
}

void save_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s", data);
    fclose(file);
}
