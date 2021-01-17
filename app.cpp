/**
* gemaakt door: Michael Scholten
* datum: 17-1-2021
* beschrijving: Een bubble sort algoritme geschreven in c++ en MASM Assembly
*/

#include <iostream>
#include <ctime>

extern "C" void bsort8(uint8_t * arr, uint64_t size);
extern "C" void bsort16(uint16_t * arr, uint64_t size);

void cbsort(uint8_t* arr, uint64_t size){
	// de start index is 0
	uint64_t i = 0;
	// zolang i + 1 < size
	while (i + 1 < size) {
		// check of arr[i] < arr[i + 1] en wissel de waardes als dat het geval is.
		if (arr[i] > arr[i + 1]) {
			arr[i] += arr[i + 1];
			arr[i + 1] = arr[i] - arr[i + 1];
			arr[i] -= arr[i + 1];
			// als i > 0, moet i omlaag, anders kan het omhoog.
			if (i) i--;
			else i++;
		}// Als arr[i] <= arr[i + 1], moet i omhoog
		else i++;
	}
}

void cbsort(uint16_t* arr, uint64_t size) {
	// zelfde als de vorige functie, maar dan met een 16 bit pointer
	uint64_t i = 0;
	while (i + 1 < size) {
		if (arr[i] > arr[i + 1]) {
			arr[i] += arr[i + 1];
			arr[i + 1] = arr[i] - arr[i + 1];
			arr[i] -= arr[i + 1];
			if (i) i--;
			else i++;
		}
		else i++;
	}
}

// de grootte van de array
#define max 10000

int main() {
	// Bepaalt wat er op het scherm getoond wordt.
	char mode = 6;
	
	// Maak de array en vul het met de minst efficiënte data voor het gebruikte sorteer algoritme
	uint16_t* arr = (uint16_t*)malloc(max * 2);
	for (int i = 0; i < max; i++) {
		arr[i] = max - i;
	}

	// Start het meten van de tijd voor als dat later van belang is en sorteer de array met het algoritme in Assembly.
	clock_t start = clock();
	bsort16(arr, max);

	// Als het bit met waarde 1 gelijk is aan 1, zal de hele array op het scherm getoond worden.
	// Als het bit met waarde 2 gelijk is aan 1, zal de gemeten tijd op het scherm getoond worden.
	if(mode & 1) for (int i = 0; i < max; i++) printf("%d\n", arr[i]);
	if(mode & 2) std::cout << clock() - start << std::endl;

	// vul de array opnieuw met de startwaarde
	for (int i = 0; i < max; i++) {
		arr[i] = max - i;
	}
	// Start het meten van de tijd opnieuw voor als dat later van belang is en sorteer de array met het algoritme in c++
	start = clock();
	cbsort(arr, max);

	// Als het bit met waarde 4 gelijk is aan 1, zal de gehele array op het scherm getoond worden.
	// Als het bit met waarde 8 gelijk is aan 1, zal de gemeten tijd op het scherm getoond worden.
	if(mode & 4) std::cout << clock() - start << std::endl;
	if(mode & 8) for (int i = 0; i < max; i++) printf("%d\n", arr[i]);
}