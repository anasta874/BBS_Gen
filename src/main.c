#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bbs.h"
#include "sequence.h"
#include "config.h"

void print_help() {
    printf("Usage: bbs <type (dna|rna|prot)> <count> [output prefix]\n");
    printf("Options:\n");
    printf("  --help        Show this help message and exit\n");
    printf("  --version     Show program version and exit\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No arguments provided.\n\n");
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "--version") == 0) {
        printf("BBSGen Version: %s\n", VERSION);
        return 0;
    }

    if (argc < 3) {
        fprintf(stderr, "Error: Missing required arguments.\n");
        print_help();
        return 1;
    }

    const char *type = argv[1];
    uint64_t count = strtoull(argv[2], NULL, 10);
    const char *output_prefix = (argc > 3) ? argv[3] : NULL;

    const char *alphabet = NULL;
    int alphabet_size = 0;

    if (strcmp(type, "dna") == 0) {
        alphabet = DNA_ALPHABET;
        alphabet_size = 4;
    } else if (strcmp(type, "rna") == 0) {
        alphabet = RNA_ALPHABET;
        alphabet_size = 4;
    } else if (strcmp(type, "prot") == 0) {
        alphabet = PROTEIN_ALPHABET;
        alphabet_size = 20;
    } else {
        fprintf(stderr, "Error: Unknown type '%s'.\n", type);
        return 1;
    }

    uint64_t seed = time(NULL);
    char *sequence = generate_sequence(alphabet, alphabet_size, count, seed, BBS_MODULUS);

    if (output_prefix) {
        char filename[256];
        snprintf(filename, sizeof(filename), "%s_%s.txt", output_prefix, type);
        save_to_file(filename, sequence);
        printf("Sequence saved to %s\n", filename);
    } else {
        printf("Generated Sequence: %s\n", sequence);
    }

    free(sequence);
    return 0;
}
