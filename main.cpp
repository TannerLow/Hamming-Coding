#include <cstdio>
#include <bitset>
//#include <string>

using namespace std;

int main(){
	//get 11 bit message
	printf("Insert a number 0-2047: ");
	short input;
	scanf("%hd", &input);
	//Makes sure number is 11 bits and is not negative 
	if(input > 2047 or input < 0) {
		printf("Number not valid\n");
		return 0;
	}

	constexpr int SIZE = 16;
	constexpr int GIVE_ME_BITS = SIZE / 2 - 1

	bitset<SIZE> message(input & ((1 << GIVE_ME_BITS)-1));
	
	
	printf("Message: %s\n", message.to_string().c_str());

	short result = 0xf;
	for(short i = 0; i < 16; i++){
		if(message.test(i))
			result ^= i;
	}

	int i = 11;
	while(i < 16){
		message.set(i, result & 1);
		result >>= 1;
		i++;
	}

	printf("Message: %s\n", message.to_string().c_str());



	return 0;
}