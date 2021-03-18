#include <cstdint>

class LC3 {
    public:
        //constructor
        LC3();                          

        //data storage
        std::int16_t mem[INT16_MAX];    //LC3 Memory
        std::int16_t reg[13];           //REGFILE[0:7], PC[8], IR[9], Condition Codes: N[10], Z[11], P[12]
        
        //LC3 Methods
        std::int16_t ALU();
        std::int16_t addrADD;
        void updateCC();
        

        //non-LC3-specific methods
        //add functions that would not by regular instructions
        //Example:
        void matrixADD();
        


}