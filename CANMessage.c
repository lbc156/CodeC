#include <stdio.h>

/* Define a union to hold different variables/data for CAN message */ 
typedef struct{ 
    union { 
        struct __attribute__((__packed_))
        { 
            __uint8_t Signal1; 
            __uint16_t Signal2; 
            __uint8_t Signal3; 
            __uint8_t Signal4; 
            __uint8_t Signal5; 
            __uint8_t Signal6; 
            __uint8_t Signal7; 
            } signal; 
            __uint8_t rawData[8]; 
        }; 
    }CAN_Message; 
CAN_Message Message_0x100; 

int main() { 
    Message_0x100.signal.Signal1 = 0x00; 
    printf("Byte 0: %x\n",Message_0x100.signal.Signal1); 
    Message_0x100.signal.Signal2 = 0x0102; 
    printf("Byte 12: %x\n",Message_0x100.signal.Signal2); 
    Message_0x100.signal.Signal3 = 0x03; 
    printf("Byte 3: %x\n",Message_0x100.signal.Signal3); 
    Message_0x100.signal.Signal4 = 0x04; 
    printf("Byte 4: %x\n",Message_0x100.signal.Signal4); 
    Message_0x100.signal.Signal5 = 0x05; 
    printf("Byte 5: %x\n",Message_0x100.signal.Signal5); 
    Message_0x100.signal.Signal6 = 0x06; 
    printf("Byte 6: %x\n",Message_0x100.signal.Signal6); 
    Message_0x100.signal.Signal7 = 0x07; 
    printf("Byte 6: %x\n",Message_0x100.signal.Signal6); 
    printf("\n"); 
    printf("RawData:\n"); 
    for(int i=0;i<8;i++){ 
        printf("Byte %d: %x\t",i,Message_0x100.rawData[i]); 
    } 
    printf("\n"); 
    printf("Size of struct: %ld bytes\n", sizeof(Message_0x100)); 
    return 0; 
}