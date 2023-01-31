#include <iostream>
#include <vector>
#include <ctime>

void generateNoise(std::vector<char> &noise, int length, int noiseDensity);
void filterNoise(std::vector<char> &noise, int length);
void printArray(std::vector<char> &noise, int length);

/**
 * @brief      Main function to run the program
*/
int main() {
    std::cout << "For this square output what should the length be?" << std::endl;
    int length;
    std::cin >> length;
    std::cout << "What is the noise density? (1 - 100)" << std::endl;
    int noiseDensity;
    std::cin >> noiseDensity;
    std::vector<char> noise;
    generateNoise(noise, length * length, noiseDensity);
    std::cout << "Here is the noise array:" << std::endl;
    printArray(noise, length);
    std::cout << std::endl;
    std::cout << "How many iterations should the filter run?" << std::endl;
    int iterations;
    std::cin >> iterations;
    std::cout << "And now the new biome array:" << std::endl;
    for (int i = 0; i < iterations; i++) {
        filterNoise(noise, length);
        std::cout << std::endl;
        std::cout << "iteration: " << i + 1 << std::endl;
        printArray(noise, length);
    } // for loop to run through iterations

    std::cout << std::endl;
    return 0;
} // main

/**
 * @brief      Filters the noise vector
 *
 * @param      noise  The noise vector
 * @param[in]  length The length of the noise vector
*/
void filterNoise(std::vector<char> &noise, int length) {
    std::vector<char> temp = noise; // temp vector to store new values
    int sum = 0;
    int mini_sum = 0;
    for (int i = 0; i < length * length; i++) {
        mini_sum = 0;
        for (int x = (i - length - 1); x <= (i + length + 1); x++) {
            try {
                if (noise.at(x) == '0' && mini_sum < 3 && x != i) {
                    sum++;
                } else if (x == (i - 2)) {
                    mini_sum = -1;
                } else if (x == (i + length - 2)) {               
                    mini_sum = -1;
                } // if 
                mini_sum++;
            } catch (std::out_of_range) {
                continue;
            } // try catch
        } // for loop to run through noise vector        
        if (sum > 4){
            temp.at(i) =  '0';
        } else {
            temp.at(i) = ' ';
        } // if 
        sum = 0; // reset sum
    } // for loop to run through noise vector
    noise = temp; // set noise to temp
} // filterNoise

/**
 * @brief      Generates the noise vector
 *
 * @param      noise         The noise vector
 * @param[in]  length        The length of the noise vector
 * @param[in]  noiseDensity  The noise density
*/
void generateNoise(std::vector<char> &noise, int length, int noiseDensity) {
    srand(time(0));
    int num;
    for (int i = 0; i < length; i++) {
        num = rand() % 100 + 1;
        if (num > noiseDensity) {
            noise.push_back(' ');
        } else {
            noise.push_back('0');
        } // if
    } // for loop to generate noise vector
} // generateNoise

/**
 * @brief      Prints the noise vector
 *
 * @param      noise  The noise vector
 * @param[in]  length The length of the noise vector
*/
void printArray(std::vector<char> &noise, int length) {
    for (int i = 0; i < length * length; i++) {
        std::cout << noise[i];
        if (i % length == 0) {
            std::cout << std::endl;
        } // if
    } // for loop to print noise vector
} // printArray
