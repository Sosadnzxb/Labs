#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct bits {
    unsigned int num : 4; // 4-битное число
    unsigned int top_bits : 2; // 2 старших бита числа
};

// Example 7 - 0b0111
// Сдвиг на 2 бита вправо(>>)
// = 0b0001
//Побитовая операция И с маской 0x03 (это 0b0011 в бинарном виде)
//которая оставляет только два младших бита результата

int main() {
    struct bits b = { 0 };                                    // Инициализируем все поля структуры нулями
    unsigned int tmp;
    printf("Enter an unsigned int number: ");
    scanf("%u", &tmp);                                        // Ввод числа с клавиатуры
    b.num = tmp;                                              // Сохраняем значение в поле b.num
    b.top_bits = (b.num >> 2) & 0x03;                         // Получение двух старших бит              
    printf("The two highest bits of the number %u: %u\n", b.num, b.top_bits);   
    return 0;                                                                    
}


