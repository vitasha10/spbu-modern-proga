#include <cstdlib>
#include <iostream>

void generateSequence(int* const sequence, const int size);
void printSequence(const char* const label, const int* const sequence, const int size);
void printSequenceArithmeticMean(const char* const label, const int* const sequence, const int size);

int main() {
    const int size = 10;
    int sequences[3][size];
    const char* labels[3] = {
        u8"первой",
        u8"второй",
        u8"третьей"
    };

    for (int i = 0; i < 3; i++) {
        generateSequence(sequences[i], size);
        printSequence(labels[i], sequences[i], size);
        printSequenceArithmeticMean(labels[i], sequences[i], size);
    }

    return 0;
}

void generateSequence(int* const sequence, const int size) {
    for (int i = 0; i < size; i++) {
        sequence[i] = rand() % 10;
    }
}

void printSequence(const char* const label, const int* const sequence, const int size) {
    std::cout << u8"Элементы "
              << label
              << u8" последовательности:"
              << std::endl;
    const char* separator = " ";
    for (int i = 0; i < size; i++) {
        std::cout << sequence[i] << separator;
    }
    std::cout << std::endl;
}

void printSequenceArithmeticMean(const char* const label, const int* const sequence, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += sequence[i];
    }
    std::cout << u8"Среднее значение у "
              << label
              << u8" последовательности:"
              << " = "
              << sum / size
              << std::endl
              << std::endl;
}